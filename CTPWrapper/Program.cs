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
            ctpImpl.CreateAPI("");
            ctpImpl.ReqUserLogin("test", "test", "test");
        }
    }
}
