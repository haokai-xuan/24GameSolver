#include "mainframe.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

enum IDs {
    BUTTON_ID = 2
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::onBtnClick)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, Solver& s)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), solver{s}
{
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);

    num1 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 25), wxSP_WRAP, 1, 10, 1);
    num2 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 25), wxSP_WRAP, 1, 10, 1);
    num3 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 25), wxSP_WRAP, 1, 10, 1);
    num4 = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 25), wxSP_WRAP, 1, 10, 1);

    topSizer->AddStretchSpacer(1);
    topSizer->Add(num1, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);
    topSizer->Add(num2, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);
    topSizer->Add(num3, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);
    topSizer->Add(num4, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);

    button = new wxButton(this, BUTTON_ID, "Go", wxDefaultPosition, wxSize(80, 25));
    topSizer->Add(button, 0, wxALL, 5);
    topSizer->AddStretchSpacer(1);

    this->SetSizer(topSizer);
    this->Layout();
}

void MainFrame::onBtnClick(wxCommandEvent& e) {

}

void MainFrame::displaySolutions(const std::unordered_set<std::string>& solutions)
{

}
