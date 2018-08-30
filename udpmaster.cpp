#include "udpmaster.hpp"

UdpMaster::UdpMaster(QObject * parent) : QObject(parent)
	, m_dataStateAck("")
	, m_localIP("192.168.1.15")
	, m_remoteIP("192.168.1.10")
	, m_temperature(0)
	, m_pressure(0)
	, m_humidity(0)
	, m_heading(0)
	, m_roll(0)
	, m_pitch(0)
	, m_current(0)
	, m_voltage(0)
	, m_latitude(0)
	, m_longitude(0)
	, m_num_of_satellite(0)
	, m_coordinate{0,0}

{
	m_UdpSocket = new QUdpSocket;
	//m_UdpSocket->bind(QHostAddress("192.168.1.15"), 8000);
	m_UdpSocket->bind(QHostAddress(m_localIP), 8000);
	connect(m_UdpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessageFromSlave()));
}

UdpMaster::~UdpMaster() {
	
}

float UdpMaster::getVoltage(float v)
{
	averageVoltage.append(v);
	float sum = 0;
	float average = 0;
	if (averageVoltage.count() == 200)
	{
		for (int i = 0; i < averageVoltage.count(); i++)
		{
			sum += averageVoltage[i];
		}
		average = sum / 200;
		averageVoltage.removeFirst();
	}
	return average;
}


void UdpMaster::receiveMessageFromSlave()
{
	//qDebug() << "===========" << endl;
	
	//QJsonObject jsonObj;
	char *ch = NULL;
	QByteArray myBuff;
	
	struct PowerMsg
	{
		float current;
		float voltage;
	}power;
	struct PressureMsg
	{
		int Temperature;
		int Pressure;
		int init_value;
		float depth;
	}pressure;
	struct Compass
	{
		float heading;
		float roll;
		float pitch;
	}compass_st;
	struct TempHumiMsg_st
	{
		float temp;
		float humi;
	}tempHumi;

	struct GPS_st
	{
		int num_of_satellite;  //卫星数，小于4个卫星，经纬度值不可取，一般不会用到。
		float longitude; //经度
		float latitude; //纬度
		float coordinate[2]; //经过某种变换，得到的坐标值
	}gps;

	while (m_UdpSocket->hasPendingDatagrams())
	{
		QByteArray receiveData;
		receiveData.resize(m_UdpSocket->pendingDatagramSize());

		m_UdpSocket->readDatagram(receiveData.data(), receiveData.size());

		myBuff.append(receiveData);

		ch = myBuff.data();
		emit sendReciveData(QString(myBuff.toHex(':')));
		//按字节进行判断
		if (myBuff[0] != (char)0xfe)
		{
			myBuff.remove(0, 1);

			if (myBuff.isEmpty())
				return;
		}
		else
		{
			if (myBuff.length() >= myBuff[1])
			{
				if (myBuff[myBuff[1] - 1] == (char)0x0a)
				{
					char commd = myBuff[3];

					switch (commd)
					{
					case 0x00:
						memcpy(&tempHumi, ch + 4, 8);
						//jsonObj["temperature"] = tempHumi.temp;
						//temper_send = tempHumi.temp;
						//jsonObj["humidity"] = tempHumi.humi;
						//setTemperature(tempHumi.humi);
						//setHumidity(tempHumi.humi);
						//humidity_send = tempHumi.humi;
						m_temperature = tempHumi.temp;
						m_humidity = tempHumi.humi;
						break;
					case 0x01:
						memcpy(&pressure, ch + 4, sizeof(pressure));
						//jsonObj["pressure"] = pressure.p;
						//setPressure(pressure.p);
						//pressure_send = pressure.p;
						m_pressure = pressure.depth;
						break;
					case 0x02:
						memcpy(&compass_st, ch + 4, 12);
						//jsonObj["heading"] = compass_st.heading;
						//jsonObj["roll"] = compass_st.roll;
						//jsonObj["pitch"] = compass_st.pitch;
						//setHeading(compass_st.heading);
						//setRoll(compass_st.roll);
						//setPitch(compass_st.pitch);
						/*heading_send = compass_st.heading;
						roll_send = compass_st.roll;
						pitch_send = compass_st.pitch;*/
						m_heading = compass_st.heading;
						m_roll = compass_st.roll;
						m_pitch = compass_st.pitch;
						break;
					case 0x03:
						memcpy(&power, ch + 4, 8);
						//jsonObj["current"] = power.current;
						//jsonObj["voltage"] = power.voltage;
						//setCurrent(power.current);
						//电压滤波
						float tempV;
						if (getVoltage(power.voltage) == 0)
						{
							tempV = power.voltage;
						}
						else
						{
							tempV = getVoltage(power.voltage);
						}
						//setVoltage(tempV);
						m_voltage = tempV;
						//========
						/*current_send = power.current;
						voltage_send = power.current;*/
						break;
					case 0x20://GPS坐标
						memcpy(&gps, ch + 4, sizeof(gps));
						m_num_of_satellite = gps.num_of_satellite;
						m_longitude = gps.longitude;
						m_latitude = gps.latitude;
						m_coordinate[0] = gps.coordinate[0];
						m_coordinate[1] = gps.coordinate[1];
						break;
					case 0x08:
						//mySleep(3000); 延时3s
						//QMessageBox::warning(NULL,"WARING","设备开启失败，请重启",QMessageBox::Retry);
						//QMessageBox::warning(NULL, "WARING", "If the device is unsuccessful, please restart", QMessageBox::Retry);
						break;						
					
					default:
						break;
					}
					//qDebug() << jsonObj << endl;
					//QJsonDocument doc(jsonObj);
					//QString strJson(doc.toJson(QJsonDocument::Compact));
					//m_dataStateAck = strJson;
					//setDataStateAck(m_dataStateAck);
					/*emit sendSensorData(m_temperature, 
						m_humidity, 
						m_heading, 
						m_roll, 
						m_pitch,
						m_current,
						m_voltage);*/
					myBuff.remove(0, myBuff[1]);
				}
				else
				{
					myBuff.remove(0, 1);
				}
			}
			else
			{
				return;
			}
		}
	}
}

