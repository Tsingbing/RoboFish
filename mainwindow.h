#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <QTime>
#include "udpmaster.hpp"
#include "qjoystick.h"
#include <QLabel>
#include "mapwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	void setupUiAction();
	void setupUiStatusBar();
	void setCenter(float, float);//设置地图中心 *

protected:
    void timerEvent( QTimerEvent *event );
	void resizeEvent(QResizeEvent *event);

public slots:
	void initMap();
	void openDialog();
	void on_switchButton_clicked();
	void handleQJoystickAxisEvent(QJoystickAxisEvent *event);
	void handleQJoystickButtonEvent(QJoystickButtonEvent *event);

	void addPoint(quint8 id, QString type, float lon, float lat, QString pointType, int size, int color);//*
	void addImage(QString layer, quint8 Id, QString type, QString path, quint8 width, quint8 height, float lon, float lat, int angle);
	void addLayer(QString);//*
	void clearRuler();//*
	void startRuler();//路径规划 *
	void acceptFlashData(QString str);
	void addLabel(QString); // *
	//void reciveSensorData(float t, float hu, float he, float r, float p, float , float, float);

private:
    Ui::MainWindow *ui;
	
    Dialog *dialog;
	UdpMaster *m_udp;
	mapWidget *m_map;
	QLabel *first_statusLabel;
	QLabel *axisX_statusLabel;
	QLabel *axisY_statusLabel;
	QLabel *axisR_statusLabel;
	QLabel *axisU_statusLabel;
	QLabel *pushWay_statusLabel;
	QLabel *directial_statusLabel;
	QLabel *depthkeeping_statusLabel;
	QLabel *switch_statusLabel;
	QLabel *zoom_statusLabel;

    int m_timerId;
    int m_steps;
    float m_realTime;
    QTime m_time;

	//joystick 属性/////
	bool m_running;
	float m_axisX;
	float m_axisY;
	float m_axisR;
	float m_axisU;
	float m_b; // 模式选择
	int m_led;
	int m_pantile;
	bool m_button_A;
	bool m_button_B;
	bool m_button_X;
	bool m_button_Y;
	bool m_button_ZoomOut;
	bool m_button_ZoomIn;

	//=====
	int m_axis;
	float m_axisValue;
	int m_button;
	bool m_buttonPressed;

	//mapAxWidget
	bool isPlanning = false;
	QString separate = ";string&gt;";
	QList <QPointF> logPoints;

	// 数据显示
	float m_longitude;
	float m_latitude;
};

#endif // MAINWINDOW_H
