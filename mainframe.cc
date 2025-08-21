#include "mainframe.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
using namespace std;

enum IDs
{
    BUTTON_ID = 2
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::onBtnClick)
        wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString &title, Solver &s) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), solver{s} {
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);

    num1 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 20), wxSP_WRAP, 1, 10, 1);
    num2 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 20), wxSP_WRAP, 1, 10, 1);
    num3 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 20), wxSP_WRAP, 1, 10, 1);
    num4 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 20), wxSP_WRAP, 1, 10, 1);

    topSizer->AddStretchSpacer(1);
    topSizer->Add(num1, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);
    topSizer->Add(num2, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);
    topSizer->Add(num3, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);
    topSizer->Add(num4, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);

    button = new wxButton(this, BUTTON_ID, "Go", wxDefaultPosition, wxSize(80, 20));
    topSizer->Add(button, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);

    scrollWin = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(800, 400), wxVSCROLL);
    scrollWin->SetScrollRate(5, 5);

    gridSizer = new wxGridSizer(0, 5, 10, 10);
    scrollWin->SetSizer(gridSizer);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(topSizer, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(scrollWin, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(mainSizer);
    this->Layout();
}

void MainFrame::onBtnClick(wxCommandEvent &e) {
    int a = num1->GetValue();
    int b = num2->GetValue();
    int c = num3->GetValue();
    int d = num4->GetValue();

    unordered_set<string> solutions = solver.solveAll({a, b, c, d});
    displaySolutions(solutions);
}

void MainFrame::displaySolutions(const ::unordered_set<::string> &solutions) {
    scrollWin->Freeze();

    gridSizer->Clear(true);

    wxStaticText* countLabel = new wxStaticText(scrollWin, wxID_ANY,
        "Solutions: " + wxString::Format("%zu", solutions.size()));
    gridSizer->Add(countLabel, 0, wxALL, 5);

    for (const auto& s : solutions) {
        wxStaticText* label = new wxStaticText(scrollWin, wxID_ANY, s);
        gridSizer->Add(label, 0, wxALL, 5);
    }

    scrollWin->Layout();
    scrollWin->FitInside();
    scrollWin->Thaw();
}
