#include "stdafx.h"
#include <stdio.h>
#include "QuoteAPI.h"


QuoteAPI::QuoteAPI(void)
{
}


QuoteAPI::~QuoteAPI(void)
{
}

void QuoteAPI::OnFrontConnected()
{
	if(_fnOnFrontConnected)
	{
		_fnOnFrontConnected();
	}
}

void QuoteAPI::OnFrontDisconnected(int nReason)
{
	if(_fnOnFrontDisconnected)
	{
		_fnOnFrontDisconnected(nReason);
	}
}

void QuoteAPI::OnHeartBeatWarning(int nTimeLapse)
{
	if(_fnOnHeartBeatWarning)
	{
		_fnOnHeartBeatWarning(nTimeLapse);
	}
}

void QuoteAPI::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	int eId = -1;
	if(pRspInfo)
	{
		eId = pRspInfo->ErrorID;
	}

	if(0 == eId)
	{
		//TODO: get the tradingday
	}

	if(_fnOnRspUserLogin)
	{
		_fnOnRspUserLogin(eId);
	}
}

void QuoteAPI::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(_fnOnRspUserLogout)
	{

		//_fnOnRspUserLogout(nRequestID);
	}
}

void QuoteAPI::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(_fnOnRspError && pRspInfo)
	{
		_fnOnRspError(pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	}
}

void QuoteAPI::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(_fnOnRspSubMarketData)
	{
		//TODO:
	}
}

void QuoteAPI::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(_fnOnRspUnSubMarketData)
	{
		//TODO:
	}
}

void QuoteAPI::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(_fnOnRspSubForQuoteRsp)
	{
	}
}

void QuoteAPI::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(_fnOnRspUnSubForQuoteRsp)
	{
	}
}

void QuoteAPI::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	if(_fnOnRtnDepthMarketData)
	{
		if(NULL == pDepthMarketData)
		{
			return;
		}

		//栈上的对象不能跨出其作用域
		//MarketData *d = new MarketData();
		MarketData d;
		memset(&d, 0, sizeof(MarketData));

		strcpy_s(d.InstrumentID, sizeof(d.InstrumentID), pDepthMarketData->InstrumentID);
		d.LastPrice = pDepthMarketData->LastPrice;
		d.PreClosePrice = pDepthMarketData->PreClosePrice;
		d.OpenPrice = pDepthMarketData->OpenPrice;
		d.HighestPrice = pDepthMarketData->HighestPrice;
		d.LowestPrice = pDepthMarketData->LowestPrice;
		d.UpperLimitPrice = pDepthMarketData->UpperLimitPrice;
		d.LowerLimitPrice = pDepthMarketData->LowerLimitPrice;
		d.UpdateMillisec = pDepthMarketData->UpdateMillisec;
		sprintf_s(d.UpdateTime, "%s", pDepthMarketData->UpdateTime);
		d.AskPrice1 = pDepthMarketData->AskPrice1;
		d.AskVolume1 = pDepthMarketData->AskVolume1;
		d.AskPrice2 = pDepthMarketData->AskPrice2;
		d.AskVolume2 = pDepthMarketData->AskVolume2;
		d.AskPrice3 = pDepthMarketData->AskPrice3;
		d.AskVolume3 = pDepthMarketData->AskVolume3;
		d.AskPrice4 = pDepthMarketData->AskPrice4;
		d.AskVolume4 = pDepthMarketData->AskVolume4;
		d.AskPrice5 = pDepthMarketData->AskPrice5;
		d.AskVolume5 = pDepthMarketData->AskVolume5;
		d.BidPrice1 = pDepthMarketData->BidPrice1;
		d.BidVolume1 = pDepthMarketData->BidVolume1;
		d.BidPrice2 = pDepthMarketData->BidPrice2;
		d.BidVolume2 = pDepthMarketData->BidVolume2;
		d.BidPrice3 = pDepthMarketData->BidPrice3;
		d.BidVolume3 = pDepthMarketData->BidVolume3;
		d.BidPrice4 = pDepthMarketData->BidPrice4;
		d.BidVolume4 = pDepthMarketData->BidVolume4;
		d.BidPrice5 = pDepthMarketData->BidPrice5;
		d.BidVolume5 = pDepthMarketData->BidVolume5;

		//此处如何处理内存分配问题，在栈中传递地址？？？
		_fnOnRtnDepthMarketData(&d);

		//delete d;
	}
}

void QuoteAPI::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
}

void QuoteAPI::RegOnFrontConnected(PFnOnFrontConnected onFrontConnected)
{
	_fnOnFrontConnected = onFrontConnected;
}

void QuoteAPI::RegOnFrontDisconnected(PFnOnFrontDisconnected onFrontDisconnected)
{
	_fnOnFrontDisconnected = onFrontDisconnected;
}

void QuoteAPI::RegOnHeartBeatWarning(PFnOnHeartBeatWarning onHeartBeatWarning)
{
	_fnOnHeartBeatWarning = onHeartBeatWarning;
}

void QuoteAPI::RegOnRspUserLogin(PFnOnRspUserLogin onRspUserLogin)
{
	_fnOnRspUserLogin = onRspUserLogin;
}

void QuoteAPI::RegOnRspUserLogout(PFnOnRspUserLogout onRspUserLogout)
{
	_fnOnRspUserLogout = onRspUserLogout;
}

void QuoteAPI::RegOnRspError(PFnOnRspError onRspError)
{
	_fnOnRspError = onRspError;
}

void QuoteAPI::RegOnRspSubMarketData(PFnOnRspSubMarketData onRspSubMarketData)
{
	_fnOnRspSubMarketData = onRspSubMarketData;
}

void QuoteAPI::RegOnRspUnSubMarketData(PFnOnRspUnSubMarketData onRspUnSubMarketData)
{
	_fnOnRspUnSubMarketData = onRspUnSubMarketData;
}

void QuoteAPI::RegOnRspSubForQuoteRsp(PFnOnRspSubForQuoteRsp onRspSubForQuoteRsp)
{
	_fnOnRspSubForQuoteRsp = onRspSubForQuoteRsp;
}

void QuoteAPI::RegOnRspUnSubForQuoteRsp(PFnOnRspUnSubForQuoteRsp onRspUnSubForQuoteRsp)
{
	_fnOnRspUnSubForQuoteRsp = onRspUnSubForQuoteRsp;
}

void QuoteAPI::RegOnRtnDepthMarketData(PFnOnRtnDepthMarketData onRtnDepthMarketData)
{
	_fnOnRtnDepthMarketData = onRtnDepthMarketData;
}