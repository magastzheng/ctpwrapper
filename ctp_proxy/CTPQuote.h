#pragma once
#define DllExport __declspec(dllexport)
#define WINAPI __stdcall
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

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
	//TThostFtdcPriceType	PreClosePrice;
	///昨持仓量
	//TThostFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	double	OpenPrice;
	///最高价
	double	HighestPrice;
	///最低价
	double	LowestPrice;
	///数量
	//TThostFtdcVolumeType	Volume;
	///成交金额
	//TThostFtdcMoneyType	Turnover;
	///持仓量
	//TThostFtdcLargeVolumeType	OpenInterest;
	///今收盘
	//TThostFtdcPriceType	ClosePrice;
	///本次结算价
	//TThostFtdcPriceType	SettlementPrice;
	///涨停板价
	double	UpperLimitPrice;
	///跌停板价
	double	LowerLimitPrice;
	///昨虚实度
	//TThostFtdcRatioType	PreDelta;
	///今虚实度
	//TThostFtdcRatioType	CurrDelta;
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
	///当日均价
	//TThostFtdcPriceType	AveragePrice;
	///业务日期
	//TThostFtdcDateType	ActionDay;
};

typedef int (WINAPI *FrontConnected)();
typedef int (WINAPI *FrontDisconnected)(int nReason);
typedef int (WINAPI *RspUserLogin)(int nRequestId);
typedef int (WINAPI *RspUserLogout)(int nReason);
typedef int (WINAPI *RspError)(int nErrorId, const char *strMsg);
typedef int (WINAPI *RspSubMarketData)();
typedef int (WINAPI *RtnDepthMarketData)(MarketData* data);



