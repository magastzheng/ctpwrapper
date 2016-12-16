#pragma once

#ifndef CTPQUOTE_H_
#define CTPQUOTE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DllExport __declspec(dllexport)
#define WINAPI _cdecl
#define WIN32_LEAN_AND_MEAN

//#include <Windows.h>



struct MarketData
{
	char InstrumentID[32];
	
	///������
	//int	TradingDay;
	///��Լ����
	//TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	//TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	//TThostFtdcExchangeInstIDType	ExchangeInstID;
	///���¼�
	double	LastPrice;
	///�ϴν����
	//TThostFtdcPriceType	PreSettlementPrice;
	///������
	double	PreClosePrice;
	///��ֲ���
	//TThostFtdcLargeVolumeType	PreOpenInterest;
	///����
	double	OpenPrice;
	///��߼�
	double	HighestPrice;
	///��ͼ�
	double	LowestPrice;
	///��ͣ���
	double	UpperLimitPrice;
	///��ͣ���
	double	LowerLimitPrice;
	///����޸�ʱ��
	char	UpdateTime[32];
	///����޸ĺ���
	int	UpdateMillisec;
	///�����һ
	double	BidPrice1;
	///������һ
	int	BidVolume1;
	///������һ
	double	AskPrice1;
	///������һ
	int	AskVolume1;
	///����۶�
	double	BidPrice2;
	///��������
	int	BidVolume2;
	///�����۶�
	double	AskPrice2;
	///��������
	int	AskVolume2;
	///�������
	double	BidPrice3;
	///��������
	int	BidVolume3;
	///��������
	double	AskPrice3;
	///��������
	int	AskVolume3;
	///�������
	double	BidPrice4;
	///��������
	int	BidVolume4;
	///��������
	double	AskPrice4;
	///��������
	int	AskVolume4;
	///�������
	double	BidPrice5;
	///��������
	int	BidVolume5;
	///��������
	double	AskPrice5;
	///��������
	int	AskVolume5;
};

typedef int (WINAPI *PFnOnFrontConnected)();
typedef int (WINAPI *PFnOnFrontDisconnected)(int nReason);
typedef int (WINAPI *PFnOnHeartBeatWarning)(int nTimeLapse);
typedef int (WINAPI *PFnOnRspUserLogin)(int nRequestId);
typedef int (WINAPI *PFnOnRspUserLogout)(int nReason);
typedef int (WINAPI *PFnOnRspError)(int nErrorId, const char *strErrMsg);
typedef int (WINAPI *PFnOnRspSubMarketData)(int nRequestId, const char *investmentID, int nErrorId, const char *strErrMsg);
typedef int (WINAPI *PFnOnRspUnSubMarketData)(int nRequestId, const char *investmentID, int nErrorId, const char *strErrMsg);
typedef int (WINAPI *PFnOnRspSubForQuoteRsp)(int nRequestId, const char *investmentID, int nErrorId, const char *strErrMsg);
typedef int (WINAPI *PFnOnRspUnSubForQuoteRsp)(int nRequestId, const char *investmentID, int nErrorId, const char *strErrMsg);
typedef int (WINAPI *PFnOnRtnDepthMarketData)(MarketData *data);

//void* _OnFrontConnected;
//void* _OnFrontDisconnected;
//void* _OnRspUserLogin;
//void* _OnRspUserLogout;
//void* _OnRspError;
//void* _OnRspSubMarketData;
//void* _OnRspUnSubMarketData;
//void* _OnRspSubForQuoteRsp;
//void* _OnRspUnSubForQuoteRsp;
//void* _OnRtnDepthMarketData;

class QuoteAPI;
class CTPManager;

DllExport CTPManager* WINAPI CreateAPI(char *pszNsAddress);
DllExport void WINAPI DestroyAPI(CTPManager* mgr);
DllExport void WINAPI RegOnFrontConnected(CTPManager* mgr, PFnOnFrontConnected onFrontConnected);
DllExport void WINAPI RegOnFrontDisconnected(CTPManager* mgr, PFnOnFrontDisconnected onFrontDisconnected);
DllExport void WINAPI RegOnHeartBeatWarning(CTPManager* mgr, PFnOnHeartBeatWarning onHeartBeatWarning);
DllExport void WINAPI RegOnRspUserLogin(CTPManager* mgr, PFnOnRspUserLogin onRspUserLogin);
DllExport void WINAPI RegOnRspUserLogout(CTPManager* mgr, PFnOnRspUserLogout onRspUserLogout);
DllExport void WINAPI RegOnRspError(CTPManager* mgr, PFnOnRspError onRspError);
DllExport void WINAPI RegOnRspSubMarketData(CTPManager* mgr, PFnOnRspSubMarketData onRspSubMarketData);
DllExport void WINAPI RegOnRspUnSubMarketData(CTPManager* mgr, PFnOnRspUnSubMarketData onRspUnSubMarketData);
DllExport void WINAPI RegOnRspSubForQuoteRsp(CTPManager* mgr, PFnOnRspSubForQuoteRsp onRspSubForQuoteRsp);
DllExport void WINAPI RegOnRspUnSubForQuoteRsp(CTPManager* mgr, PFnOnRspUnSubForQuoteRsp onRspUnSubForQuoteRsp);
DllExport void WINAPI RegOnRtnDepthMarketData(CTPManager* mgr, PFnOnRtnDepthMarketData onRtnDepthMarketData);

DllExport int WINAPI ReqUserLogin(CTPManager* mgr, char* brokerId, char* userId, char* password);
DllExport int WINAPI ReqUserLogout(CTPManager* mgr, char* brokerId, char* userId);
DllExport int WINAPI SubscribeMarketData(CTPManager* mgr, char *ppInvestmentID[], int nCount);
DllExport int WINAPI UnSubscribeMarketData(CTPManager* mgr, char *ppInstrumentID[], int nCount);
DllExport int WINAPI SubscribeForQuoteRsp(CTPManager* mgr, char *ppInstrumentID[], int nCount);
DllExport int WINAPI UnSubscribeForQuoteRsp(CTPManager* mgr, char *ppInstrumentID[], int nCount);

#ifdef __cplusplus
}
#endif

#endif