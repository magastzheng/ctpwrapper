// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CTP_PROXY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CTP_PROXY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CTP_PROXY_EXPORTS
#define CTP_PROXY_API __declspec(dllexport)
#else
#define CTP_PROXY_API __declspec(dllimport)
#endif

#include "ThostFtdcMdApi.h"

// This class is exported from the ctp_proxy.dll
class CTP_PROXY_API Cctp_proxy : CThostFtdcMdSpi{
public:
	Cctp_proxy(void);
	// TODO: add your methods here.
};

extern CTP_PROXY_API int nctp_proxy;

CTP_PROXY_API int fnctp_proxy(void);
