#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QByteArray>

Dialog::Dialog(UdpMaster *um, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
	, mUdp(um)
	, m_axisX(0)
	, m_axisY(0)
	, m_axisR(0)
	, m_axisU(0)
	, m_light(0)
	, m_panTilt(0)
	, m_p(0)
	, m_i(0)
	, m_d(0)
{
    ui->setupUi(this);
	//setAttribute(Qt::WA_DeleteOnClose);
	//设置joystick图片
	QPixmap pixmap(":/images/joystickInfo.jpg");
	ui->label_14->setPixmap(pixmap);
	ui->label_14->show();
	
	connect(mUdp, SIGNAL(sendReciveData(QString)), this, SLOT(setReciveData(QString)));
	connect(mUdp, SIGNAL(sendSendData(QString)), this, SLOT(setSendData(QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_sendMoveButton_clicked()
{
	//ui->
	m_b = 0;
	qDebug() << ui->depthkeeping->isChecked() << "=====";
	if (ui->depthkeeping->isChecked())
		m_b += 1;
	if (ui->directional->isChecked())
		m_b += 2;
	if (ui->pushMode->isChecked())
		m_b += 4;
	if (ui->mannal->isChecked())
		m_b += 8;
	qDebug() << m_b << "=====";
	//emit sendTest(m_axisX, m_axisY, m_axisR, m_axisU, m_b);
	mUdp->sendMoveCommandToUDP(m_axisX, m_axisY, m_axisR, m_axisU, m_b);
}
void Dialog::on_sendPanTiltButton_clicked()
{
	mUdp->sendPanTileCommandToUdp(m_panTilt);
}

void Dialog::on_sendGPSButton_clicked()
{
	mUdp->sendGPS(ui->longitude->text().toFloat(), ui->latitude->text().toFloat());
}

void Dialog::on_sendSelfBalanceButton_clicked() 
{
	/*QByteArray a = ui->selfBalance->text().toLatin1();
	qDebug() << "aaaaaaaaaaaaa:" << a.toHex();
	int b = 80;
	mUdp->sendSelfBalance(b);*/
	mUdp->sendSelfBalance((qint8)(ui->selfBalance->text().toInt()), ui->openClose->isChecked());
}
void Dialog::on_sendPIDButton_clicked()
{
	mUdp->sendSetPIDParameters(1, m_p, m_i, m_d);
}

void Dialog::on_sendLightButton_clicked()
{
	mUdp->sendLightCommandToUdp(m_light);
}

void Dialog::on_zoomInButton_clicked()
{
	//ui->widgetVideo->zoomOut();
}

void Dialog::on_zoomOutButton_clicked()
{
}

void Dialog::setReciveData(QString s)
{
	m_reciveData = s;
	qDebug() << "m_reciveData" << m_reciveData;
	ui->reciveData->setPlainText(m_reciveData);
}

void Dialog::setSendData(QString s)
{
	m_sendData = s;
	qDebug() << "m_sendData" << m_sendData;
	ui->sendData->setPlainText(m_sendData);
}