//void UdpMasterItem::sendSensorsDataToUIFlush()
//{
//}

void UdpMaster::sendLightCommandToUdp(qint8 light)
{
	QByteArray desData;
	
	desData.clear();
	desData[0] = 0xfe;
	desData[1] = 0x08;
	desData[2] = 0x00;
	desData[3] = 0x06;
	desData[4] = light;
	desData[5] = 0x00;
	desData[6] = 0x00;
	desData[7] = 0x0a;
	emit sendSendData(QString(desData.toHex(':')));
	//m_UdpSocket->writeDatagram(desData, QHostAddress("192.168.1.10"), 5001);
	m_UdpSocket->writeDatagram(desData, QHostAddress(m_remoteIP), 5001);
}

void UdpMaster::sendPanTileCommandToUdp(qint8 panTilt)
{
	
	QByteArray desData;
	desData.clear();
	desData[0] = 0xfe;
	desData[1] = 0x08;
	desData[2] = 0x00;
	desData[3] = 0x05;
	desData[4] = panTilt;
	desData[5] = 0x00;
	desData[6] = 0x00;
	desData[7] = 0x0a;
	qDebug() << QString(desData.toHex(':'));
	emit sendSendData(QString(desData.toHex(':')));
	m_UdpSocket->writeDatagram(desData, QHostAddress(m_remoteIP), 5001);
	//m_UdpSocket->writeDatagram(desData, QHostAddress("192.168.1.10"), 5001);
}

void UdpMaster::sendZoomOut()
{

}

void UdpMaster::sendMoveCommandToUDP(float axisX, float axisY, float axisR, float axisU, qint8 b)
{
#pragma pack(1)
	struct moveData
	{
		qint16 x; //左移右移
		qint16 y; //前进后退
		qint16 r; //左转右转？
		qint16 u; //上浮下潜？
		quint8 b; //定深定向 0:(!定深&&!定向) 1:(定深&&定向) 2:(!定深&&定向) 3:(定深&&定向)
				  //0000 0:000
				  //2位推进方式：0（尾巴）1（螺旋）
			      //1位：定航
				  //0位：定深
	}MoveCmd;
#pragma pack()

	MoveCmd.x = axisX;
	MoveCmd.y = axisY;
	MoveCmd.r = axisR;
	MoveCmd.u = axisU;
	MoveCmd.b = b;
	qDebug() <<  MoveCmd.x << ":" << MoveCmd.y << ":" << MoveCmd.r << ":" << MoveCmd.u << ":" << MoveCmd.b;
	
	QByteArray desData;
	QByteArray Code;
	desData.clear();
	desData[0] = 0xfe;
	desData[1] = sizeof(MoveCmd) + 7;
	desData[2] = 0x00;
	desData[3] = 0x04;
	Code = QByteArray::fromRawData((char*)&MoveCmd, sizeof(MoveCmd));
	desData += Code;
	desData += (char)0x00;
	desData += (char)0x00;
	desData += (char)0x0a;
	emit sendSendData(QString(desData.toHex(':')));
	m_UdpSocket->writeDatagram(desData, QHostAddress(m_remoteIP), 5001);
	//m_UdpSocket->writeDatagram(desData, QHostAddress("192.168.1.10"), 5001);
}

