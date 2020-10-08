#ifndef __CMAIN_H__
#define __CMAIN_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/frame.h>

#include <string.h>
#include "CamThread.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class cMain
///////////////////////////////////////////////////////////////////////////////
class cMain : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_camPanel;
		wxButton* m_camButton;
		wxButton* m_recordButton;
		wxButton* m_joyButton;
		wxStaticText* m_cameraLabel;
		wxStaticText* m_recordLabel;
		wxStaticText* m_joyLabel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void start_cam( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_record( wxCommandEvent& event ) { event.Skip(); }
		virtual void control_joy( wxCommandEvent& event ) { event.Skip(); }
		
		// threads
		CamThread* camTh; 
		
		bool cam_online;

	public:
		
		cMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~cMain();


	
};

#endif //__NONAME_H__
