#include "CamThread.h"

CamThread::CamThread(wxFrame* pFrame, wxPanel* pPanel) : wxThread(wxTHREAD_DETACHED)
{
	m_parent = pFrame;
	m_targetPanel = pPanel;
	cap = new cv::VideoCapture;

	video_writer = new cv::VideoWriter("recorded.avi",cv::CV_FOURCC('M','J','P','G'),30, cv::Size(640,480));
	record = false;

    //capturer = new cvCapturer(this, this->m_panel1);
    //capturer->Run();
}

void* CamThread::Entry()
{
	cap->open(0);

	while (1)
	{
		cv::Mat cam_frame;

		if (!cap->read(cam_frame))
		{
			wxMessageBox(wxT("Camera is not opened"),wxT("Error lol :)"), wxICON_ERROR);
			break;
		}

		cv::cvtColor(cam_frame, frame, cv::COLOR_BGR2RGB);
		wxBitmap bitmap = wxBitmap( wxImage(frame.cols, frame.rows, frame.data, true) );
		wxClientDC dc(m_targetPanel);
		dc.DrawBitmap(bitmap, 0, 0, false);

		if(record)
		{
			video_writer->write(cam_frame);
		}

	}
	
	cap->release();
	return nullptr;
}