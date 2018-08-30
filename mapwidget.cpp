#include "mapwidget.h"
#include "ui_mapwidget.h"
#include <QDir>
#include <ActiveQt/QAxWidget>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
mapWidget::mapWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::mapWidget)
{
	ui->setupUi(this);

	QString path = QDir::currentPath();
	//ui->axWidget->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
	ui->axWidget->dynamicCall("LoadMovie(int,QString)", 0, path + "/API/FlashGIS.swf");
	ui->axWidget->dynamicCall("");
	connect(ui->axWidget, SIGNAL(FlashCall(QString)), this, SLOT(acceptFlashData(QString)));
}

mapWidget::~mapWidget()
{
	delete ui;
}
void mapWidget::initMap()
{
	QString myMap("locationMap");
	addLayer(myMap);
	QDir myDir;
	//QString path = myDir.currentPath() + "/resource/罗盘/箭头.png";
	QString path = "E:/01_RobotSea/01_Pro/08_RoboFish/RoboFish/images/pin.png";
	QString type("img");
	addImage(myMap, 4, type, path, 25, 50, 140.49, 31.228, 90);
	addPoint(2, "point", 122, 43, "circle", 5, 0xff0000);
	qDebug() << "--------";
}
void mapWidget::on_gotoQrigin_Btn_clicked()
{
	 initMap();  
	 //setImagePosition(100, 30);
	 //setCenter(100, 30);
}

void mapWidget::on_showTrack_Btn_clicked()
{
	 setCenter(longitude,latitude);
}

void mapWidget::receiveLocation(float longitude, float latitude, float heading)
{
	setImagePosition(longitude, latitude);
	setImageRotation(heading);
}
//****************地图设置函数****************/
void mapWidget::setCenter(float lon, float lat)
{
	QString argu;
	argu.append("<param>");
	argu.append(QString("<lon>%1</lon>").arg(lon));
	argu.append(QString("<lat>%1</lat>").arg(lat));
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", 
		"<invoke name=\"set_map_center\" returntype=\"xml\">"
		"<arguments><string>"
		+ argu + 
		"</string></arguments></invoke>");
}
//开始路径规划
void mapWidget::startRuler()
{
	isPlanning = true;
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append("<open>1</open>");
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"open_ruler\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}

void mapWidget::acceptFlashData(QString str)
{
	QPointF tempPoint;
	QString latitude;
	QString longitude;
	QString tempData;
	int ret = 0;
	QString fileName = QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".txt";
	QDir myDir;
	myDir.mkdir("logDir");
	QString filePath = QDir::currentPath() + "/logDir/";
	QFile logFile(filePath + fileName);
	qDebug() << str;
	if (isPlanning)
	{
		if (!logFile.open(QIODevice::Append | QIODevice::Text))
		{
			QMessageBox::warning(NULL, "WARNING", "文件打开失败", QMessageBox::Retry);
			return;
		}
		QTextStream out(&logFile);

		while (-1 != ret)
		{
			ret = str.indexOf(separate);
			tempData = str.mid(ret + 11, 24);
			QStringList list = tempData.split(",");
			longitude = list[0];
			latitude = list[1];

			tempPoint.setX(longitude.remove(longitude.length() - 3, 3).toDouble());
			tempPoint.setY(latitude.remove(latitude.length() - 3, 3).toDouble());
			//保存日志文件
			out << longitude << "," << latitude << "," << tempPoint.x() << "," << tempPoint.y() << "\n";

			if (tempPoint.x() == 0 || tempPoint.y() == 0)
			{
				QMessageBox::warning(NULL, "WARNING", "路径规划失败请重试", QMessageBox::Retry);
				clearRuler();
				//                ui->openRuler_Btn->setText("开始规划");
				//                on_openRuler_Btn_clicked();
				logPoints.clear();
				return;
			}
			logPoints.append(tempPoint);
			str = str.mid(ret + 1);
		}
		logFile.close();
		isPlanning = false;
		//        ui->openRuler_Btn->setText("开始规划");
		logPoints.removeLast();
		//发送点数据并保存
		//emit sendPointsData(logPoints, 1, 1, 1, 1);
		//        logPoints.clear();
	}

}
//停止路径规划
void mapWidget::clearRuler()
{

	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append("<open>0</open>");
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"open_ruler\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}

void mapWidget::addLabel(QString text)
{
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append("<bus_id>5</bus_id>");         //业务ID
	argu.append("<bus_type>label</bus_type>");   //业务类型
	argu.append(QString("<text>%1</text>").arg(text));
	argu.append(QString("<lonlat>%1,%2</lonlat>").arg(100).arg(30));
	argu.append("<placement>square</placement>");
	argu.append("<color>16711680</color>");
	argu.append("<size>12</size>");
	argu.append("<xoff>0</xoff>");
	argu.append("<yoff>0</yoff>");
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"add_lable\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}
void mapWidget::addPoint(quint8 id, QString type, float lon, float lat, QString pointType, int size, int color)
{
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append(QString("<bus_id>%1</bus_id>").arg(id));         //业务ID
	argu.append(QString("<bus_type>%1</bus_type>").arg(type));   //业务类型
	argu.append(QString("<lonlat>%1,%2</lonlat>").arg(lon).arg(lat));
	argu.append(QString("<type>%1</type>").arg(pointType));
	argu.append(QString("<size>%1</size>").arg(size));
	argu.append(QString("<color>%1</color>").arg(color));
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"add_point\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}
void mapWidget::delObject(quint8 id, QString type)
{
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append(QString("<bus_id>%1</bus_id>").arg(id));
	argu.append(QString("<bus_type>%1</bus_type>").arg(type));
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"del_objects\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}

//添加图层
void mapWidget::addLayer(QString layer)
{
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append("<layer_visible>1</layer_visible>");
	argu.append("<min_level>2</min_level>");
	argu.append("<max_level>18</max_level>");
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"add_layer\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}
//删除图层
void mapWidget::deleteLayer(QString layer)
{
	QString argu;
	argu.append("<param>");
	argu.append(QString("<layer_name>%1</layer_name>").arg(layer));
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"clear_layer\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}
void mapWidget::addImage(QString layer, quint8 Id, QString type, QString path, quint8 width, quint8 height, float lon, float lat, int angle)
{

	QString argu;
	argu.append("<param>");
	argu.append(QString("<layer_name>%1</layer_name>").arg("locationMap"));
	argu.append(QString("<bus_id>%1</bus_id>").arg(Id));
	argu.append(QString("<bus_type>%1</bus_type>").arg(type));
	argu.append(QString("<url>%1</url>").arg(path));
	argu.append(QString("<width>%1</width>").arg(width));
	argu.append(QString("<height>%1</height>").arg(height));
	argu.append(QString("<lonlat>%1,%2</lonlat>").arg(lon).arg(lat));
	argu.append(QString("<rotation>%1</rotation>").arg(angle));
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"add_image\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}
void mapWidget::setImageRotation(int angle)
{
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append("<bus_id>4</bus_id>");
	argu.append("<bus_type>img</bus_type>");
	argu.append(QString("<rotation>%1</rotation>").arg(angle));
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"set_image_rotation\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}
void mapWidget::setImagePosition(float lon, float lat)
{
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append("<bus_id>4</bus_id>");
	argu.append("<bus_type>img</bus_type>");
	argu.append(QString("<lonlat>%1,%2</lonlat>").arg(lon).arg(lat));
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"set_image_position\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}
