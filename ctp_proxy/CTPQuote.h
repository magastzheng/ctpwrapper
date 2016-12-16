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
	
	///交易日
	//int	TradingDay;
	///合约代码
	//TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	//TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	//TThostFtdcExchangeInstIDType	ExchangeInstID;
	///最新价
	double	LastPrice;
	///上次结算价
	//TThostFtdcPriceType	PreSettlementPrice;
	///昨收盘
	double	PreClosePrice;
	///昨持仓量
	//TThostFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	double	OpenPrice;
	///最高价
	double	HighestPrice;
	///最低价
	double	LowestPrice;
	///涨停板价
	double	UpperLimitPrice;
	///跌停板价
	double	LowerLimitPrice;
	///最后修改时间
	char	UpdateTime[32];
	///最后修改毫秒
	int	UpdateMillisec;
	///申买价一
	double	BidPrice1;
	///申买量一
	int	BidVolume1;
	///申卖价一
	double	AskPrice1;
	///申卖量一
	int	AskVolume1;
	///申买价二
	double	BidPrice2;
	///申买量二
	int	BidVolume2;
	///申卖价二
	double	AskPrice2;
	///申卖量二
	int	AskVolume2;
	///申买价三
	double	BidPrice3;
	///申买量三
	int	BidVolume3;
	///申卖价三
	double	AskPrice3;
	///申卖量三
	int	AskVolume3;
	///申买价四
	double	BidPrice4;
	///申买量四
	int	BidVolume4;
	///申卖价四
	double	AskPrice4;
	///申卖量四
	int	AskVolume4;
	///申买价五
	double	BidPrice5;
	///申买量五
	int	BidVolume5;
	///申卖价五
	double	AskPrice5;
	///申卖量五
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