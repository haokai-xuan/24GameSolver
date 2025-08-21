#include "app.h"
#include "mainframe.h"
#include "solver.h"

bool App::OnInit() {
    Solver s;
    MainFrame* mainFrame = new MainFrame("24 Game Solver", s);
    mainFrame->SetClientSize(800, 600);
    mainFrame->SetMinSize(wxSize(800, 600));
    mainFrame->SetMaxSize(wxSize(800, 600));
    mainFrame->Center();
    mainFrame->Show();
    return true;
}

wxIMPLEMENT_APP(App);
