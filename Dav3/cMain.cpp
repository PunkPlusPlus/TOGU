#include "cMain.h"
#include "alg.h"
#include <chrono>

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, choise_1_act)
	EVT_BUTTON(10002, tst)
	EVT_BUTTON(10003, Find)
	EVT_BUTTON(10004, tst2)
wxEND_EVENT_TABLE()

int * array; // Изначальный массив чисел
int * SortedArr; // отсортированный массив, в котором ищем




cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Progromir", wxPoint(30, 30), wxSize(800, 700))
{

	wxFont font(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD, false);
	wxWindow::SetBackgroundColour("#f5f5f5");
	choise_1 = new wxButton(this, 10001, "Случайные числа", wxPoint(10, 10), wxSize(120, 40));
	choise_2 = new wxButton(this, 10002, "Ввети текст", wxPoint(10, 350), wxSize(100, 40));
	del = new wxStaticLine(this, wxID_ANY, wxPoint(450, 1), wxSize(1, 800));
	del2 = new wxStaticLine(this, wxID_ANY, wxPoint(1, 320), wxSize(450, 1));
	
	
	
	//tit = new wxStaticText(this, wxID_ANY, "Для алгоритмов Кнута-Морриса-Прата и Бойера-Мура", wxPoint(10, 330));
	
}

cMain::~cMain()
{

}

void cMain::choise_1_act(wxCommandEvent &evt)
{
	if (warning != nullptr)
	{
		warning->Destroy();
	}
	if (rand != nullptr)
	{
		rand->Destroy();
	}
	if (find != nullptr)
	{
		find->Destroy();
	}
	if (inp != nullptr)
	{
		inp->Destroy();
	}
	if (s1 != nullptr && s2 != nullptr)
	{
		s1->Destroy();
		s2->Destroy();		
	}
	if (s3!=nullptr)
	{
		s3->Destroy();
	}
	if (question != nullptr)
	{
		question->Destroy();
	}
	s1 = new wxRadioButton(this, wxID_ANY, "Линейный поиск", wxPoint(500, 10));
	s2 = new wxRadioButton(this, wxID_ANY, "Бинарный поиск", wxPoint(640, 10));
	s3 = new wxRadioButton();
	question = new wxStaticText(this, wxID_ANY, "Что найти?", wxPoint(500, 50));
	inp = new wxTextCtrl(this, wxID_ANY, "", wxPoint(500, 80), wxSize(100, 20));
	find = new wxButton(this, 10003, "Найти", wxPoint(610, 79));
	int * temp = new int[100];
	int size = 100;	
	array = GetArr(size);
	wxString tmp = "";
	
	SortedArr = new int[100];
	for (int i = 0; i < 100; i++)
	{
		SortedArr[i] = array[i];
	}
	sort(100, SortedArr);
	for (int i = 0; i < 100; i++)
	{
		tmp += wxString::Format(wxT("%i"), SortedArr[i]) + "  ";
	}
	sArr = new wxStaticText(this, wxID_ANY, tmp, wxPoint(10, 70), wxSize(250, 250));
	tmp = "";
	warning = new wxStaticText(this, wxID_ANY, "", wxPoint(500, 300));
}

void cMain::Find(wxCommandEvent &evt)
{	//заранее сортируем массив
	sort(100, array);	
	wxString temp = "";
	
	if (result != nullptr)
	{
		result->Destroy();
	}
	
	if (!wxAtoi(inp->GetValue()) || inp->GetValue() == "")
	{
		inp->SetValue("0");
	}
	int key = wxAtoi(inp->GetValue());
	int ind;
	if (s1->GetValue())
	{
		ind = linear(array, key);
		if (ind == -1)
		{
			temp = "Ваш элемент не найден!";
		}
		else
		{
			ind++;
			temp = "Ваш элемент найден под порядковым номером " + wxString::Format(wxT("%i"), ind);;
		}
		
		result = new wxStaticText(this, wxID_ANY, temp, wxPoint(480, 150));
	}
	else if (s2->GetValue())
	{
		ind = birnary(array, key);
		if (ind == -1)
		{
			temp = "Ваш элемент не найден!";
		}
		else
		{
			ind++;
			temp = "Ваш элемент найден под порядковым номером " + wxString::Format(wxT("%i"), ind);;
		}
		result = new wxStaticText(this, wxID_ANY, temp, wxPoint(480, 150));
	}
	else
	{
		result = new wxStaticText(this, wxID_ANY, "Вы не выбрали метод поиска!", wxPoint(500, 150));
	}
	
	
}

