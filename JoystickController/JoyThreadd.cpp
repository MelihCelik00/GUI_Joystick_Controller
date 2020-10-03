#include "JoyThreadd.h"

JoyThreadd::JoyThreadd(wxFrame* pFrame, wxPanel* pPanel) : wxThread(wxTHREAD_DETACHED)
{
	m_parent = pFrame;
	m_targetPanel = pPanel;
	cap = new cv::VideoCapture;
    //capturer = new cvCapturer(this, this->m_panel1);
    //capturer->Run();
}

void* JoyThreadd::Entry()
{	
	cap->open(0);

	while (1)
	{
		cv::Mat cam_frame;

		if (!cap->read(cam_frame))
		{
			wxMessageBox(wxT("This is the message."),wxT("This is the title"), wxICON_ERROR);
			break;
		}
		cv::cvtColor(cam_frame, frame, cv::COLOR_BGR2RGB);
		wxBitmap bitmap = wxBitmap( wxImage(frame.cols, frame.rows, frame.data, true) );
		wxClientDC dc(m_targetPanel);
		dc.DrawBitmap(bitmap, 0, 0, false);
	}
	
	cap->release();
	return nullptr;
}