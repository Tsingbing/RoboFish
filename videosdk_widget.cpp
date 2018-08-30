#include "videosdk_widget.h"

#include <bin/netsdk.h>
#include <bin/H264Play.h>

//视频显示模块
long lLogin = 0;//登录句柄
long m_nPlaydecHandle = 0;//decode handle
long m_iPlayhandle = -1;//播放 handle
//断开设备

void __stdcall DisConnectBackCallFunc(LONG lLoginID, char *pchDVRIP,
	LONG nDVRPort, DWORD dwUser)
{
	/*
	char ch[100] = { 0 };
	sprintf(ch, "%s断线了\n", pchDVRIP);
	OutputDebugString(ch);
	CmytestDlg* pThis = (CmytestDlg*)dwUser;
	if (pThis == NULL)
	{
	ASSERT(FALSE);
	return;
	}
	pThis->ReConnect(lLoginID, pchDVRIP, nDVRPort);
	*/
}
//设备信息回调
void __stdcall videoInfoFramCallback(LONG nPort, LONG nType, LPCSTR pBuf, LONG nSize, LONG nUser)
{

	//收到信息帧, 0x03 代表GPRS信息
	if (nType == 0x03)
	{
		//pThis->m_strInfoFrame[nPort] = pBuf;
	}
}
//通过pProc函数指针来获得pbuf数据
void __stdcall pProc(LONG nPort, LPCSTR pBuf, LONG nSize, LONG nWidth, LONG nHeight, LONG nStamp, LONG nType, LONG nUser)
{
	/*
	char StrFileName[256] = {};
	sprintf(StrFileName, "c:\\pic\\%d.bmp", ++i);
	bool ret = H264_PLAY_ConvertToBmpFile((PBYTE)pBuf, nSize, nWidth, nHeight, StrFileName, NULL);
	if (ret)
	{
	OutputDebugString("success.......\n");
	}
	else
	{
	OutputDebugString("error.......\n");
	}
	*/
}
//实时数据回调
int __stdcall RealDataCallBack(long lRealHandle,
	long dwDataType, unsigned char *pBuffer,
	long lbufsize, long dwUser)
{
	//QTime myTime;
	if (!H264_PLAY_InputData(m_nPlaydecHandle, pBuffer, lbufsize))
	{
		qDebug() << "缓存已满!" /*<< myTime.currentTime()*/;
	}

	return 1;
}

VideoSDK_Widget::VideoSDK_Widget(QWidget *parent) : QWidget(parent)
{
    DEV_INFO *pDev = new DEV_INFO;
	pDev->lLoginID = 0;
    pDev->szIpaddress = "192,168,1,12";
    pDev->nPort = 34567;
    pDev->szUserName = "admin";
    pDev->szPsw = "";

    InitSDK();
    if (Connect(pDev))
        qDebug() << "登录成功" << pDev->lLoginID;
    else
        qDebug() << "登录失败" ;
	playCamera();
}



int VideoSDK_Widget::Connect(DEV_INFO *pDev)
{
    BOOL bResult = TRUE;
	bResult = H264_DVR_Init((fDisConnect)DisConnectBackCallFunc, (DWORD)this);
	if (!bResult)
	{
		//QMessageBox::warning(NULL, "WARNING", "设备初始化失败，请重试!", QMessageBox::Retry);
		return 0;
	}

	H264_DVR_DEVICEINFO OutDev;
	int nError = 0;

	H264_DVR_SetConnectTime(3000, 1);

	QString  str(tr("192.168.1.12"));

	char*  address;

	QByteArray ba = str.toLatin1();

	address = ba.data();

	lLogin = H264_DVR_Login(address, 34567, tr("admin").toLatin1().data(),
		tr("").toLatin1().data(), &OutDev, &nError);

	if (lLogin != 0)
	{
		qDebug() << "登录成功!" << "lLogin =" << lLogin;
		//isLoginSucc = true;
		//ui->state_label->setText(tr("设备登录成功!"));
	}
	else
	{
		//QMessageBox::warning(NULL, "WARNING", "设备登录失败", QMessageBox::Retry);
		//ui->state_label->setText(tr("设备登录失败请重试!"));
		return 0;
	}
	return true;
}

bool VideoSDK_Widget::InitSDK()
{
    //initialize
    BOOL bResult = H264_DVR_Init((fDisConnect)DisConnectBackCallFunc,(DWORD)this);

    //he messages received in SDK from DVR which need to upload， such as alarm information，diary information，may do through callback function
    //H264_DVR_SetDVRMessCallBack(MessCallBack,(DWORD)this);

    H264_DVR_SetConnectTime(5000, 3);

    return bResult;
}

bool VideoSDK_Widget::ExitSDK()
{
    H264_DVR_Cleanup();
    return true;
}

void VideoSDK_Widget::playCamera()
{
	HWND g_hWnd = 0;
	//g_hWnd = get_hwnd();//获取窗口句柄
	g_hWnd = (HWND)winId();//获取窗口句柄
	BYTE byFileHeadBuf;

	int m_nIndex = 0;

	if (!H264_PLAY_OpenStream(m_nIndex, &byFileHeadBuf, 1, SOURCE_BUF_MIN * 100))
	{
		QMessageBox::warning(NULL, "WARNING", "视频流打开失败!", QMessageBox::Ok);
		return;//不知道此处加return是否正确
	}
	else
	{
		qDebug() << tr("视频流打开成功");
		//ui->state_label->setText(tr("视频流打开成功"));
		QMessageBox::warning(NULL, "WARNING", "视频流打开成功!", QMessageBox::Ok);
	}
	//设置信息帧回调
	LONG myUser = 0;
	H264_PLAY_SetInfoFrameCallBack(m_nIndex, videoInfoFramCallback, myUser);
	//视频流打开方式
	H264_PLAY_SetStreamOpenMode(m_nIndex, STREAME_REALTIME);
	//图像显示回调
	LONG myPort = 0;
	H264_PLAY_SetDisplayCallBack(m_nIndex, pProc, myPort);

	if (H264_PLAY_Play(m_nIndex, g_hWnd))
	{
		m_nPlaydecHandle = m_nIndex;
		QMessageBox::warning(NULL, "WARNING", "播放成功!", QMessageBox::Ok);
	}
	else
	{
		qDebug() << "播放失败";
		
	}

	H264_DVR_CLIENTINFO playstru;
	int nChannel = 0;
	playstru.nChannel = nChannel;
	playstru.nStream = 0;
	playstru.nMode = 0;

	m_iPlayhandle = H264_DVR_RealPlay(lLogin, &playstru);

	if (m_iPlayhandle <= 0)
	{
		DWORD dwErr = H264_DVR_GetLastError();
		qDebug() << dwErr;//错误类型
	}
	else
	{
		H264_DVR_SetRealDataCallBack(m_iPlayhandle, RealDataCallBack, (long)this);
	}
}

void VideoSDK_Widget::stopCamera()
{

}

void VideoSDK_Widget::zoomOut()
{
	H264_DVR_PTZControl(lLogin, 0, ZOOM_OUT_1, false, 4);	
}

void VideoSDK_Widget::zoomIn()
{
	H264_DVR_PTZControl(lLogin, 0, ZOOM_IN_1, false, 4);
}



