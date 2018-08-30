#ifndef VIDEOSDK_WIDGET_H
#define VIDEOSDK_WIDGET_H

#include <QMessageBox>
#include <QWidget>
#include <QDebug>

#include <bin/netsdk.h>
#include <bin/H264Play.h>

/*
 * 将网络摄像头SDK转化为Widget
 */
#pragma execution_character_set("utf-8")

typedef struct _DEV_INFO
{
    int	nListNum;		   //position in the list

    long lLoginID;			//login handle
    long lID;				//device ID
    QString szDevName;		//device name
	QString szIpaddress;		//device IP
	QString szUserName;		//user name
	QString szPsw;			//pass word
    int nPort;				//port number
    int nTotalChannel;		//total channel

}DEV_INFO;


class VideoSDK_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoSDK_Widget(QWidget *parent = nullptr);
    //连接
    int Connect(DEV_INFO *pDev);
	
signals:

public slots: 
    //播放
    void playCamera();
    //停止
    void stopCamera();
    //放大
	void zoomOut();
    //缩小
	void zoomIn();
    //录制

    //截图
    //void Captute();

public:
    //初始化
    bool InitSDK();
    //退出SDK
    bool ExitSDK();

public:
    //SDK
    long lLogin = 0;
    //SDK_SYSTEM_TIME pSysTime;
	DEV_INFO *pDev;
};

#endif // VIDEOSDK_WIDGET_H
