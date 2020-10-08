#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001,OnButtonClicked)
	EVT_BUTTON(10002,OnCheckJoy)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Joystick Controller", wxPoint(30,30), wxSize(800,600)) {
	// Text section
	button1 = new wxButton(this, 10001, "Click to send messages!", wxPoint(10, 10), wxSize(200, 50));
	textController1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10,80), wxSize(300, 40));
	list1 = new wxListBox(this, wxID_ANY, wxPoint(10,140), wxSize(300,100));
	// Text section ends

	// Joystick
	checkJoyButton1 = new wxButton(this, 10002, "Check Joystick", wxPoint(220,10), wxSize(90, 50)); // Joystick check event
	
	//////////FIX BELOW//////////

	/*isJoyOk = {true: "Good", false: "Fail"}[stick.IsOk() == true];
	staticText1 = new wxStaticText(this, wxID_ANY, "Joystick Status: ", wxPoint(350,10), wxSize(80,40));
	staticText2 = new wxStaticText(this, 10003, isJoyOk);*/  
}

cMain::~cMain() {
	
}

void cMain::OnButtonClicked(wxCommandEvent& ref) {
	list1->AppendString(textController1->GetValue()); // Push messages into the listBox
};

void cMain::OnCheckJoy(wxCommandEvent& refJ) {
	wxJoystick stick(wxJOYSTICK1);
	if (!stick.IsOk())
	{
		wxMessageBox(wxT("No joystick detected!"));
	}
	else
	{
		wxMessageBox(wxT("Joystick is connected!"));
	}

}