#pragma once

class CamThread
{
public:
	CamThread(wxFrame* pFrame, wxPanel* pPanel);

	virtual void* Entry();

private:
	wxFrame* m_parent;
	wxPanel* m_targetPanel;

	cv::VideoCapture* cap;
	cv::Mat frame;
	cv::VideoWriter* video_writer;

	bool record; // Helal be

};

