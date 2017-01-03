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

	//创建实例，如果需要注册回调，需要在创建完成时候之后，初始化之前注册回调
	int Create();
	//初始化实例
	int Init(char* pszNsAddress);
	//阻塞线程
	int Wait();
	int Destroy();

public:
	//注册回调接口
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
