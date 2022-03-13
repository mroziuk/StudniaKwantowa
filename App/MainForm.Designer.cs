
namespace ChartTestTwo
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.chart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.buttonStart = new System.Windows.Forms.Button();
            this.buttonLiczCalki = new System.Windows.Forms.Button();
            this.numericSzerokosc1 = new System.Windows.Forms.NumericUpDown();
            this.numericSzerokosc2 = new System.Windows.Forms.NumericUpDown();
            this.numericX2 = new System.Windows.Forms.NumericUpDown();
            this.numericX1 = new System.Windows.Forms.NumericUpDown();
            this.numericY2 = new System.Windows.Forms.NumericUpDown();
            this.numericY1 = new System.Windows.Forms.NumericUpDown();
            this.boxMaterial1 = new System.Windows.Forms.ComboBox();
            this.boxMaterial2 = new System.Windows.Forms.ComboBox();
            this.numericTemperatura = new System.Windows.Forms.NumericUpDown();
            this.numericCalka2 = new System.Windows.Forms.NumericUpDown();
            this.numericCalka1 = new System.Windows.Forms.NumericUpDown();
            this.numericWartosciWlasne = new System.Windows.Forms.NumericUpDown();
            this.calkaPrzekrycia = new System.Windows.Forms.TextBox();
            this.energiaPrzejscia = new System.Windows.Forms.TextBox();
            this.buttonSaveImage = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.gruboscKrytyczna1 = new System.Windows.Forms.TextBox();
            this.gruboscKrytyczna2 = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.dlugoscFali = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.chart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericSzerokosc1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericSzerokosc2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericX2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericX1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericY2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericY1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericTemperatura)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCalka2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCalka1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericWartosciWlasne)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // chart
            // 
            this.chart.BackColor = System.Drawing.Color.Transparent;
            chartArea1.AxisX.MajorGrid.Enabled = false;
            chartArea1.AxisX.MinorGrid.LineColor = System.Drawing.Color.DarkGray;
            chartArea1.AxisX.Title = "położenie (nm)";
            chartArea1.AxisY.MajorGrid.Enabled = false;
            chartArea1.AxisY.Title = "E (eV)";
            chartArea1.Name = "ChartArea1";
            this.chart.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chart.Legends.Add(legend1);
            this.chart.Location = new System.Drawing.Point(503, 42);
            this.chart.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.chart.Name = "chart";
            this.chart.Palette = System.Windows.Forms.DataVisualization.Charting.ChartColorPalette.SeaGreen;
            series1.ChartArea = "ChartArea1";
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chart.Series.Add(series1);
            this.chart.Size = new System.Drawing.Size(871, 770);
            this.chart.TabIndex = 0;
            this.chart.Text = "chart1";
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(24, 405);
            this.buttonStart.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(399, 87);
            this.buttonStart.TabIndex = 1;
            this.buttonStart.Text = "Start";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // buttonLiczCalki
            // 
            this.buttonLiczCalki.Location = new System.Drawing.Point(24, 649);
            this.buttonLiczCalki.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonLiczCalki.Name = "buttonLiczCalki";
            this.buttonLiczCalki.Size = new System.Drawing.Size(289, 58);
            this.buttonLiczCalki.TabIndex = 2;
            this.buttonLiczCalki.Text = "Licz Całki";
            this.buttonLiczCalki.UseVisualStyleBackColor = true;
            this.buttonLiczCalki.Click += new System.EventHandler(this.buttonTest_Click);
            // 
            // numericSzerokosc1
            // 
            this.numericSzerokosc1.Location = new System.Drawing.Point(175, 220);
            this.numericSzerokosc1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericSzerokosc1.Maximum = new decimal(new int[] {
            50,
            0,
            0,
            0});
            this.numericSzerokosc1.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericSzerokosc1.Name = "numericSzerokosc1";
            this.numericSzerokosc1.Size = new System.Drawing.Size(123, 22);
            this.numericSzerokosc1.TabIndex = 3;
            this.numericSzerokosc1.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // numericSzerokosc2
            // 
            this.numericSzerokosc2.Location = new System.Drawing.Point(315, 220);
            this.numericSzerokosc2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericSzerokosc2.Name = "numericSzerokosc2";
            this.numericSzerokosc2.Size = new System.Drawing.Size(123, 22);
            this.numericSzerokosc2.TabIndex = 4;
            this.numericSzerokosc2.Value = new decimal(new int[] {
            6,
            0,
            0,
            0});
            // 
            // numericX2
            // 
            this.numericX2.DecimalPlaces = 2;
            this.numericX2.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericX2.Location = new System.Drawing.Point(315, 144);
            this.numericX2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericX2.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericX2.Name = "numericX2";
            this.numericX2.Size = new System.Drawing.Size(60, 22);
            this.numericX2.TabIndex = 6;
            this.numericX2.Value = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            // 
            // numericX1
            // 
            this.numericX1.DecimalPlaces = 2;
            this.numericX1.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericX1.Location = new System.Drawing.Point(175, 144);
            this.numericX1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericX1.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericX1.Name = "numericX1";
            this.numericX1.Size = new System.Drawing.Size(56, 22);
            this.numericX1.TabIndex = 5;
            this.numericX1.Value = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            // 
            // numericY2
            // 
            this.numericY2.DecimalPlaces = 2;
            this.numericY2.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericY2.Location = new System.Drawing.Point(380, 144);
            this.numericY2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericY2.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericY2.Name = "numericY2";
            this.numericY2.Size = new System.Drawing.Size(57, 22);
            this.numericY2.TabIndex = 8;
            this.numericY2.Value = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            // 
            // numericY1
            // 
            this.numericY1.DecimalPlaces = 2;
            this.numericY1.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericY1.Location = new System.Drawing.Point(241, 144);
            this.numericY1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericY1.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericY1.Name = "numericY1";
            this.numericY1.Size = new System.Drawing.Size(56, 22);
            this.numericY1.TabIndex = 7;
            this.numericY1.Value = new decimal(new int[] {
            7,
            0,
            0,
            65536});
            // 
            // boxMaterial1
            // 
            this.boxMaterial1.DisplayMember = "1";
            this.boxMaterial1.ForeColor = System.Drawing.SystemColors.WindowText;
            this.boxMaterial1.FormattingEnabled = true;
            this.boxMaterial1.Items.AddRange(new object[] {
            "GaInAsSb",
            "AlGaAsSb"});
            this.boxMaterial1.Location = new System.Drawing.Point(175, 62);
            this.boxMaterial1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.boxMaterial1.Name = "boxMaterial1";
            this.boxMaterial1.Size = new System.Drawing.Size(121, 24);
            this.boxMaterial1.TabIndex = 9;
            this.boxMaterial1.ValueMember = "1";
            // 
            // boxMaterial2
            // 
            this.boxMaterial2.DisplayMember = "GaInAsSb";
            this.boxMaterial2.FormattingEnabled = true;
            this.boxMaterial2.Items.AddRange(new object[] {
            "GaInAsSb",
            "AlGaAsSb"});
            this.boxMaterial2.Location = new System.Drawing.Point(315, 62);
            this.boxMaterial2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.boxMaterial2.Name = "boxMaterial2";
            this.boxMaterial2.Size = new System.Drawing.Size(121, 24);
            this.boxMaterial2.TabIndex = 10;
            this.boxMaterial2.ValueMember = "GaInAsSb";
            // 
            // numericTemperatura
            // 
            this.numericTemperatura.Location = new System.Drawing.Point(24, 375);
            this.numericTemperatura.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericTemperatura.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numericTemperatura.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericTemperatura.Name = "numericTemperatura";
            this.numericTemperatura.Size = new System.Drawing.Size(120, 22);
            this.numericTemperatura.TabIndex = 11;
            this.numericTemperatura.Value = new decimal(new int[] {
            300,
            0,
            0,
            0});
            // 
            // numericCalka2
            // 
            this.numericCalka2.Location = new System.Drawing.Point(175, 601);
            this.numericCalka2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericCalka2.Maximum = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.numericCalka2.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericCalka2.Name = "numericCalka2";
            this.numericCalka2.Size = new System.Drawing.Size(120, 22);
            this.numericCalka2.TabIndex = 13;
            this.numericCalka2.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // numericCalka1
            // 
            this.numericCalka1.Location = new System.Drawing.Point(24, 601);
            this.numericCalka1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericCalka1.Maximum = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.numericCalka1.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericCalka1.Name = "numericCalka1";
            this.numericCalka1.Size = new System.Drawing.Size(120, 22);
            this.numericCalka1.TabIndex = 12;
            this.numericCalka1.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // numericWartosciWlasne
            // 
            this.numericWartosciWlasne.Location = new System.Drawing.Point(255, 375);
            this.numericWartosciWlasne.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.numericWartosciWlasne.Maximum = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.numericWartosciWlasne.Name = "numericWartosciWlasne";
            this.numericWartosciWlasne.Size = new System.Drawing.Size(120, 22);
            this.numericWartosciWlasne.TabIndex = 14;
            this.numericWartosciWlasne.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // calkaPrzekrycia
            // 
            this.calkaPrzekrycia.Location = new System.Drawing.Point(323, 764);
            this.calkaPrzekrycia.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.calkaPrzekrycia.Name = "calkaPrzekrycia";
            this.calkaPrzekrycia.ReadOnly = true;
            this.calkaPrzekrycia.Size = new System.Drawing.Size(100, 22);
            this.calkaPrzekrycia.TabIndex = 15;
            // 
            // energiaPrzejscia
            // 
            this.energiaPrzejscia.Cursor = System.Windows.Forms.Cursors.No;
            this.energiaPrzejscia.Location = new System.Drawing.Point(321, 622);
            this.energiaPrzejscia.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.energiaPrzejscia.Name = "energiaPrzejscia";
            this.energiaPrzejscia.ReadOnly = true;
            this.energiaPrzejscia.Size = new System.Drawing.Size(100, 22);
            this.energiaPrzejscia.TabIndex = 16;
            // 
            // buttonSaveImage
            // 
            this.buttonSaveImage.Location = new System.Drawing.Point(24, 721);
            this.buttonSaveImage.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.buttonSaveImage.Name = "buttonSaveImage";
            this.buttonSaveImage.Size = new System.Drawing.Size(156, 68);
            this.buttonSaveImage.TabIndex = 17;
            this.buttonSaveImage.Text = "zapisz obraz";
            this.buttonSaveImage.UseVisualStyleBackColor = true;
            this.buttonSaveImage.Click += new System.EventHandler(this.buttonSaveImage_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(473, 11);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(311, 42);
            this.label1.TabIndex = 18;
            this.label1.Text = "Struktura A/B/C/A";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(40, 59);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 25);
            this.label2.TabIndex = 19;
            this.label2.Text = " A= GaAs";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label3.Location = new System.Drawing.Point(171, 33);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(104, 25);
            this.label3.TabIndex = 20;
            this.label3.Text = "materiał B:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label4.Location = new System.Drawing.Point(309, 34);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(106, 25);
            this.label4.TabIndex = 21;
            this.label4.Text = "materiał C:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label5.Location = new System.Drawing.Point(16, 183);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(228, 25);
            this.label5.TabIndex = 22;
            this.label5.Text = "szerokość warstwy: (nm)";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(24, 220);
            this.numericUpDown1.Margin = new System.Windows.Forms.Padding(4);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(128, 22);
            this.numericUpDown1.TabIndex = 23;
            this.numericUpDown1.Value = new decimal(new int[] {
            35,
            0,
            0,
            0});
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label6.Location = new System.Drawing.Point(16, 103);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(258, 25);
            this.label6.TabIndex = 24;
            this.label6.Text = "skład (A(x)B(1-x)C(y)D(1-y)";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label7.Location = new System.Drawing.Point(11, 260);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(222, 25);
            this.label7.TabIndex = 25;
            this.label7.Text = "grubość krytyczna: (nm)";
            // 
            // gruboscKrytyczna1
            // 
            this.gruboscKrytyczna1.Location = new System.Drawing.Point(176, 289);
            this.gruboscKrytyczna1.Margin = new System.Windows.Forms.Padding(4);
            this.gruboscKrytyczna1.Name = "gruboscKrytyczna1";
            this.gruboscKrytyczna1.ReadOnly = true;
            this.gruboscKrytyczna1.Size = new System.Drawing.Size(120, 22);
            this.gruboscKrytyczna1.TabIndex = 26;
            // 
            // gruboscKrytyczna2
            // 
            this.gruboscKrytyczna2.Location = new System.Drawing.Point(315, 289);
            this.gruboscKrytyczna2.Margin = new System.Windows.Forms.Padding(4);
            this.gruboscKrytyczna2.Name = "gruboscKrytyczna2";
            this.gruboscKrytyczna2.ReadOnly = true;
            this.gruboscKrytyczna2.Size = new System.Drawing.Size(121, 22);
            this.gruboscKrytyczna2.TabIndex = 27;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label8.Location = new System.Drawing.Point(16, 348);
            this.label8.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(149, 25);
            this.label8.TabIndex = 28;
            this.label8.Text = "temperatura (K)";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label9.Location = new System.Drawing.Point(236, 348);
            this.label9.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(224, 25);
            this.label9.TabIndex = 29;
            this.label9.Text = "liczba wartości własnych";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label10.Location = new System.Drawing.Point(19, 571);
            this.label10.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(76, 25);
            this.label10.TabIndex = 30;
            this.label10.Text = "Ex(VB)";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label11.Location = new System.Drawing.Point(175, 571);
            this.label11.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(77, 25);
            this.label11.TabIndex = 31;
            this.label11.Text = "Ey(CB)";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label12.Location = new System.Drawing.Point(317, 592);
            this.label12.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(203, 25);
            this.label12.TabIndex = 32;
            this.label12.Text = "energia przejścia (eV)";
            // 
            // dlugoscFali
            // 
            this.dlugoscFali.Location = new System.Drawing.Point(321, 681);
            this.dlugoscFali.Margin = new System.Windows.Forms.Padding(4);
            this.dlugoscFali.Name = "dlugoscFali";
            this.dlugoscFali.ReadOnly = true;
            this.dlugoscFali.Size = new System.Drawing.Size(100, 22);
            this.dlugoscFali.TabIndex = 33;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label13.Location = new System.Drawing.Point(321, 654);
            this.label13.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(155, 25);
            this.label13.TabIndex = 34;
            this.label13.Text = "długość fali (nm)";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label14.Location = new System.Drawing.Point(323, 720);
            this.label14.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(157, 25);
            this.label14.TabIndex = 35;
            this.label14.Text = "całka przekrycia ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1224, 802);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.dlugoscFali);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.gruboscKrytyczna2);
            this.Controls.Add(this.gruboscKrytyczna1);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonSaveImage);
            this.Controls.Add(this.energiaPrzejscia);
            this.Controls.Add(this.calkaPrzekrycia);
            this.Controls.Add(this.numericWartosciWlasne);
            this.Controls.Add(this.numericCalka2);
            this.Controls.Add(this.numericCalka1);
            this.Controls.Add(this.numericTemperatura);
            this.Controls.Add(this.boxMaterial2);
            this.Controls.Add(this.boxMaterial1);
            this.Controls.Add(this.numericY2);
            this.Controls.Add(this.numericY1);
            this.Controls.Add(this.numericX2);
            this.Controls.Add(this.numericX1);
            this.Controls.Add(this.numericSzerokosc2);
            this.Controls.Add(this.numericSzerokosc1);
            this.Controls.Add(this.buttonLiczCalki);
            this.Controls.Add(this.buttonStart);
            this.Controls.Add(this.chart);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Struktura A/B/C/A";
            ((System.ComponentModel.ISupportInitialize)(this.chart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericSzerokosc1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericSzerokosc2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericX2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericX1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericY2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericY1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericTemperatura)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCalka2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCalka1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericWartosciWlasne)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataVisualization.Charting.Chart chart;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.Button buttonLiczCalki;
        private System.Windows.Forms.NumericUpDown numericSzerokosc1;
        private System.Windows.Forms.NumericUpDown numericSzerokosc2;
        private System.Windows.Forms.NumericUpDown numericX2;
        private System.Windows.Forms.NumericUpDown numericX1;
        private System.Windows.Forms.NumericUpDown numericY2;
        private System.Windows.Forms.NumericUpDown numericY1;
        private System.Windows.Forms.ComboBox boxMaterial1;
        private System.Windows.Forms.ComboBox boxMaterial2;
        private System.Windows.Forms.NumericUpDown numericTemperatura;
        private System.Windows.Forms.NumericUpDown numericCalka2;
        private System.Windows.Forms.NumericUpDown numericWartosciWlasne;
        private System.Windows.Forms.TextBox calkaPrzekrycia;
        private System.Windows.Forms.TextBox energiaPrzejscia;
        private System.Windows.Forms.NumericUpDown numericCalka1;
        private System.Windows.Forms.Button buttonSaveImage;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox gruboscKrytyczna1;
        private System.Windows.Forms.TextBox gruboscKrytyczna2;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox dlugoscFali;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
    }
}

