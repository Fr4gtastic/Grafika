/***************************************************************
 * Name:      GrafikaProjectApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2017-06-10
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "GrafikaProjectApp.h"

//(*AppHeaders
#include "GrafikaProjectMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GrafikaProjectApp);

bool GrafikaProjectApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GrafikaProjectDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
