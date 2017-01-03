using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CTPWrapper
{
    class Program
    {
        static void Main(string[] args)
        {
            CTPWrapImpl ctpImpl = new CTPWrapImpl();
            ctpImpl.CreateAPI();
            ctpImpl.RegOnFrontConnected(new OnFrontConnected(OnFrontConnected));
            ctpImpl.RegOnFrontDisconnected(new OnFrontDisconnected(OnFrontDisconnected));
            ctpImpl.RegOnHeartBeatWarning(new OnHeartBeatWarning(OnHeartBeatWarning));
            ctpImpl.RegOnRspUserLogin(new OnRspUserLogin(OnRspUserLogin));
            ctpImpl.RegOnRspUserLogout(new OnRspUserLogout(OnRspUserLogout));
            ctpImpl.RegOnRspError(new OnRspError(OnRspError));
            ctpImpl.RegOnRspSubMarketData(new OnRspSubMarketData(OnRspSubMarketData));
            ctpImpl.RegOnRspUnSubMarketData(new OnRspUnSubMarketData(OnRspUnSubMarketData));
            ctpImpl.RegOnRspSubForQuoteRsp(new OnRspSubForQuoteRsp(OnRspSubForQuoteRsp));
            ctpImpl.RegOnRspUnSubForQuoteRsp(new OnRspUnSubForQuoteRsp(OnRspUnSubForQuoteRsp));
            ctpImpl.RegOnRtnDepthMarketData(new OnRtnDepthMarketData(OnRtnDepthMarketData));

            ctpImpl.Init("tcp://test.com");
            ctpImpl.ReqUserLogin("test", "test", "test");

            ctpImpl.Wait();
        }

        static int OnFrontConnected()
        {
            Console.WriteLine("OnFrontConnected");

            return 0;
        }

        static int OnFrontDisconnected(int reason)
        {
            Console.WriteLine("OnFrontDisconnected");

            return 0;
        }

        static int OnHeartBeatWarning(int timeLapse)
        {
            Console.WriteLine("OnHeartBeatWarning");

            return 0;
        }

        static int OnRspUserLogin(int requestId)
        {
            Console.WriteLine("OnRspUserLogin");

            return 0;
        }

        static int OnRspUserLogout(int reason)
        {
            Console.WriteLine("OnRspUserLogout");

            return 0;
        }

        static int OnRspError(int errorId, string errorMsg)
        {
            Console.WriteLine("OnRspError");

            return 0;
        }

        static int OnRspSubMarketData(int requestId, string investmentID, int errorId, string errorMsg)
        {
            Console.WriteLine("OnRspSubMarketData");

            return 0;
        }

        static int OnRspUnSubMarketData(int requestId, string investmentID, int errorId, string errorMsg)
        {
            Console.WriteLine("OnRspUnSubMarketData");

            return 0;
        }

        static int OnRspSubForQuoteRsp(int requestId, string investmentID, int errorId, string errorMsg)
        {
            Console.WriteLine("OnRspSubForQuoteRsp");

            return 0;
        }

        static int OnRspUnSubForQuoteRsp(int requestId, string investmentID, int errorId, string errorMsg)
        {
            Console.WriteLine("OnRspUnSubForQuoteRsp");

            return 0;
        }

        static int OnRtnDepthMarketData(ref MarketData data)
        {
            Console.WriteLine("OnRtnDepthMarketData");

            return 0;
        }
    }
}

