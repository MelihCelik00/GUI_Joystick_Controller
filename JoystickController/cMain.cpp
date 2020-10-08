///////////////////////////////////////////////////////////////////////////
// 
// Authors: Berke Algul & Melih Safa Celik
// Last edit: Oct 8, 2020
// 
///////////////////////////////////////////////////////////////////////////

#include "cMain.h"

///////////////////////////////////////////////////////////////////////////

cMain::cMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_camPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 640,480 ), wxTAB_TRAVERSAL );
	bSizer1->Add( m_camPanel, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_camButton = new wxButton( this, wxID_ANY, wxT("Start Camera"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	bSizer3->Add( m_camButton, 0, wxALL, 5 );
	
	m_recordButton = new wxButton( this, wxID_ANY, wxT("Start/Stop Recording"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_recordButton, 0, wxALL, 5 );
	
	m_joyButton = new wxButton( this, wxID_ANY, wxT("Check Joy Status"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_joyButton, 0, wxALL, 5 );
	
	m_cameraLabel = new wxStaticText( this, wxID_ANY, wxT("Camera Status: Close"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cameraLabel->Wrap( -1 );
	bSizer3->Add( m_cameraLabel, 0, wxALL, 5 );
	
	m_recordLabel = new wxStaticText( this, wxID_ANY, wxT("Recording: False"), wxDefaultPosition, wxDefaultSize, 0 );
	m_recordLabel->Wrap( -1 );
	bSizer3->Add( m_recordLabel, 0, wxALL, 5 );
	
	m_joyLabel = new wxStaticText( this, wxID_ANY, wxT("JoyStatus : okay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_joyLabel->Wrap( -1 );
	bSizer3->Add( m_joyLabel, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_camButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cMain::start_cam ), NULL, this );
	m_recordButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cMain::toggle_record ), NULL, this );
	m_joyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cMain::control_joy ), NULL, this );

	//create threads
	camTh = new CamThread(this, this->m_camPanel);

	cam_online = false;
}

cMain::~cMain()
{
	// Disconnect Events
	m_camButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cMain::start_cam ), NULL, this );
	m_recordButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cMain::toggle_record ), NULL, this );
	m_joyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cMain::control_joy ), NULL, this );
	
}

cMain::toggle_record( wxCommandEvent& event )
{
	camTh->record = !camTh->record;
	m_recordLabel.SetLabel("Recording: " + std::to_string(camTh->record));
}

cMain::start_cam( wxCommandEvent& event )
{
	camTh->Run();
	m_cameraLabel->SetLabel("Camera Status Online");
	cam_online = true;
}

cMain::control_joy(wxCommandEvent& event ) {
	wxJoystick stick(wxJOYSTICK1);
	if (!stick.IsOk())
	{
		wxMessageBox(wxT("No joystick detected!"));
	}
	else
	{
		wxMessageBox(wxT("Joystick is connected."));
	} // thx m8
} //niceee