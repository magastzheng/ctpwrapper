#pragma once
#define DllExport __declspec(dllexport)
#define WINAPI __stdcall
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

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
	//TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	//TThostFtdcLargeVolumeType	PreOpenInterest;
	///����
	double	OpenPrice;
	///��߼�
	double	HighestPrice;
	///��ͼ�
	double	LowestPrice;
	///����
	//TThostFtdcVolumeType	Volume;
	///�ɽ����
	//TThostFtdcMoneyType	Turnover;
	///�ֲ���
	//TThostFtdcLargeVolumeType	OpenInterest;
	///������
	//TThostFtdcPriceType	ClosePrice;
	///���ν����
	//TThostFtdcPriceType	SettlementPrice;
	///��ͣ���
	double	UpperLimitPrice;
	///��ͣ���
	double	LowerLimitPrice;
	///����ʵ��
	//TThostFtdcRatioType	PreDelta;
	///����ʵ��
	//TThostFtdcRatioType	CurrDelta;
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
	///���վ���
	//TThostFtdcPriceType	AveragePrice;
	///ҵ������
	//TThostFtdcDateType	ActionDay;
};

typedef int (WINAPI *FrontConnected)();
typedef int (WINAPI *FrontDisconnected)(int nReason);
typedef int (WINAPI *RspUserLogin)(int nRequestId);
typedef int (WINAPI *RspUserLogout)(int nReason);
typedef int (WINAPI *RspError)(int nErrorId, const char *strMsg);
typedef int (WINAPI *RspSubMarketData)();
typedef int (WINAPI *RtnDepthMarketData)(MarketData* data);