void UdpMaster::sendSetMotorParameters(qint8 LF, qint8 LB, qint8 RF, qint8 RB)
{
	QByteArray desData;
	desData.clear();
	desData[0] = 0xfe;
	desData[1] = 0x09;
	desData[2] = 0x00;
	desData[3] = 0x10;
	desData[4] = LF;
	desData[5] = LB;
	desData[6] = RF;
	desData[7] = RB;
	desData[8] = 0x0a;
	emit sendSendData(QString(desData.toHex(':')));
	m_UdpSocket->writeDatagram(desData, QHostAddress(m_remoteIP), 5001);
	//m_UdpSocket->writeDatagram(desData, QHostAddress("192.168.1.10"), 5001);
}

void UdpMaster::sendSetPIDParameters(qint8 mode, float P, float I, float D)
{
#pragma pack(4)
	struct moveData
	{
		float P; //
		float I; //
		float D; //
	}PIDCmd;
#pragma pack()

	PIDCmd.P = P;
	PIDCmd.I = I;
	PIDCmd.D = D;

	QByteArray Code;
	Code = QByteArray::fromRawData((char*)&PIDCmd, sizeof(PIDCmd));

	QByteArray desData;
	desData.clear();
	desData[0] = 0xfe;
	desData[1] = sizeof(PIDCmd) + 8;
	desData[2] = 0x00;
	desData[3] = 0x07;
	desData[4] = mode; //mode:0 == 深度PID； mode:1 == 航向PID；

	desData += Code;
	desData += (char)0x00;
	desData += (char)0x00;
	desData += (char)0x0a;
	emit sendSendData(QString(desData.toHex(':')));
	m_UdpSocket->writeDatagram(desData, QHostAddress(m_remoteIP), 5001);
	//m_UdpSocket->writeDatagram(desData, QHostAddress("192.168.1.10"), 5001);
}

void UdpMaster::sendMachineHand(qint8 qi)
{
	QByteArray desData;
	desData.clear();
	desData[0] = 0xfe;
	desData[1] = 0x09;
	desData[2] = 0x00;
	desData[3] = 0x20; //命令号
	desData[4] = 0x01; //0:读 1:写
	desData[5] = qi; //（0 - 200）电机速度  0：最大速度张开； 100：停止 ；200：最大速度夹住
	desData[6] = 0x00;
	desData[7] = 0x00;
	desData[8] = 0x0a;
	emit sendSendData(QString(desData.toHex(':')));
	m_UdpSocket->writeDatagram(desData, QHostAddress(m_remoteIP), 5001);
}

void UdpMaster::sendGPS(float longit, float latit)
{
	struct GPS_st
	{
		int num_of_satellite;  //卫星数，小于4个卫星，经纬度值不可取，一般不会用到。
		float longitude; //经度
		float latitude; //纬度
		float coordinate[2]; //经过某种变换，得到的坐标值
	}gps;
	qDebug() << sizeof(gps);
	gps.num_of_satellite = 0;
	gps.longitude = longit;
	gps.latitude = latit;
	gps.coordinate[0] = 0;
	gps.coordinate[1] = 0;

	QByteArray Code;
	Code = QByteArray::fromRawData((char*)&gps, sizeof(gps));

	QByteArray desData;
	desData.clear();
	desData[0] = 0xfe;
	desData[1] = sizeof(gps) + 7;
	desData[2] = 0x00;
	desData[3] = 0x20;

	desData += Code;
	desData += (char)0x00;
	desData += (char)0x00;
	desData += (char)0x0a;
	emit sendSendData(QString(desData.toHex(':')));
	m_UdpSocket->writeDatagram(desData, QHostAddress(m_remoteIP), 5001);
}

