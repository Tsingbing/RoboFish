#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_timerId(0),
	m_steps(0),
	m_realTime(0.0)
	, m_axis(0)
	, m_axisX(0)
	, m_axisY(0)
	, m_axisR(0)
	, m_axisU(0)
	, m_b(0)
	, m_led(0)
	, m_pantile(50)
	, m_axisValue(0)
	, m_button(0)
	, m_buttonPressed(0)
	, m_button_ZoomIn(0)	
	, m_button_ZoomOut(0)
{
    ui->setupUi(this);
    m_timerId  = startTimer( 0 );
    m_time.start();	
	m_udp = new UdpMaster();
	//m_udp 依赖注入
	dialog = new Dialog(m_udp, this);
	//m_map = new mapWidget();
	QString path = QDir::currentPath();
	ui->axWidget->dynamicCall("LoadMovie(int,QString)", 0, path + "/API/FlashGIS.swf");
	ui->axWidget->dynamicCall("");
	connect(ui->axWidget, SIGNAL(FlashCall(QString)), this, SLOT(acceptFlashData(QString)));

	setupUiStatusBar();
	setupUiAction();

	QJoystick *joystick;
	for (int i = 0; i < 10; i++)
	{
		joystick = new QJoystick(i, this);
		if (joystick->isValid())
		{
			connect(joystick, SIGNAL(JoystickAxisEvent(QJoystickAxisEvent*)), this, SLOT(handleQJoystickAxisEvent(QJoystickAxisEvent*)));
			connect(joystick, SIGNAL(JoystickButtonEvent(QJoystickButtonEvent*)), this, SLOT(handleQJoystickButtonEvent(QJoystickButtonEvent*)));

			QTimer *timer = new QTimer(this);
			timer->setInterval(15);
			connect(timer, SIGNAL(timeout()), joystick, SLOT(readJoystick()));
			timer->start();
		}
		else
		{
			qDebug() << "joystick not found" << endl;
			delete joystick;
		}
	}
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << "Average time step: " << ( (double)m_realTime ) / ( (double)m_steps ) << " s" << endl;
    if ( m_timerId ) killTimer( m_timerId );
	delete m_udp;
}

void MainWindow::setupUiAction()
{
	connect(ui->actionhelp, SIGNAL(triggered()), this, SLOT(openDialog()));
	//connect(ui->actionsetCenter, SIGNAL(triggered()), m_map, SLOT(on_gotoQrigin_Btn_clicked()));
	connect(ui->actionswitch, SIGNAL(triggered()), this, SLOT(on_switchButton_clicked()));
	connect(ui->actionstartRuler, SIGNAL(triggered()), this, SLOT(startRuler()));
	connect(ui->actionclearRuler, SIGNAL(triggered()), this, SLOT(clearRuler()));
	connect(ui->actioninit, SIGNAL(triggered()), this, SLOT(initMap()));
	//connect(ui->actionsetCenter, SIGNAL(triggered()), this, SLOT(initMap()));

}

void MainWindow::setupUiStatusBar()
{
	first_statusLabel = new QLabel();
	first_statusLabel->setMinimumSize(70, 20);
	axisX_statusLabel = new QLabel();
	axisX_statusLabel->setMinimumSize(70, 20);
	axisY_statusLabel = new QLabel();
	axisY_statusLabel->setMinimumSize(70, 20);
	axisR_statusLabel = new QLabel();
	axisR_statusLabel->setMinimumSize(70, 20);
	axisU_statusLabel = new QLabel();
	axisU_statusLabel->setMinimumSize(70, 20);
	pushWay_statusLabel = new QLabel();
	pushWay_statusLabel->setMinimumSize(70, 20);
	directial_statusLabel = new QLabel();
	directial_statusLabel->setMinimumSize(70, 20);
	depthkeeping_statusLabel = new QLabel();
	depthkeeping_statusLabel->setMinimumSize(70, 20);
	switch_statusLabel = new QLabel();
	switch_statusLabel->setMinimumSize(70, 20);
	zoom_statusLabel = new QLabel();
	zoom_statusLabel->setMinimumSize(70, 20);

	ui->statusBar->addWidget(first_statusLabel);
	ui->statusBar->addWidget(axisX_statusLabel);
	ui->statusBar->addWidget(axisY_statusLabel);
	ui->statusBar->addWidget(axisR_statusLabel);
	ui->statusBar->addWidget(axisU_statusLabel);
	ui->statusBar->addWidget(pushWay_statusLabel);
	ui->statusBar->addWidget(directial_statusLabel);
	ui->statusBar->addWidget(depthkeeping_statusLabel);
	ui->statusBar->addWidget(switch_statusLabel);
	ui->statusBar->addWidget(zoom_statusLabel);
}