void cMain::tst(wxCommandEvent &evt)
{
	if (find != nullptr)
	{
		find->Destroy();
	}
	if (inp != nullptr)
	{
		inp->Destroy();
	}
	if (txt != nullptr)
	{
		txt->Destroy();
	}
	if (s1 != nullptr && s2 != nullptr && s3 != nullptr)
	{
		s1->Destroy();
		s2->Destroy();
		s3->Destroy();
	}
	if (question != nullptr)
	{
		question->Destroy();
	}

	s1 = new wxRadioButton(this, wxID_ANY, "Кнута-Морриса-Прата", wxPoint(500, 10));
	s2 = new wxRadioButton(this, wxID_ANY, "Бойера-Мура", wxPoint(660, 10));
	s3 = new wxRadioButton(this, wxID_ANY, "Линейный поиск", wxPoint(500, 30));
	question = new wxStaticText(this, wxID_ANY, "Что найти?", wxPoint(500, 70));
	inp = new wxTextCtrl(this, wxID_ANY, "", wxPoint(500, 100), wxSize(100, 20));
	find = new wxButton(this, 10004, "Найти", wxPoint(610, 99));
	txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 400), wxSize(350, 200), wxTE_MULTILINE);
	warning = new wxStaticText(this, wxID_ANY, "В целях более стабильной работы используйте латиницу.", wxPoint(455, 300));
}
void cMain::tst2(wxCommandEvent &evt)
{
	if (inp->GetValue()=="")
	{
		inp->SetValue("test");
	}
	if (inp->GetValue().length() < 2)
	{
		inp->SetValue("test");
	}
	if (result != nullptr)
	{
		result->Destroy();
	}
	UsrInp = txt->GetValue();
	wxString temp = "";
	int res;
	std::string key = std::string(inp->GetValue().mb_str());
	std::string str = std::string(UsrInp.mb_str());
	if (s1->GetValue())
	{
		res = KnMrPr(key, str);
		if (res == -1)
		{
			temp = "Совпадений не найдено!";
			result = new wxStaticText(this, wxID_ANY, temp, wxPoint(500, 150));
		}
		
		else
		{
			temp = "Есть совпадение на " + wxString::Format(wxT("%i"), res) + " позиции.";
			result = new wxStaticText(this, wxID_ANY, temp, wxPoint(500, 150));
		}
	}
	
	else if (s2->GetValue())
	{
		res = BMSearch(str, key);
		if (res == -1)
		{
			temp = "Совпадений не найдено!";
			result = new wxStaticText(this, wxID_ANY, temp, wxPoint(500, 150));
		}
		else
		{
			temp = "Есть совпадение на " + wxString::Format(wxT("%i"), res) + " позиции.";
			result = new wxStaticText(this, wxID_ANY, temp, wxPoint(500, 150));
		}
	}
	else if (s3->GetValue())
	{
		res = LinStr(str, key);
		if (res == -1)
		{
			temp = "Совпадений не найдено!";
			result = new wxStaticText(this, wxID_ANY, temp, wxPoint(500, 150));
		}
		else
		{
			temp = "Есть совпадение на " + wxString::Format(wxT("%i"), res) + " позиции.";
			result = new wxStaticText(this, wxID_ANY, temp, wxPoint(500, 150));
		}
	}
	else
	{
		result = new wxStaticText(this, wxID_ANY, "Вы не выбрали метод поиска!", wxPoint(500, 150));
	}
	
}
