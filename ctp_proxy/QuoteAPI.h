#pragma once

#ifndef QUOTEAPI_H_
#define QUOTEAPI_H_

#include "../include/ThostFtdcMdApi.h"
#include "CTPQuote.h"

class QuoteAPI : CThostFtdcMdSpi
{
public:
	QuoteAPI(void);
	~QuoteAPI(void);
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);
	
	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������Ӧ��
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����ѯ��Ӧ��
	virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ȡ������ѯ��Ӧ��
	virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

	///ѯ��֪ͨ
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);

public:
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

private:
	PFnOnFrontConnected			_fnOnFrontConnected;
	PFnOnFrontDisconnected		_fnOnFrontDisconnected;
	PFnOnHeartBeatWarning		_fnOnHeartBeatWarning;
	PFnOnRspUserLogin			_fnOnRspUserLogin;
	PFnOnRspUserLogout			_fnOnRspUserLogout;
	PFnOnRspError				_fnOnRspError;
	PFnOnRspSubMarketData		_fnOnRspSubMarketData;
	PFnOnRspUnSubMarketData		_fnOnRspUnSubMarketData;
	PFnOnRspSubForQuoteRsp		_fnOnRspSubForQuoteRsp;
	PFnOnRspUnSubForQuoteRsp	_fnOnRspUnSubForQuoteRsp;
	PFnOnRtnDepthMarketData		_fnOnRtnDepthMarketData;
};

#endif