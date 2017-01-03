#include "stdafx.h"
#include "TPManager.h"
#include "QuoteAPI.h"


CTPManager::CTPManager(void)
{
}


CTPManager::~CTPManager(void)
{
}

int CTPManager::Create()
{
	api = new QuoteAPI();
	md = CThostFtdcMdApi::CreateFtdcMdApi("./qlog");

	return 0;
}

int CTPManager::Init(char* pszNsAddress)
{
	md->RegisterSpi((CThostFtdcMdSpi*)api);
	md->RegisterFront(pszNsAddress);
	md->Init();
	//md->Join();

	return 0;
}

int CTPManager::Wait()
{
	return md->Join();
}

int CTPManager::Destroy()
{
	md->RegisterSpi(NULL);
	md->Release();
	md = NULL;

	if(NULL != api)
	{
		delete api;
	}

	return 0;
}

void CTPManager::RegOnFrontConnected(PFnOnFrontConnected onFrontConnected)
{
	api->RegOnFrontConnected(onFrontConnected);
}

void CTPManager::RegOnFrontDisconnected(PFnOnFrontDisconnected onFrontDisconnected)
{
	api->RegOnFrontDisconnected(onFrontDisconnected);
}

void CTPManager::RegOnHeartBeatWarning(PFnOnHeartBeatWarning onHeartBeatWarning)
{
	api->RegOnHeartBeatWarning(onHeartBeatWarning);
}

void CTPManager::RegOnRspUserLogin(PFnOnRspUserLogin onRspUserLogin)
{
	api->RegOnRspUserLogin(onRspUserLogin);
}

void CTPManager::RegOnRspUserLogout(PFnOnRspUserLogout onRspUserLogout)
{
	api->RegOnRspUserLogout(onRspUserLogout);
}

void CTPManager::RegOnRspError(PFnOnRspError onRspError)
{
	api->RegOnRspError(onRspError);
}

void CTPManager::RegOnRspSubMarketData(PFnOnRspSubMarketData onRspSubMarketData)
{
	api->RegOnRspSubMarketData(onRspSubMarketData);
}

void CTPManager::RegOnRspUnSubMarketData(PFnOnRspUnSubMarketData onRspUnSubMarketData)
{
	api->RegOnRspUnSubMarketData(onRspUnSubMarketData);
}

void CTPManager::RegOnRspSubForQuoteRsp(PFnOnRspSubForQuoteRsp onRspSubForQuoteRsp)
{
	api->RegOnRspSubForQuoteRsp(onRspSubForQuoteRsp);
}

void CTPManager::RegOnRspUnSubForQuoteRsp(PFnOnRspUnSubForQuoteRsp onRspUnSubForQuoteRsp)
{
	api->RegOnRspUnSubForQuoteRsp(onRspUnSubForQuoteRsp);
}

void CTPManager::RegOnRtnDepthMarketData(PFnOnRtnDepthMarketData onRtnDepthMarketData)
{
	api->RegOnRtnDepthMarketData(onRtnDepthMarketData);
}

int CTPManager::ReqUserLogin(char* brokerId, char* userId, char* password)
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, sizeof(req.BrokerID), brokerId);
	strcpy_s(req.UserID, sizeof(req.UserID), userId);
	strcpy_s(req.Password, sizeof(req.Password), password);

	return md->ReqUserLogin(&req, ++requestId);
}

int CTPManager::ReqUserLogout(char* brokerId, char* userId)
{
	CThostFtdcUserLogoutField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerId);
	strcpy_s(req.UserID, userId);

	return md->ReqUserLogout(&req, requestId);
}

int CTPManager::SubscribeMarketData(char *ppInvestmentID[], int nCount)
{
	return md->SubscribeMarketData(ppInvestmentID, nCount);
}

int CTPManager::UnSubscribeMarketData(char *ppInstrumentID[], int nCount)
{
	return md->UnSubscribeMarketData(ppInstrumentID, nCount);
}

int CTPManager::SubscribeForQuoteRsp(char *ppInstrumentID[], int nCount)
{
	return md->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

int CTPManager::UnSubscribeForQuoteRsp(char *ppInstrumentID[], int nCount)
{
	return md->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}