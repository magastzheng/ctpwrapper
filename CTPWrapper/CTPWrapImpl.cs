using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CTPWrapper
{
    public class CTPWrapImpl
    {
        private IntPtr _handle;

        public CTPWrapImpl()
        {
            //_handle = CTPQuoteAPI.CreateAPI("");
        }

        #region public interface
        public void CreateAPI(string nsAddress)
        {
            if (_handle == IntPtr.Zero)
            {
                _handle = CTPQuoteAPI.CreateAPI(nsAddress);
            }
        }

        public void DestroyAPI()
        {
            if (_handle != IntPtr.Zero)
            {
                CTPQuoteAPI.DestroyAPI(_handle);
            }
        }

        public int ReqUserLogin(string brokerId, string userId, string password)
        {
            if (_handle == IntPtr.Zero)
            { 
                //CTPQuoteAPI.CreateAPI
            }
            return CTPQuoteAPI.ReqUserLogin(_handle, brokerId, userId, password);
        }

        public int ReqUserLogout(string brokerId, string userId)
        {
            return CTPQuoteAPI.ReqUserLogout(_handle, brokerId, userId);
        }

        public int SubscribeMarketData(string[] investmentIds, int count)
        {
            return CTPQuoteAPI.SubscribeMarketData(_handle, investmentIds, count);
        }

        public int UnSubscribeMarketData(string[] investmentIds, int count)
        {
            return CTPQuoteAPI.UnSubscribeMarketData(_handle, investmentIds, count);
        }

        public int SubscribeForQuoteRsp(string[] investmentIds, int count)
        {
            return CTPQuoteAPI.SubscribeForQuoteRsp(_handle, investmentIds, count);
        }

        public int UnSubscribeForQuoteRsp(string[] investmentIds, int count)
        {
            return CTPQuoteAPI.UnSubscribeForQuoteRsp(_handle, investmentIds, count);
        }

        #endregion

        #region register callback

        public void RegOnFrontConnected(OnFrontConnected callback)
        {
            CTPQuoteAPI.RegOnFrontConnected(_handle, callback);
        }

        public void RegOnFrontDisconnected(OnFrontDisconnected callback)
        {
            CTPQuoteAPI.RegOnFrontDisconnected(_handle, callback);
        }

        public void RegOnHeartBeatWarning(OnHeartBeatWarning callback)
        {
            CTPQuoteAPI.RegOnHeartBeatWarning(_handle, callback);
        }

        public void RegOnRspUserLogin(OnRspUserLogin callback)
        {
            CTPQuoteAPI.RegOnRspUserLogin(_handle, callback);
        }

        public void RegOnRspUserLogout(OnRspUserLogout callback)
        {
            CTPQuoteAPI.RegOnRspUserLogout(_handle, callback);
        }

        public void RegOnRspSubMarketData(OnRspSubMarketData callback)
        {
            CTPQuoteAPI.RegOnRspSubMarketData(_handle, callback);
        }

        public void RegOnRspUnSubMarketData(OnRspUnSubMarketData callback)
        {
            CTPQuoteAPI.RegOnRspUnSubMarketData(_handle, callback);
        }

        public void RegOnRspSubForQuoteRsp(OnRspSubForQuoteRsp callback)
        {
            CTPQuoteAPI.RegOnRspSubForQuoteRsp(_handle, callback);
        }

        public void RegOnRspUnSubForQuoteRsp(OnRspUnSubForQuoteRsp callback)
        {
            CTPQuoteAPI.RegOnRspUnSubForQuoteRsp(_handle, callback);
        }

        public void RegOnRtnDepthMarketData(OnRtnDepthMarketData callback)
        {
            CTPQuoteAPI.RegOnRtnDepthMarketData(_handle, callback);
        }

        #endregion
    }
}
