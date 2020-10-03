#pragma once

#include "wx/wx.h"
#include "wx/sound.h"
#include "wx/joystick.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:

	wxButton* button1 = nullptr;
	wxTextCtrl* textController1 = nullptr;
	wxListBox* list1 = nullptr;

	wxButton* checkJoyButton1 = nullptr;

	int textFieldWidth = 10;
	int textFieldHeight = 20;
	wxButton** btn;

	void OnButtonClicked(wxCommandEvent &refEvent);

	void OnCheckJoy(wxCommandEvent &refJoy);

	wxDECLARE_EVENT_TABLE();

public:
	bool isJoyOk;

	wxStaticText* staticText1 = nullptr;
	wxStaticText* staticText2 = nullptr;
	
};