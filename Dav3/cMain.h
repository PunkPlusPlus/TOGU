#pragma once
#include "wx/wx.h"
#include "wx/statline.h"
#include <wx/valnum.h>
#include <string>



class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton * choise_1 = nullptr;
	wxButton * choise_2 = nullptr;
	wxButton * m_GenBtn = nullptr;
	wxButton * find = nullptr;
	wxStaticLine * del = nullptr;
	wxStaticLine * del2 = nullptr;
	wxStaticText * rand = nullptr;
	wxStaticText * tit = nullptr;
	wxStaticText * result = nullptr;
	wxStaticText * sArr = nullptr;
	wxTextCtrl * txt = nullptr;
	wxString UsrInp = "";
	wxStaticText * warning = nullptr;
	wxRadioButton * s1 = nullptr;
	wxRadioButton * s2 = nullptr;
	wxRadioButton * s3 = nullptr;
	
	
	wxTextCtrl * inp = nullptr;
	wxStaticText * question = nullptr;


	void choise_1_act(wxCommandEvent &evt);
	void tst(wxCommandEvent &evt);
	void Find(wxCommandEvent &evt);
	void tst2(wxCommandEvent &evt);	
	

	wxDECLARE_EVENT_TABLE();
};

