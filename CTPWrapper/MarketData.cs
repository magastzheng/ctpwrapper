using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CTPWrapper
{
    [StructLayout(LayoutKind.Sequential)]
    public struct MarketData
    {
        //合约在交易所的代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst=32)]
        public string InvestmentID;

        //最新价
        public double LastPrice;

        //昨收盘
        public double PreClosePrice;

        //今开盘
        public double OpenPrice;

        //最高价
        public double HighestPrice;

        //最低价
        public double LowestPrice;

        //涨停板价
        public double UpperLimitPrice;

        //跌停板价
        public double LowerLimitPrice;

        //最后修改时间
        public string UpdateTime;

        //最后修改毫秒
        public int UpdatedMillisec;

        //申买价一
        public double BidPrice1;

        //申买量一
        public int BidVolume1;

        //申卖价一
        public double AskPrice1;

        //申卖量一
        public int AskVolume1;

        //申买价二
        public double BidPrice2;

        //申买量二
        public int BidVolume2;

        //申卖价二
        public double AskPrice2;

        //申卖量二
        public int AskVolume2;

        //申买价三
        public double BidPrice3;

        //申买量三
        public int BidVolume3;

        //申卖价三
        public double AskPrice3;

        //申卖量三
        public int AskVolume3;

        //申买价四
        public double BidPrice4;

        //申买量四
        public int BidVolume4;

        //申卖价四
        public double AskPrice4;

        //申卖量四
        public int AskVolume4;

        //申买价五
        public double BidPrice5;

        //申买量五
        public int BidVolume5;

        //申卖价五
        public double AskPrice5;

        //申卖量五
        public int AskVolume5;
    }
}
