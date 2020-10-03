#pragma once

class JoyThreadd
{
public:
	JoyThreadd(wxFrame* pFrame, wxPanel* pPanel);

	virtual void* Entry();

private:
	wxFrame* m_parent;
	wxPanel* m_targetPanel;

	cv::VideoCapture* cap;
	cv::Mat frame;

};

