#pragma once
#include <QObject>
#include <QUdpSocket>

class UdpMaster : public QObject {
	Q_OBJECT

public:
	UdpMaster(QObject * parent = Q_NULLPTR);
	~UdpMaster();

	//电压均值滤波
	float getVoltage(float v);
	QList<float> averageVoltage;

signals:
	void sendReciveData(QString);
	void sendSendData(QString);
	void sendSensorData(float, float, float, float, float, float,float);

public slots:
	void receiveMessageFromSlave();
	void sendLightCommandToUdp(qint8 light); //灯光强度
	void sendPanTileCommandToUdp(qint8 panTilt); //云台	
	void sendZoomOut();
	//void sendZoomIn();
	void sendMoveCommandToUDP(float axisX, float axisY, float axisR, float axisU, qint8 b);//左移右移，前进后退，左转右转，上浮下潜， 定深定向
	void sendSetMotorParameters(qint8 LF, qint8 LB, qint8 RF, qint8 RB);
	void sendSetPIDParameters(qint8 mode, float P, float I, float D);
	void sendMachineHand(qint8 qi);//设置机械手抓海参
	void sendGPS(float longit, float latit);

private:
	QString m_dataStateAck;
	QString m_localIP;
	QString m_remoteIP;
	QUdpSocket *m_UdpSocket;

public:
	float m_temperature;
	float m_humidity;
	float m_pressure;
	float m_heading;
	float m_roll;
	float m_pitch;
	float m_current;
	float m_voltage;
	int m_num_of_satellite;
	float m_longitude;
	float m_latitude;
	float m_coordinate[2];
};
