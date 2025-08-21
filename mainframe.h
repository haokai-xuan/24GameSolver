#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/scrolwin.h>
#include <vector>
#include <string>
#include <unordered_set>
#include "solver.h"
using namespace std;

class MainFrame : public wxFrame {
    wxSpinCtrl* num1;
    wxSpinCtrl* num2;
    wxSpinCtrl* num3;
    wxSpinCtrl* num4;
    wxButton* button;

    Solver solver;

    void onBtnClick(wxCommandEvent& e);
    void displaySolutions(const unordered_set<string>& solutions);

    wxDECLARE_EVENT_TABLE();

public:
    MainFrame(const wxString& title, Solver& s);
};

#endif