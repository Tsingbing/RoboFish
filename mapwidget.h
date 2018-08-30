#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>

namespace Ui {
	class mapWidget;
}

class mapWidget : public QWidget
{
	Q_OBJECT

public:
	explicit mapWidget(QWidget *parent = 0);
	~mapWidget();

	void addLayer(QString);//*
	void deleteLayer(QString layer);//*
	void addPoint(quint8 id, QString type, float lon, float lat, QString pointType, int size, int color);//*
	void delObject(quint8 id, QString type);//*
	void setImageRotation(int angle);
	void setImagePosition(float, float);
	void addImage(QString layer, quint8 Id, QString type, QString path, quint8 width, quint8 height, float lon, float lat, int angle);
	void clearLayer(QString);// *
	void addLabel(QString); // *
	void setPointColor(quint8 id, QString type, int color);
	void setCenter(float, float);//设置地图中心 *

private slots:
	void on_gotoQrigin_Btn_clicked();
	void on_showTrack_Btn_clicked();
	void clearRuler();//*
	void startRuler();//路径规划 *
	void acceptFlashData(QString str);

public slots:
	void receiveLocation(float, float, float);

private:
	void initMap();
private:
	Ui::mapWidget *ui;
	bool isPlanning = false;
	QString separate = ";string&gt;";
	QList <QPointF> logPoints;

	float longitude;
	float latitude;
};

#endif // MAPWIDGET_H
