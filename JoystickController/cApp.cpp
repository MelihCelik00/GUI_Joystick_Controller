#include "cApp.h"

wxIMPLEMENT_APP(cApp);


cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	frame_1 = new cMain();
	frame_1->Show();

	return true;
}

