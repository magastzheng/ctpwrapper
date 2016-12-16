#include "stdafx.h"
#include "QuoteAPI.h";
#include "TPManager.h"

//CThostFtdcMdApi* md;
//QuoteAPI *api;
//int requestId = 0;

//CTPManager* mgr;

CTPManager* WINAPI CreateAPI(char *pszNsAddress)
{
	CTPManager* mgr = new CTPManager();
	mgr->Init(pszNsAddress);

	return mgr;
}

void WINAPI DestroyAPI(CTPManager* mgr)
{
	mgr->Destroy();
}

void WINAPI RegOnFrontConnected(CTPManager* mgr, PFnOnFrontConnected onFrontConnected)
{
	mgr->RegOnFrontConnected(onFrontConnected);
}

void WINAPI RegOnFrontDisconnected(CTPManager* mgr,PFnOnFrontDisconnected onFrontDisconnected)
{
	mgr->RegOnFrontDisconnected(onFrontDisconnected);
}

void WINAPI RegOnHeartBeatWarning(CTPManager* mgr,PFnOnHeartBeatWarning onHeartBeatWarning)
{
	mgr->RegOnHeartBeatWarning(onHeartBeatWarning);
}

void WINAPI RegOnRspUserLogin(CTPManager* mgr,PFnOnRspUserLogin onRspUserLogin)
{
	mgr->RegOnRspUserLogin(onRspUserLogin);
}

void WINAPI RegOnRspUserLogout(CTPManager* mgr,PFnOnRspUserLogout onRspUserLogout)
{
	mgr->RegOnRspUserLogout(onRspUserLogout);
}

void WINAPI RegOnRspError(CTPManager* mgr,PFnOnRspError onRspError)
{
	mgr->RegOnRspError(onRspError);
}

void WINAPI RegOnRspSubMarketData(CTPManager* mgr,PFnOnRspSubMarketData onRspSubMarketData)
{
	mgr->RegOnRspSubMarketData(onRspSubMarketData);
}

void WINAPI RegOnRspUnSubMarketData(CTPManager* mgr,PFnOnRspUnSubMarketData onRspUnSubMarketData)
{
	mgr->RegOnRspUnSubMarketData(onRspUnSubMarketData);
}

void WINAPI RegOnRspSubForQuoteRsp(CTPManager* mgr,PFnOnRspSubForQuoteRsp onRspSubForQuoteRsp)
{
	mgr->RegOnRspSubForQuoteRsp(onRspSubForQuoteRsp);
}

void WINAPI RegOnRspUnSubForQuoteRsp(CTPManager* mgr,PFnOnRspUnSubForQuoteRsp onRspUnSubForQuoteRsp)
{
	mgr->RegOnRspUnSubForQuoteRsp(onRspUnSubForQuoteRsp);
}

void WINAPI RegOnRtnDepthMarketData(CTPManager* mgr,PFnOnRtnDepthMarketData onRtnDepthMarketData)
{
	mgr->RegOnRtnDepthMarketData(onRtnDepthMarketData);
}

int WINAPI ReqUserLogin(CTPManager* mgr, char* brokerId, char* userId, char* password)
{
	return mgr->ReqUserLogin(brokerId, userId, password);
}

int WINAPI ReqUserLogout(CTPManager* mgr, char* brokerId, char* userId)
{
	return mgr->ReqUserLogout(brokerId, userId);
}

int WINAPI SubscribeMarketData(CTPManager* mgr, char *ppInvestmentID[], int nCount)
{
	return mgr->SubscribeMarketData(ppInvestmentID, nCount);
}

int WINAPI UnSubscribeMarketData(CTPManager* mgr, char *ppInstrumentID[], int nCount)
{
	return mgr->UnSubscribeMarketData(ppInstrumentID, nCount);
}

int WINAPI SubscribeForQuoteRsp(CTPManager* mgr, char *ppInstrumentID[], int nCount)
{
	return mgr->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

int WINAPI UnSubscribeForQuoteRsp(CTPManager* mgr, char *ppInstrumentID[], int nCount)
{
	return mgr->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}