#pragma once
#ifndef TPMANAGER_H_
#define TPMANAGER_H_
#include "CTPQuote.h"

class CThostFtdcMdApi;
class QuoteAPI;

class CTPManager
{
public:
	CTPManager(void);
	~CTPManager(void);
	int Init(char* pszNsAddress);
	int Destroy();
	void RegOnFrontConnected(PFnOnFrontConnected onFrontConnected);
	void RegOnFrontDisconnected(PFnOnFrontDisconnected onFrontDisconnected);
	void RegOnHeartBeatWarning(PFnOnHeartBeatWarning onHeartBeatWarning);
	void RegOnRspUserLogin(PFnOnRspUserLogin onRspUserLogin);
	void RegOnRspUserLogout(PFnOnRspUserLogout onRspUserLogout);
	void RegOnRspError(PFnOnRspError onRspError);
	void RegOnRspSubMarketData(PFnOnRspSubMarketData onRspSubMarketData);
	void RegOnRspUnSubMarketData(PFnOnRspUnSubMarketData onRspUnSubMarketData);
	void RegOnRspSubForQuoteRsp(PFnOnRspSubForQuoteRsp onRspSubForQuoteRsp);
	void RegOnRspUnSubForQuoteRsp(PFnOnRspUnSubForQuoteRsp onRspUnSubForQuoteRsp);
	void RegOnRtnDepthMarketData(PFnOnRtnDepthMarketData onRtnDepthMarketData);

public:
	int ReqUserLogin(char* brokerId, char* userId, char* password);
	int ReqUserLogout(char* brokerId, char* userId);
	int SubscribeMarketData(char *ppInvestmentID[], int nCount);
	int UnSubscribeMarketData(char *ppInstrumentID[], int nCount);
	int SubscribeForQuoteRsp(char *ppInstrumentID[], int nCount);
	int UnSubscribeForQuoteRsp(char *ppInstrumentID[], int nCount);
private:
	CThostFtdcMdApi* md;
	QuoteAPI *api;
	int requestId;
};

#endif
