#include "stdafx.h"
#include "QuoteAPI.h"


QuoteAPI::QuoteAPI(void)
{
}


QuoteAPI::~QuoteAPI(void)
{
}

void QuoteAPI::OnFrontConnected()
{

}

void QuoteAPI::OnFrontDisconnected(int nReason)
{

}

void QuoteAPI::OnHeartBeatWarning(int nTimeLapse)
{

}

void QuoteAPI::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
}

void QuoteAPI::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

}

void QuoteAPI::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
}

void QuoteAPI::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

}

void QuoteAPI::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
}

void QuoteAPI::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
}

void QuoteAPI::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

}

void QuoteAPI::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
}

void QuoteAPI::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
}