void MainWindow::setCenter(float lon, float lat)
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

void MainWindow::initMap()
{
	QString myMap("locationMap");
	addLayer(myMap);
	QDir myDir;
	//QString path = myDir.currentPath() + "/resource/罗盘/箭头.png";
	QString path = "E:/01_RobotSea/01_Pro/08_RoboFish/RoboFish/images/pin.png";
	QString type("img");
	//addImage(myMap, 4, type, path, 25, 50, 140.49, 31.228, 90);
	addPoint(2, "point", 122, 43, "circle", 5, 0xff0000);
	
	//qDebug() << "--------";
}

bool f = true;
void MainWindow::on_switchButton_clicked()
{
	if (!f)
	{
		ui->axWidget->setGeometry(20 * width() / 1366, 54 * height() / 768, 910 * width() / 1366, 576 * height() / 768);
		ui->widgetVideo->setGeometry(960 * width() / 1366, 54 * height() / 768, 383 * width() / 1366, 231 * height() / 768);
	}
	else
	{
		ui->widgetVideo->setGeometry(20 * width() / 1366, 54 * height() / 768, 910 * width() / 1366, 576 * height() / 768);
		ui->axWidget->setGeometry(960 * width() / 1366, 54 * height() / 768, 383 * width() / 1366, 231 * height() / 768);
	}
	f ^= true;
}

