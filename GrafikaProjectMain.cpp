/***************************************************************
 * Name:      GrafikaProjectMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2017-06-10
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "GrafikaProjectMain.h"
#include <wx/msgdlg.h>
#include "fromFile.h"
#include <vector>
#include <fstream>

//(*InternalHeaders(GrafikaProjectDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GrafikaProjectDialog)
const long GrafikaProjectDialog::ID_BUTTON1 = wxNewId();
const long GrafikaProjectDialog::ID_STATICTEXT1 = wxNewId();
const long GrafikaProjectDialog::ID_TEXTCTRL1 = wxNewId();
const long GrafikaProjectDialog::ID_STATICTEXT2 = wxNewId();
const long GrafikaProjectDialog::ID_TEXTCTRL2 = wxNewId();
const long GrafikaProjectDialog::ID_STATICTEXT3 = wxNewId();
const long GrafikaProjectDialog::ID_TEXTCTRL3 = wxNewId();
const long GrafikaProjectDialog::ID_SLIDER1 = wxNewId();
const long GrafikaProjectDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GrafikaProjectDialog,wxDialog)
    //(*EventTable(GrafikaProjectDialog)
    //*)
END_EVENT_TABLE()

GrafikaProjectDialog::GrafikaProjectDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GrafikaProjectDialog)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer9;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    LoadButton = new wxButton(this, ID_BUTTON1, _("Load File"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(LoadButton, 1, wxALL|wxALIGN_TOP, 5);
    BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Floating Vector"));
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer7->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    xText = new wxTextCtrl(this, ID_TEXTCTRL1, _("1"), wxDefaultPosition, wxSize(40,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer7->Add(xText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer6->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    yText = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(40,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer6->Add(yText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Z"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer8->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    zText = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxSize(40,20), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer8->Add(zText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer2->Add(BoxSizer5, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("State"));
    Slider = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxSize(150,51), wxSL_HORIZONTAL|wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticBoxSizer2->Add(Slider, 1, wxALL|wxEXPAND, 5);
    BoxSizer9->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Panel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL1"));
    Panel->SetMinSize(wxSize(400,400));
    BoxSizer3->Add(Panel, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer3, 2, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    FileDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GrafikaProjectDialog::OnLoadButtonClick);
    //*)
}

GrafikaProjectDialog::~GrafikaProjectDialog()
{
    //(*Destroy(GrafikaProjectDialog)
    //*)
}

void GrafikaProjectDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GrafikaProjectDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


void GrafikaProjectDialog::OnLoadButtonClick(wxCommandEvent& event)
{
    if (FileDialog->ShowModal()==wxID_OK)
    {
        std::fstream in(FileDialog->GetPath().ToAscii());
        Function = fromFile(in);
        in.close();
    }
}
