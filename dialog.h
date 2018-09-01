#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "udpmaster.hpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(UdpMaster *um,QWidget *parent = 0);
    ~Dialog();

signals:


public slots:
	void setReciveData(QString);
	void setSendData(QString);

	void on_axisX_valueChanged(int i) { m_axisX = i; };
	void on_axisY_valueChanged(int i) { m_axisY = i; };
	void on_axisR_valueChanged(int i) { m_axisR = i; };
	void on_axisU_valueChanged(int i) { m_axisU = i; };
	void on_light_valueChanged(int i) { m_light = i; };
	void on_panTilt_valueChanged(int i) { m_panTilt = i; };
	void on_P_valueChanged(int i) { m_p = i; };
	void on_I_valueChanged(int i) { m_i = i; };
	void on_D_valueChanged(int i) { m_d = i; };

	void on_p_textChanged(QString s) { m_p = s.toFloat(); }
	void on_i_textChanged(QString s) { m_i = s.toFloat(); }
	void on_d_textChanged(QString s) { m_d = s.toFloat(); }
	void on_sendMoveButton_clicked();
	void on_sendPanTiltButton_clicked();
	void on_sendGPSButton_clicked();
	void on_sendPIDButton_clicked();
	void on_sendLightButton_clicked();
	void on_sendSelfBalanceButton_clicked();
	void on_zoomInButton_clicked();
	void on_zoomOutButton_clicked();
	
private:
    Ui::Dialog *ui;
	UdpMaster *mUdp;
	int m_axisX;
	int m_axisY;
	int m_axisR;
	int m_axisU;
	qint8 m_b; //Ä£Ê½Ñ¡Ôñ

	float m_p;
	float m_i;
	float m_d;
	
	int m_light;
	int m_panTilt;
	QString m_reciveData;
	QString m_sendData;
};

#endif // DIALOG_H
