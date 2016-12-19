using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CTPWrapper
{
    public delegate int OnFrontConnected();
    public delegate int OnFrontDisconnected(int reason);
    public delegate int OnHeartBeatWarning(int timeLapse);
    public delegate int OnRspUserLogin(int requestId);
    public delegate int OnRspUserLogout(int reason);
    public delegate int OnRspError(int errorId, string errorMsg);
    public delegate int OnRspSubMarketData(int requestId, string investmentID, int errorId, string errorMsg);
    public delegate int OnRspUnSubMarketData(int requestId, string investmentID, int errorId, string errorMsg);
    public delegate int OnRspSubForQuoteRsp(int requestId, string investmentID, int errorId, string errorMsg);
    public delegate int OnRspUnSubForQuoteRsp(int requestId, string investmentID, int errorId, string errorMsg);
    public delegate int OnRtnDepthMarketData(ref MarketData data);

    public static class CTPQuoteAPI
    {
        private const string DLLName = "ctp_proxy.dll";

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateAPI(string nsAddress);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyAPI(IntPtr mgr);

        #region call the interface for the business
        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ReqUserLogin(IntPtr mgr, string brokerId, string userId, string password);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ReqUserLogout(IntPtr mgr, string brokerId, string userId);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SubscribeMarketData(IntPtr mgr, string[] investmentIds, int count);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int UnSubscribeMarketData(IntPtr mgr, string[] investmentIds, int count);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SubscribeForQuoteRsp(IntPtr mgr, string[] investmentIds, int count);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int UnSubscribeForQuoteRsp(IntPtr mgr, string[] investmentIds, int count);

        #endregion

        #region register callback

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnFrontConnected(IntPtr mgr, OnFrontConnected callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnFrontDisconnected(IntPtr mgr, OnFrontDisconnected callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnHeartBeatWarning(IntPtr mgr, OnHeartBeatWarning callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnRspUserLogin(IntPtr mgr, OnRspUserLogin callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnRspUserLogout(IntPtr mgr, OnRspUserLogout callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnRspSubMarketData(IntPtr mgr, OnRspSubMarketData callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnRspUnSubMarketData(IntPtr mgr, OnRspUnSubMarketData callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnRspSubForQuoteRsp(IntPtr mgr, OnRspSubForQuoteRsp callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnRspUnSubForQuoteRsp(IntPtr mgr, OnRspUnSubForQuoteRsp callback);

        [DllImport(DLLName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegOnRtnDepthMarketData(IntPtr mgr, OnRtnDepthMarketData callback);

        #endregion
    }
}
