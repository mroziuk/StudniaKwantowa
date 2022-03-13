using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace ChartTestTwo
{
    public partial class MainForm : Form
    {
        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void buttonSaveImage_Click(object sender, EventArgs e)
        {
            chart.SaveImage("wykres"+DateTime.Now.ToString().Replace('/','.').Replace(':','.')+".png", System.Windows.Forms.DataVisualization.Charting.ChartImageFormat.Png);
        }

        public const string cppDllRir = @"..\..\Debug\DllLasery.dll";
        //public const string cppDllRir = @"DllLasery.dll";
        [DllImport(cppDllRir, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode, SetLastError = true)]
        public static extern int testDll(int a);
        [DllImport(cppDllRir, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode, SetLastError = true)]
        public static extern int calculate(int i1, int i2, int i3, int i4, int i5, int i6,
        double d1, double d2, double d3, double d4, double d5, double d6, double d7, double d8);
        private Data data;
        public MainForm()
        {
            InitializeComponent();
            boxMaterial1.SelectedIndex = 0;
            boxMaterial2.SelectedIndex = 0;
        }
        private void initializeChart()
        {
            try
            {
                double minValue = 0;
                double maxValue = 0;
                double szerokoscX = 2 * (double)numericUpDown1.Value + (double)numericSzerokosc1.Value + (double)numericSzerokosc2.Value;
                szerokoscX = 1500 / szerokoscX;
                var objChart = chart.ChartAreas[0];
                objChart.AxisX.IntervalType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Number;
                objChart.AxisX.Minimum = 0;
                objChart.AxisX.Maximum = Math.Round(1500 /szerokoscX);
                objChart.AxisY.IntervalType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Number;
                List<Color> kolorki = new List<Color>();
                Color[] kolorkiWlasne = { Color.Red, Color.Blue, Color.Green, Color.GreenYellow, Color.Orange, Color.Purple };
                for (int j = 0; j < 3; j++)
                    kolorki.Add(Color.Black);
                int length = Math.Max((int)numericWartosciWlasne.Value, 1);
                for (int j = 0; j < 10; j++)
                    for (int i = 0; i < length; i++)
                        kolorki.Add(kolorkiWlasne[i]);

                chart.Series.Clear();
                for (int i = 1; i < data.lines[i].Split().Length; i++)
                {
                    chart.Series.Add("d" + i);
                    chart.Series["d" + i].Color = kolorki[i];

                    chart.Series["d" + i].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
                }
                NumberFormatInfo provider = new NumberFormatInfo();
                provider.NumberDecimalSeparator = ".";
                provider.NumberGroupSeparator = ",";
                //adding data
                for (int i = 0; i < data.lines.Length; i++)
                {
                    string[] values = data.lines[i].Split();
                    for (int j = 1; j < values.Length; j++)
                    {
                        string s = values[j];
                        if (s != null && s != "")
                        {
                            double tmp = double.Parse(values[j], provider);
                            if (tmp < minValue)
                                minValue = tmp;
                            if (tmp > maxValue)
                                maxValue = tmp;
                            chart.Series["d" + j].Points.AddXY(Math.Round((double)i / szerokoscX, 2), tmp);
                        }
                    }
                }
                objChart.AxisY.Minimum = Math.Round(minValue,2) - 0.1;
                objChart.AxisY.Maximum = Math.Round(maxValue,2) + 0.1;
            }
            catch (Exception)
            { 
                MessageBox.Show("Bład, wprowadź poprawne dane");
            }
        }
        private void buttonStart_Click(object sender, EventArgs e)
        {
            reloadDataToFIles();
            data = new Data();
            initializeChart();
            string[] wartosci = System.IO.File.ReadAllLines("wynik2.dat");
            gruboscKrytyczna1.Text = wartosci[3];
            gruboscKrytyczna2.Text = wartosci[4];
        }
        private void reloadDataToFIles()
        {
            try
            {
                int mat1 = boxMaterial1.SelectedIndex;
                int mat2 = boxMaterial2.SelectedIndex;
                double temp = (double)numericTemperatura.Value;
                int liczba = (int)numericWartosciWlasne.Value;
                int calk1 = (int)numericCalka1.Value;
                int calk2 = (int)numericCalka2.Value;
                int sz_A = (int)numericUpDown1.Value;
                int sz_B = (int)numericSzerokosc1.Value;
                int sz_C = (int)numericSzerokosc2.Value;
                double x1 = (double)numericX1.Value;
                double x2 = (double)numericX2.Value;
                double y1 = (double)numericY1.Value;
                double y2 = (double)numericY2.Value;
                x1 = Math.Min(Math.Max(0.00001,x1), 0.99999);
                x2 = Math.Min(Math.Max(0.00001,x2), 0.99999);
            
                int x = calculate(mat1, mat2, 1500, liczba, calk1-1, calk2-1, sz_B, sz_C, sz_A, temp, x1, y1, x2, y2);

            }
            catch (Exception)
            {
                MessageBox.Show("Bład, wprowadź poprawne dane");
            }
        }
        private void buttonTest_Click(object sender, EventArgs e)
        {
            if(numericWartosciWlasne.Value == 0)
            {
                MessageBox.Show("Bład, brak wartosci własnych");
                return;
            }
            int liczba = (int)numericWartosciWlasne.Value;
            int calk1 = (int)numericCalka1.Value;
            int calk2 = (int)numericCalka2.Value;
            if (calk1 > liczba)
            {
                calk1 = liczba;
                numericCalka1.Value = (decimal)liczba;
            }
            if (calk2 > liczba)
            {
                calk2 = liczba;
                numericCalka2.Value = (decimal)liczba;
            }
            reloadDataToFIles();
            string[] wartosci = System.IO.File.ReadAllLines("wynik2.dat");
            calkaPrzekrycia.Text = wartosci[0];
            energiaPrzejscia.Text = wartosci[1];
            dlugoscFali.Text = wartosci[2];
        }
    }
}
