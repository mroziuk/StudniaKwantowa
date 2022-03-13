using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ChartTestTwo
{
    
    public class Data
    {
        public string[] lines;
        public Data()
        {
            lines = System.IO.File.ReadAllLines("wynik.dat");
        }
        public void load()
        {
            lines = System.IO.File.ReadAllLines("wynik.dat");
        }
    }
}