void MainWindow::handleQJoystickAxisEvent(QJoystickAxisEvent * event)
{
	qDebug() << event->axis() << ":" << event->value() * 100 << endl;
	m_axis = event->axis();
	m_axisValue = event->value() * 100;
	
	//左转右转
	if (event->axis() == 0){
		m_axisY = event->value() * -100;
	}
	//前进后退
	if (event->axis() == 1){
		m_axisX = event->value() * 100;
	}
	//上浮下潜
	if (event->axis() == 2){
		m_axisU = event->value() * 100;
	}
	//
	if (event->axis() == 3) {
		m_axisR = event->value() * 100;
	}
	// 灯光
	if (event->axis() == 5)
	{
		if (event->value()*100 == 100)
		{
			m_led = m_led + 20;
			if (m_led > 100)
				m_led = 100;
		}
		if (event->value()*100 == -100)
		{
			m_led = m_led - 20;
			if (m_led < 0)
				m_led = 0;
		}
		//emit dialog->sendLight(m_led);
		m_udp->sendLightCommandToUdp(m_led);
	}
	// 云台
	if (event->axis() == 6)
	{
		if (event->value() * 100 == 100)
		{
			m_pantile = m_pantile + 5;
			if (m_pantile > 100)
				m_pantile = 100;
		}
		if (event->value() * 100 == -100)
		{
			m_pantile = m_pantile - 5;
			if (m_pantile < 0)
				m_pantile = 0;
		}
		//dialog->sendPantile(m_pantile);
		m_udp->sendPanTileCommandToUdp(m_pantile);
	}
	if (event->axis() == 0 || event->axis() == 1 || event->axis() == 2 || event->axis() == 3)
	{
		//emit dialog->sendTest(m_axisX, m_axisY, m_axisR, m_axisU, m_b);
		m_udp->sendMoveCommandToUDP(m_axisX, m_axisY, m_axisR, m_axisU, m_b);
	}

	//emit dialog->sendl
	axisX_statusLabel->setText("左右:" + QString::number(m_axisX));
	axisY_statusLabel->setText("前后:" + QString::number(m_axisY));
	axisU_statusLabel->setText("上下:" + QString::number(m_axisU));
	axisR_statusLabel->setText("axisR:" + QString::number(m_axisR));
	//statusBar()->showMessage(QString::number(event->value() * 100), 3000);//3s后关闭
}
bool a = true; bool b = true; bool c = true; bool d = true;
void MainWindow::handleQJoystickButtonEvent(QJoystickButtonEvent * event)
{
	//m_b = 0;
	qDebug() << event->button() << ":" << event->pressed() << endl;
	m_button = event->button();
	m_buttonPressed = event->pressed();
	
	//A 推进方式
	if (event->button() == 0 && event->pressed()) {
		/*m_button_A = event->pressed();
		if (m_button_A){*/
		if (a)
		{
			pushWay_statusLabel->setText("尾巴");
			m_b = m_b + 4;
		}
		else
		{
			pushWay_statusLabel->setText("螺旋桨");
			m_b = m_b - 4;
		}
			
			a ^= true;
		//}
	}
	//B
	if (event->button() == 1 && event->pressed()) {
		m_button_B = event->pressed();
		if (b) {
			directial_statusLabel->setText("定航");
			m_b = m_b + 2;
		}	
		else {
			directial_statusLabel->setText("");
			m_b = m_b - 2;
		}
			
		b ^= true;
	}
	//X
	if (event->button() == 2 && event->pressed()) {
		m_button_X = event->pressed();
		if (c) {
			depthkeeping_statusLabel->setText("定深");
			m_b += 1;
		}			
		else {
			depthkeeping_statusLabel->setText("");
			m_b -= 1;
		}
			
		c ^= true;
	}
	//Y
	if (event->button() == 3 && event->pressed()) {
		//if (d) {
			switch_statusLabel->setText("切换");
			m_button_Y = event->pressed();
			on_switchButton_clicked();
		//}			
		//else
		//	switch_statusLabel->setText("");
		//d ^= true;
	}
	//放大
	if (event->button() == 4 && event->pressed()) {
		m_button_ZoomOut = event->pressed();
		zoom_statusLabel->setText("放大");
		ui->widgetVideo->zoomOut();
	}
	//缩小
	if (event->button() == 5 && event->pressed()) {
		m_button_ZoomIn = event->pressed();
		zoom_statusLabel->setText("缩小");
		ui->widgetVideo->zoomIn();
	}
	m_udp->sendMoveCommandToUDP(m_axisX, m_axisY, m_axisR, m_axisU, m_b);
}

void MainWindow::addPoint(quint8 id, QString type, float lon, float lat, QString pointType, int size, int color)
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

void MainWindow::addImage(QString layer, quint8 Id, QString type, QString path, quint8 width, quint8 height, float lon, float lat, int angle)
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

void MainWindow::addLayer(QString layer)
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

void MainWindow::clearRuler()
{
	QString argu;
	argu.append("<param>");
	argu.append("<layer_name>locationMap</layer_name>");
	argu.append("<open>0</open>");
	argu.append("</param>");
	ui->axWidget->dynamicCall("CallFunction(string)", "<invoke name=\"open_ruler\" returntype=\"xml\">"
		"<arguments><string>" + argu + "</string></arguments></invoke>");
}

void MainWindow::startRuler()
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

void MainWindow::acceptFlashData(QString str)
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

void MainWindow::addLabel(QString layer)
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

void MainWindow::openDialog()
{
    dialog->show();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->axWidget->setGeometry(20*width()/1366, 54*height()/768, 910*width()/1366, 576*height()/768);
    ui->widgetPFD->setGeometry(970*width()/1366, 320*height()/768, 371*width()/1366, 311*height()/768);
	ui->widgetVideo->setGeometry(960 * width() / 1366, 54 * height() / 768, 383 * width() / 1366, 231 * height() / 768);
}

