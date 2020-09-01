#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}




	protected:









	protected:







	private: System::Windows::Forms::Button^  button_exec;


	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  textBox_out;




	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  button_pr;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox_fy;
	private: System::Windows::Forms::TextBox^  textBox_fx;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox_ey;
	private: System::Windows::Forms::TextBox^  textBox_ex;
	private: System::Windows::Forms::TextBox^  textBox_gy;
	private: System::Windows::Forms::TextBox^  textBox_gx;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_exec = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox_out = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_pr = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox_fy = (gcnew System::Windows::Forms::TextBox());
			this->textBox_fx = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox_ey = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ex = (gcnew System::Windows::Forms::TextBox());
			this->textBox_gy = (gcnew System::Windows::Forms::TextBox());
			this->textBox_gx = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_exec
			// 
			this->button_exec->Location = System::Drawing::Point(23, 214);
			this->button_exec->Name = L"button_exec";
			this->button_exec->Size = System::Drawing::Size(102, 23);
			this->button_exec->TabIndex = 7;
			this->button_exec->Text = L"execude";
			this->button_exec->UseVisualStyleBackColor = true;
			this->button_exec->Click += gcnew System::EventHandler(this, &MyForm::button_exec_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(23, 326);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(653, 214);
			this->dataGridView1->TabIndex = 11;
			// 
			// textBox_out
			// 
			this->textBox_out->Location = System::Drawing::Point(23, 188);
			this->textBox_out->Name = L"textBox_out";
			this->textBox_out->ReadOnly = true;
			this->textBox_out->Size = System::Drawing::Size(102, 20);
			this->textBox_out->TabIndex = 8;
			this->textBox_out->Text = L"Площадь";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(218, 20);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Name = L"Series2";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Name = L"Series3";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 16;
			this->chart1->Text = L"chart1";
			// 
			// button_pr
			// 
			this->button_pr->Location = System::Drawing::Point(23, 145);
			this->button_pr->Name = L"button_pr";
			this->button_pr->Size = System::Drawing::Size(102, 35);
			this->button_pr->TabIndex = 34;
			this->button_pr->Text = L"Контрольный пример";
			this->button_pr->UseVisualStyleBackColor = true;
			this->button_pr->Click += gcnew System::EventHandler(this, &MyForm::button_pr_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(74, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 13);
			this->label5->TabIndex = 33;
			this->label5->Text = L"Fy";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 103);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 13);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Fx";
			// 
			// textBox_fy
			// 
			this->textBox_fy->Location = System::Drawing::Point(77, 119);
			this->textBox_fy->Name = L"textBox_fy";
			this->textBox_fy->Size = System::Drawing::Size(48, 20);
			this->textBox_fy->TabIndex = 31;
			this->textBox_fy->Text = L"0";
			// 
			// textBox_fx
			// 
			this->textBox_fx->Location = System::Drawing::Point(23, 119);
			this->textBox_fx->Name = L"textBox_fx";
			this->textBox_fx->Size = System::Drawing::Size(48, 20);
			this->textBox_fx->TabIndex = 30;
			this->textBox_fx->Text = L"4";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(74, 61);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(19, 13);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Ey";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(20, 61);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(19, 13);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Ex";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(74, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(20, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Gy";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(23, 19);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 13);
			this->label10->TabIndex = 26;
			this->label10->Text = L"Gx";
			// 
			// textBox_ey
			// 
			this->textBox_ey->Location = System::Drawing::Point(77, 77);
			this->textBox_ey->Name = L"textBox_ey";
			this->textBox_ey->Size = System::Drawing::Size(48, 20);
			this->textBox_ey->TabIndex = 25;
			this->textBox_ey->Text = L"6";
			// 
			// textBox_ex
			// 
			this->textBox_ex->Location = System::Drawing::Point(23, 77);
			this->textBox_ex->Name = L"textBox_ex";
			this->textBox_ex->Size = System::Drawing::Size(48, 20);
			this->textBox_ex->TabIndex = 24;
			this->textBox_ex->Text = L"6";
			// 
			// textBox_gy
			// 
			this->textBox_gy->Location = System::Drawing::Point(77, 35);
			this->textBox_gy->Name = L"textBox_gy";
			this->textBox_gy->Size = System::Drawing::Size(48, 20);
			this->textBox_gy->TabIndex = 23;
			this->textBox_gy->Text = L"5";
			// 
			// textBox_gx
			// 
			this->textBox_gx->Location = System::Drawing::Point(23, 35);
			this->textBox_gx->Name = L"textBox_gx";
			this->textBox_gx->Size = System::Drawing::Size(48, 20);
			this->textBox_gx->TabIndex = 22;
			this->textBox_gx->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 552);
			this->Controls->Add(this->button_pr);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox_fy);
			this->Controls->Add(this->textBox_fx);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox_ey);
			this->Controls->Add(this->textBox_ex);
			this->Controls->Add(this->textBox_gy);
			this->Controls->Add(this->textBox_gx);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button_exec);
			this->Controls->Add(this->textBox_out);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"OOP_PROC";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public:
		bool Check();
		double GetFGX();
		double GetFGY();
		double GetFEX();
		double GetFEY();
		double GetFFX();
		double GetFFY();
	private:
		System::Void button_exec_Click(System::Object^  sender, System::EventArgs^  e);

	private:
		double * mas;
		double xm, xn, ym, yn, n, x, y, tg1, tg2, tg3, tk1, tk2, tk3, pogr;
		int m;
		float time_test;
		Chart^ ch1;
	public:
		double GetLenght(double, double, double, double);
		double Perp();
		double CalcPogr(double);
		bool Cheack();
		void Start(int);
		double Calc();
		double fRand(double, double);
		void CalcTgF();
		void CalcMN();
		void CalcK();
		float GetTimeTest();
		double GetPogr();
		int GetM();
		double GetPloshad();
		void Draw();
	private: System::Void button_pr_Click(System::Object^  sender, System::EventArgs^  e);
};
}
#pragma endregion