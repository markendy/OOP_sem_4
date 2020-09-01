#include "MyForm.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

namespace Project2 {
	
	void MyForm::Start(int n_) {
		mas = new double [6];
		tg1 = 0;
		tg2 = 0;
		tg3 = 0;
		tk1 = 0;
		tk2 = 0;
		tk3 = 0;
		pogr = 0;
		m = 0;
		time_test = 0;
		x = 0;
		y = 0;
		button_exec->Text = "execude";
		n = n_;
		ch1 = chart1;
		xm = this->GetFEX();
		ym = this->GetFEY();
		xn = this->GetFGX();
		yn = this->GetFFY();
		mas[0] = 0; mas[1]=0;
		mas[2] = 0; mas[3] = 0;
		mas[4] = 0; mas[5] = 0;
		CalcMN();
		CalcTgF();
		CalcK();
	}
	//рандом
	double MyForm::fRand(double fMin, double fMax)
	{
		double f = (double)rand() / RAND_MAX;
		return fMin + f * (fMax - fMin);
	}
	//основной
	double MyForm::Calc() {
		const double PI = 3.141592653589793238463;
		auto rnd = gcnew Random();
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		clock_t time;
		time = clock();
		for (int i = 0; i <= n; i++) {
			x = fRand(xn, xm);
			y = fRand(yn, ym);
			if (Cheack()) {
				m++;
			}
		}
		double t_M = m;
		time = clock() - time;
		time_test = static_cast<float>(time) / CLOCKS_PER_SEC;
		double temp1 = ((float)xm - (float)xn)*((float)ym - (float)yn);
		double temp2 = (float)t_M / (float)n;
		pogr = CalcPogr(temp1 * temp2);
		Draw();
		return temp1 * temp2;
	}
	double MyForm::CalcPogr(double temp) {
		return abs((GetPloshad() - temp) * 100 / (temp));
	}
	double MyForm::GetPloshad() {
		double ge = GetLenght(mas[0], mas[1], mas[2], mas[3]);
		double ef = GetLenght(mas[2], mas[3], mas[4], mas[5]);
		double gf = GetLenght(mas[0], mas[1], mas[4], mas[5]);
		return sqrt(Perp()*(Perp() - ge)*(Perp() - ef)*(Perp() - gf));
	}
	double MyForm::Perp() {
		double s = GetLenght(mas[0], mas[1], mas[2], mas[3]);
		s += GetLenght(mas[2], mas[3], mas[4], mas[5]);
		s += GetLenght(mas[0], mas[1], mas[4], mas[5]);
		return 0.5*s;
	}
	double MyForm::GetLenght(double x1, double y1, double x2, double y2) {
		return sqrt(pow((x2 - x1), 2) + (pow((y2 - y1), 2)));
	}
	void MyForm::Draw() {
		ch1->Series[0]->Points->Clear();
		ch1->Series[1]->Points->Clear();
		ch1->Series[2]->Points->Clear();
		ch1->Series[0]->Points->AddXY(round(mas[0] * 1000) / 1000, round(mas[1] * 1000) / 1000);
		ch1->Series[0]->Points->AddXY(round(mas[2] * 1000) / 1000, round(mas[3] * 1000) / 1000);
		ch1->Series[1]->Points->AddXY(round(mas[2] * 1000) / 1000, round(mas[3] * 1000) / 1000);
		ch1->Series[1]->Points->AddXY(round(mas[4] * 1000) / 1000, round(mas[5] * 1000) / 1000);
		ch1->Series[2]->Points->AddXY(round(mas[0] * 1000) / 1000, round(mas[1] * 1000) / 1000);
		ch1->Series[2]->Points->AddXY(round(mas[4] * 1000) / 1000, round(mas[5] * 1000) / 1000);
	}
	//края прямоугольника
	void MyForm::CalcMN() {
		mas[0] = GetFGX(); mas[1] = GetFGY();
		mas[2] = GetFEX(), mas[3] = GetFEY();
		mas[4] = GetFFX(); mas[5] = GetFFY();
	}
	float MyForm::GetTimeTest() {
		return time_test;
	}
	double MyForm::GetPogr() {
		return pogr;
	}
	int MyForm::GetM() {
		return m;
	}
	//тангенсы для k
	void MyForm::CalcTgF() {
		double tempGx = mas[0];
		double tempEx = mas[2];
		double tempFx = mas[4];
		double tempGy = mas[1];
		double tempEy = mas[3];
		double tempFy = mas[5];
		tg1 = (tempEy - tempGy) / (tempEx - tempGx);
		tg2 = (tempEy - tempFy) / (tempEx - tempFx);
		tg3 = (tempFy - tempGy) / (tempFx - tempGx);
	}
	//коэф k
	void MyForm::CalcK() {
		tk1 = mas[1] - mas[0]*tg1;
		tk2 = mas[5] - tg2 * mas[4];
		tk3 = mas[5] - mas[4]*tg3;
	}
	//проверка
	bool MyForm::Cheack() {
		return(y <= tg1 * x + tk1 && y >= tg2 * x + tk2 && y >= tg3 * x + tk3);
	}
	
