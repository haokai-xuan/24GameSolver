#include "app.h"
#include "mainframe.h"

bool App::OnInit() {
    MainFrame* mainframe = new MainFrame("24 Game Solver");
    mainframe->Show();
    return true;
}

wxIMPLEMENT_APP(App);