void MainWindow::timerEvent( QTimerEvent *event )
{
    /////////////////////////////////
    QMainWindow::timerEvent( event );
    /////////////////////////////////

	//addPoint(2, "point", 116, 43, "circle", 5, 0xff0000);

	//传感器数据接收
	ui->temperature->setText("温度:"+QString::number(m_udp->m_temperature));
	ui->humidity->setText("湿度:"+QString::number(m_udp->m_humidity));
	ui->heading->setText("航向:"+QString::number(m_udp->m_heading));
	ui->roll->setText("旋转角:"+QString::number(m_udp->m_roll));
	ui->pitch->setText("翻滚角:"+QString::number(m_udp->m_pitch));
	ui->pressure->setText("深度:"+QString::number(m_udp->m_pressure));
	ui->current->setText("电流:"+QString::number(m_udp->m_current));
	ui->voltage->setText("电压:"+QString::number(m_udp->m_voltage));
	ui->led->setText("亮度:" + QString::number(m_led));
	ui->pantile->setText("云台:" + QString::number(m_pantile));
	ui->lg->setText("经度:" + QString::number(m_udp->m_longitude));
	ui->la->setText("纬度:" + QString::number(m_udp->m_latitude));
	//

    float timeStep = m_time.restart();
    m_realTime = m_realTime + timeStep / 1000.0f;
	//qDebug() << m_realTime;
    float alpha     =  0.0f;
    float beta      =  0.0f;
    float roll      =  0.0f;
    float pitch     =  0.0f;
    float heading   =  0.0f;
    float slipSkid  =  0.0f;
    float turnRate  =  0.0f;
    float devH      =  0.0f;
    float devV      =  0.0f;
    float airspeed  =  0.0f;
    float altitude  =  0.0f;
    float pressure  = 28.0f;
    float climbRate =  0.0f;
    float machNo    =  0.0f;
    float adf       =  0.0f;
    float dme       =  0.0f;

  /*  alpha     =   20.0f * sin( m_realTime /  10.0f );
    beta      =   15.0f * sin( m_realTime /  10.0f );
    roll      =  180.0f * sin( m_realTime /  10.0f );
    pitch     =   90.0f * sin( m_realTime /  20.0f );
    heading   =  360.0f * sin( m_realTime /  40.0f );*/
  /*  slipSkid  =    1.0f * sin( m_realTime /  10.0f );
    turnRate  =    7.0f * sin( m_realTime /  10.0f );
    devH      =    1.0f * sin( m_realTime /  20.0f );
    devV      =    1.0f * sin( m_realTime /  20.0f );
    airspeed  =  125.0f * sin( m_realTime /  40.0f ) +  125.0f;
    altitude  = 100.0f * sin( m_realTime /  40.0f ) + 100.0f;
    pressure  =    2.0f * sin( m_realTime /  20.0f ) +   30.0f;
    climbRate =  650.0f * sin( m_realTime /  20.0f );*/
    //machNo    = airspeed / 650.0f;
    //adf       = -360.0f * sin( m_realTime /  50.0f );
    //dme       =   99.0f * sin( m_realTime / 100.0f );


    ui->widgetPFD->setFlightPathMarker ( alpha, beta );
    //ui->widgetPFD->setRoll          ( roll     );
	ui->widgetPFD->setRoll(m_udp->m_roll);
    //ui->widgetPFD->setPitch         ( pitch     );
	ui->widgetPFD->setPitch(m_udp->m_pitch);
    ui->widgetPFD->setSlipSkid      ( slipSkid  );
    ui->widgetPFD->setTurnRate      ( turnRate / 6.0f );
    ui->widgetPFD->setDevH          ( devH      );
    ui->widgetPFD->setDevV          ( devV      );
    ui->widgetPFD->setHeading       ( heading   );
	ui->widgetPFD->setHeading(m_udp->m_heading);
    //ui->widgetPFD->setAirspeed      ( airspeed  );
    ui->widgetPFD->setMachNo        ( machNo    );
    ui->widgetPFD->setAltitude      ( altitude  );
    ui->widgetPFD->setPressure      ( pressure  );
    ui->widgetPFD->setClimbRate     ( climbRate / 100.0f );

    ui->widgetPFD->update();

    m_steps++;
}
