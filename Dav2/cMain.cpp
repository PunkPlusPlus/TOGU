#include "cMain.h"
#include "alg.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonCLicked)
	EVT_BUTTON(10002, OnButtonCLicked2)	
	EVT_BUTTON(10003, Quick)
	EVT_BUTTON(10004, PyrSortB)
	EVT_BUTTON(10005, SelectionSort)
	EVT_BUTTON(10006, SHellSort)
	EVT_BUTTON(10007, MergeSort)
wxEND_EVENT_TABLE()

int * array; //сортируемый массив
int size;


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Progromir", wxPoint(30, 30), wxSize(800,600))
{
	
	wxFont font(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD, false);
	wxWindow::SetBackgroundColour("#fffff0");
	m_GenBtn = new wxButton(this, 10001, "Get Array", wxPoint(10,10), wxSize(70,35), wxBORDER_NONE);	
	m_bubble = new wxButton(this, 10002, "Bubble", wxPoint(300, 10), wxSize(70, 35));
	m_quick = new wxButton(this, 10003, "Quick", wxPoint(380, 10), wxSize(70, 35));
	m_pyr = new wxButton(this, 10004, "Pyramid", wxPoint(460, 10), wxSize(70, 35));
	m_size = new wxSlider(this, wxID_ANY, 0, 0, 100, wxPoint(150, 10), wxSize(140, 35), wxSL_LABELS);
	m_size->SetFont(font);
	m_sel = new wxButton(this, 10005, "Selection", wxPoint(540, 10), wxSize(70, 35));
	m_shell = new wxButton(this, 10006, "Shell", wxPoint(620, 10), wxSize(70, 35));
	m_merge = new wxButton(this, 10007, "Merge", wxPoint(700, 10), wxSize(70, 35));
}

cMain::~cMain()
{
	
}

void cMain::OnButtonCLicked(wxCommandEvent &evt)
{
	if (ShowArr != nullptr)
	{
		ShowArr->Destroy();
	}
	delete[] array;
	int sizeT = m_size->GetValue();
	size = sizeT;
	int * temp = new int[size];
	temp = GetArr(size);
	array = temp;
	wxString tmp = "";
	for (int i = 0; i < size; i++)
	{		
		tmp += wxString::Format(wxT("%i"), array[i]) + "  ";		
	}
	ShowArr = new wxStaticText(this, wxID_ANY, tmp, wxPoint(10, 110), wxSize(250, 400));
	tmp = "";
}
void cMain::OnButtonCLicked2(wxCommandEvent &evt)
{
	if (SortArr != nullptr)
	{
		SortArr->Destroy();
	}
	int* BubbleArr;
	wxString tmp2 = "";
	BubbleArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		BubbleArr[i] = array[i];
	}
	Bubble(size, BubbleArr);
	for (int i = 0; i < size; i++)
	{
		tmp2 += wxString::Format(wxT("%i"), BubbleArr[i]) + "  ";
	}
	SortArr = new wxStaticText(this, wxID_ANY, tmp2, wxPoint(300, 110), wxSize(250, 400));
	delete[] BubbleArr;
}
void cMain::Quick(wxCommandEvent &evt)
{
	if (SortArr != nullptr)
	{
		SortArr->Destroy();
	}
	int* QuickArr = new int[size];
	wxString tmp2 = "";
	for (int i = 0; i < size; i++)
	{
		QuickArr[i] = array[i];
	}
	QuickS(size, QuickArr);
	for (int i = 0; i < size; i++)
	{
		tmp2 += wxString::Format(wxT("%i"), QuickArr[i]) + "  ";
	}
	SortArr = new wxStaticText(this, wxID_ANY, tmp2, wxPoint(300, 110), wxSize(250, 400));
	delete[] QuickArr;
}

void cMain::PyrSortB(wxCommandEvent &evt)
{
	if (SortArr != nullptr)
	{
		SortArr->Destroy();
	}
	int * PyrArr = new int[size];
	wxString tmp2 = "";
	for (int i = 0; i < size; i++)
	{
		PyrArr[i] = array[i];
	}
	PyrSort(PyrArr, size);
	for (int i = 0; i < size; i++)
	{
		tmp2 += wxString::Format(wxT("%i"), PyrArr[i]) + "  ";
	}
	SortArr = new wxStaticText(this, wxID_ANY, tmp2, wxPoint(300, 110), wxSize(250, 400));
	delete[] PyrArr;
}

void cMain::SelectionSort(wxCommandEvent &evt)
{
	if (SortArr != nullptr)
	{
		SortArr->Destroy();
	}
	int * SelArr = new int[size];
	wxString tmp2 = "";
	for (int i = 0; i < size; i++)
	{
		SelArr[i] = array[i];
	}
	SelectionS(SelArr, size);
	for (int i = 0; i < size; i++)
	{
		tmp2 += wxString::Format(wxT("%i"), SelArr[i]) + "  ";
	}
	SortArr = new wxStaticText(this, wxID_ANY, tmp2, wxPoint(300, 110), wxSize(250, 400));
	delete[] SelArr;
}

void cMain::SHellSort(wxCommandEvent &evt)
{
	if (SortArr != nullptr)
	{
		SortArr->Destroy();
	}
	int * ShellArr = new int[size];
	wxString tmp2 = "";
	for (int i = 0; i < size; i++)
	{
		ShellArr[i] = array[i];
	}
	ShellSort(ShellArr, size);
	for (int i = 0; i < size; i++)
	{
		tmp2 += wxString::Format(wxT("%i"), ShellArr[i]) + "  ";
	}
	SortArr = new wxStaticText(this, wxID_ANY, tmp2, wxPoint(300, 110), wxSize(250, 400));
	delete[] ShellArr;
}

void cMain::MergeSort(wxCommandEvent &evt)
{
	if (SortArr != nullptr)
	{
		SortArr->Destroy();
	}
	int * MergeArr = new int[size];
	wxString tmp3 = "";
	for (int i = 0; i < size; i++)
	{
		MergeArr[i] = array[i];
	}
	merge(MergeArr, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		tmp3 += wxString::Format(wxT("%i"), MergeArr[i]) + "  ";
	}
	SortArr = new wxStaticText(this, wxID_ANY, tmp3, wxPoint(300, 110), wxSize(250, 400));
	delete[] MergeArr;
}
