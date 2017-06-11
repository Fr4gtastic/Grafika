/***************************************************************
 * Name:      GrafikaProjectMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2017-06-10
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef GRAFIKAPROJECTMAIN_H
#define GRAFIKAPROJECTMAIN_H

//(*Headers(GrafikaProjectDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include <vector>

class GrafikaProjectDialog: public wxDialog
{
    public:

        GrafikaProjectDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~GrafikaProjectDialog();

    private:

        //(*Handlers(GrafikaProjectDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnScrollBar1Scroll(wxScrollEvent& event);
        void OnLoadButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(GrafikaProjectDialog)
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_SLIDER1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(GrafikaProjectDialog)
        wxTextCtrl* yText;
        wxButton* LoadButton;
        wxSlider* Slider;
        wxTextCtrl* xText;
        wxStaticText* StaticText2;
        wxFileDialog* FileDialog;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxTextCtrl* zText;
        wxBoxSizer* BoxSizer1;
        wxPanel* Panel;
        //*)

        DECLARE_EVENT_TABLE()
        std::vector<std::vector<double> > Function;
};

#endif // GRAFIKAPROJECTMAIN_H
