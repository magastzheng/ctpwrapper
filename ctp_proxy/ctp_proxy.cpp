// ctp_proxy.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ctp_proxy.h"


// This is an example of an exported variable
CTP_PROXY_API int nctp_proxy=0;

// This is an example of an exported function.
CTP_PROXY_API int fnctp_proxy(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see ctp_proxy.h for the class definition
Cctp_proxy::Cctp_proxy()
{
	return;
}
