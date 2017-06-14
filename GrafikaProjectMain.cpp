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
#include <cmath>

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
const long GrafikaProjectDialog::ID_BUTTON2 = wxNewId();
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
    DrawButton = new wxButton(this, ID_BUTTON2, _("Draw"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer1->Add(DrawButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    BoxSizer3->Add(Panel, 1, wxALL|wxEXPAND|wxSHAPED, 5);
    BoxSizer1->Add(BoxSizer3, 2, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    FileDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GrafikaProjectDialog::OnLoadButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GrafikaProjectDialog::OnDrawButtonClick);
    Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&GrafikaProjectDialog::OnSliderCmdScroll);
    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&GrafikaProjectDialog::OnSliderCmdSliderUpdated);
    Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&GrafikaProjectDialog::OnPanelPaint,0,this);
    //*)
   // double **DrawData;// dane dla Sheparda, [][3] - rozmiar
    //wxBitmap MemoryBitmap;
    //std::vector<std::vector<double> > Function;
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
        //wxLogMessage("dupa2");
        std::ofstream test1; //log co wczytuje
        test1.open("t1.txt");
        std::ifstream in;
        in.open(FileDialog->GetPath().ToAscii());

        if (!in.good())
        {
            wxLogError("Cannot open file '%s'.", FileDialog->GetPath());
            return;
        }

        if (in.is_open())
            {
                test1 << "otworzył plik";
                fromFile(in, Function, test1);
            }

        in.close();
        test1.close();
    }
}

double Shepard(int N,  std::vector<std::vector<double> > & d, float x, float y, int SliderState, int os1, int os2, int os3)
{
    double wk,L=0,M=0;
    double slider3 = SliderState*9/10;
    for(int i = 0;i < N;++i)
    {
        if(d[os3][i]==slider3)
        {
        wk=1./(fabs(pow((x-d[os1][i]),2)+pow((y-d[os2][i]),2)));

        L += d[3][i]*wk;
        M += wk;
        }
    }
    return L/M;
}

void GrafikaProjectDialog::Draw( std::vector<std::vector<double> > & d,int N)
{
     wxMemoryDC memDC;
    memDC.SelectObject(MemoryBitmap);

// Ponizszy kod mozna spokojnie wyrzucic. Wstawilem jedynie po to, zeby sie
// kompilowalo i rysowalo cos na ekranie
    memDC.SetBackground(*wxWHITE_BRUSH);
    memDC.Clear();
    //memDC.SetDeviceOrigin(250,250);
    memDC.SetPen(*wxBLACK_PEN);
    memDC.SetBrush(*wxTRANSPARENT_BRUSH);

    wxClientDC dc(Panel); ///// w ramach testu


    double tmp,min,max;
    min = max = d[3][0];
    for(float i=0;i<=10;i+=1)
        for(float j=0;j<=10;j+=1)
        {
            tmp=Shepard(N,d,i,j, Slider->GetValue()/10, os1, os2, os3);
            if(tmp<min)
                min=tmp;
            else if(tmp>max)
                max=tmp;
        }
    unsigned int R,G,B;
    double value;

    for(int i=0;i<=400;++i)
        {
            for(int j=0;j<=400;++j)
            {
                value = Shepard(N,d,i*9/400.,j*9/400., Slider->GetValue()/10, os1, os2, os3);

                    R=255-((value-min)/(max-min))*255;
                    G=0;
                    B=((value-min)/(max-min))*255;

                if (R < 0) R = 0;
                if (R > 255) R = 255;
                if (G < 0) G = 0;
                if (G > 255) G = 255;
                if (B < 0) B = 0;
                if (B > 255) B=255;
                memDC.SetPen(wxPen(wxColour(R,G,B)));
                memDC.DrawPoint(i,j);
            }
        }

   // wxMemoryDC memDC2;            ///// w ramach testu
    //memDC.SelectObject(MemoryBitmap);///// w ramach testu
   // wxClientDC dc(Panel);///// w ramach testu
   //int * w;///// w ramach testu
   //int * h;///// w ramach testu
   //Panel.GetSize(w,h);///// w ramach testu
   dc.StretchBlit(0,0,400,400,&memDC,0,0,400,400);///// w ramach testu
    memDC.SelectObject(wxNullBitmap);///// w ramach testu
   //dc.Clear();///// w ramach testu
   //dc.DrawEllipse(15,20,250,250);///// w ramach testu
   //dc.DrawText("dupa", Slider->GetValue()*2,250);///// w ramach testu

   //dc.DrawBitmap(MemoryBitmap,0,0);///// w ramach testu

}

void GrafikaProjectDialog::OnSliderCmdScroll(wxScrollEvent& event)
{
    Draw(Function,Function[0].size());
}



void GrafikaProjectDialog::OnDrawButtonClick(wxCommandEvent& event)
{
    wxString str = xText->GetValue();
    str.ToDouble(&_X);
    str =  yText->GetValue();
    str.ToDouble(&_Y);
    str = zText->GetValue();
    str.ToDouble(&_Z);
    if(_X)
    {
        os1 = 2;
        os2 = 1;
        os3 = 0;
    }
     if(_Y)
    {
        os1 = 0;
        os2 = 2;
        os3 = 1;
    }
     if(_Z)
    {
        os1 = 0;
        os2 = 1;
        os3 = 2;
    }
    Draw(Function,Function[0].size());
}

void GrafikaProjectDialog::OnPanelPaint(wxPaintEvent& event)
{
//    wxMemoryDC memDC;
//    memDC.SelectObject(MemoryBitmap);
//    wxClientDC dc(Panel);
//    dc.Blit(0,0,400,400,&memDC,0,0);
//    memDC.SelectObject(wxNullBitmap);
}

void GrafikaProjectDialog::OnSliderCmdSliderUpdated(wxScrollEvent& event)
{
    Draw(Function,Function[0].size());
}