	bool MyForm::Check() {
		try {
			double temp_gx = Double::Parse(this->textBox_gx->Text);
			double temp_gy = Double::Parse(this->textBox_gy->Text);
			double temp_ex = Double::Parse(this->textBox_ex->Text);
			double temp_ey = Double::Parse(this->textBox_ey->Text);
			double temp_fx = Double::Parse(this->textBox_fx->Text);
			double temp_fy = Double::Parse(this->textBox_fy->Text);
			if (temp_ex < temp_gx || temp_fx < temp_gx || temp_ex < temp_fx || temp_ey < temp_gy || temp_gy < temp_fy || temp_ey < temp_fy) {
				throw gcnew Exception;
			}
			return true;
		}
		catch (...) {
			button_exec->Text = "Error";
			return false;
		}
	}
	double MyForm::GetFGX() {
		return Double::Parse(this->textBox_gx->Text);
	}
	double MyForm::GetFGY() {
		return Double::Parse(this->textBox_gy->Text);
	}
	double MyForm::GetFEX() {
		return Double::Parse(this->textBox_ex->Text);
	}
	double MyForm::GetFEY() {
		return Double::Parse(this->textBox_ey->Text);
	}
	double MyForm::GetFFX() {
		return Double::Parse(this->textBox_fx->Text);
	}
	double MyForm::GetFFY() {
		return Double::Parse(this->textBox_fy->Text);
	}
	System::Void MyForm::button_pr_Click(System::Object^  sender, System::EventArgs^  e) {
		textBox_gx->Text = "0";
		textBox_gy->Text = "5";
		textBox_ex->Text = "6";
		textBox_ey->Text = "6";
		textBox_fx->Text = "4";
		textBox_fy->Text = "0";
	}
	System::Void MyForm::button_exec_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Check()) {
			//Очистка строк и столбцов таблицы
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();

			//Создание столбцов
			DataGridViewTextBoxColumn ^firstColumn = gcnew DataGridViewTextBoxColumn();
			firstColumn->HeaderText = "№";
			firstColumn->Name = "№";
			DataGridViewTextBoxColumn ^secondColumn = gcnew DataGridViewTextBoxColumn();
			secondColumn->HeaderText = "N";
			secondColumn->Name = "N";
			DataGridViewTextBoxColumn ^thirdColumn = gcnew DataGridViewTextBoxColumn();
			thirdColumn->Name = "N попало";
			thirdColumn->HeaderText = "N попало";
			DataGridViewTextBoxColumn ^fourColumn = gcnew DataGridViewTextBoxColumn();
			fourColumn->Name = "S";
			fourColumn->HeaderText = "S";
			DataGridViewTextBoxColumn ^fifsColumn = gcnew DataGridViewTextBoxColumn();
			fifsColumn->Name = "Погрешность, %";
			fifsColumn->HeaderText = "Погрешность, %";
			DataGridViewTextBoxColumn ^sixColumn = gcnew DataGridViewTextBoxColumn();
			sixColumn->Name = "Время работы, мс";
			sixColumn->HeaderText = "Время работы, мс";

			//Добавление столбцов
			dataGridView1->Columns->Add(firstColumn);
			dataGridView1->Columns->Add(secondColumn);
			dataGridView1->Columns->Add(thirdColumn);
			dataGridView1->Columns->Add(fourColumn);
			dataGridView1->Columns->Add(fifsColumn);
			dataGridView1->Columns->Add(sixColumn);

			//Переменнняе для ячеек и строки таблицы
			DataGridViewCell ^firstCell;
			DataGridViewCell ^secondCell;
			DataGridViewCell ^thirdCell;
			DataGridViewCell ^fourCell;
			DataGridViewCell ^fifsCell;
			DataGridViewCell ^sixCell;
			DataGridViewRow ^row;

			int n = 1000;
			for (int i = 0; i < 5; ++i, n*=10) {
				Start(n);
				//Создание ячеек для первой строки
				firstCell = gcnew DataGridViewTextBoxCell();
				secondCell = gcnew DataGridViewTextBoxCell();
				thirdCell = gcnew DataGridViewTextBoxCell();
				fourCell = gcnew DataGridViewTextBoxCell();
				fifsCell = gcnew DataGridViewTextBoxCell();
				sixCell = gcnew DataGridViewTextBoxCell();
				row = gcnew DataGridViewRow();
				firstCell->Value = i + 1;
				secondCell->Value = n;
				fourCell->Value = (round(Calc() * 1000) / 1000).ToString();
				thirdCell->Value = GetM();
				fifsCell->Value = (round(GetPogr() * 1000) / 1000).ToString();
				sixCell->Value = GetTimeTest().ToString();
				row->Cells->AddRange(firstCell, secondCell, thirdCell, fourCell, fifsCell, sixCell);
				dataGridView1->Rows->Add(row);
				textBox_out->Text = (round(GetPloshad() * 1000) / 1000).ToString();
			}
		}		
	}
}