#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:	
	wxButton *m_GenBtn = nullptr;
	wxButton *m_bubble = nullptr;
	wxButton *m_quick = nullptr;
	wxButton *m_pyr = nullptr;
	wxButton *m_sel = nullptr;
	wxButton *m_shell = nullptr;
	wxButton *m_merge = nullptr;
	wxTextCtrl *m_txt1 = nullptr;
	wxListBox *m_list1 = nullptr;
	wxSlider *m_size = nullptr;
	wxStaticText *val = nullptr;
	wxStaticText *ShowArr = nullptr;
	wxStaticText *SortArr = nullptr;
	wxString text = "";
	

	void OnButtonCLicked(wxCommandEvent &evt);
	void OnButtonCLicked2(wxCommandEvent &evt);
	void Quick(wxCommandEvent &evt);
	void PyrSortB(wxCommandEvent &evt);
	void OnScroll(wxScrollEvent &evt);
	void SelectionSort(wxCommandEvent &evt);
	void SHellSort(wxCommandEvent &evt);
	void MergeSort(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();
};

