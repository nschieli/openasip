/*
    Copyright (c) 2002-2009 Tampere University.

    This file is part of TTA-Based Codesign Environment (TCE).

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
 */
/**
 * @file HDBEditorAboutDialog.cc
 * 
 * Definition of HDBEditorAboutDialog class.
 * 
 * @author Veli-Pekka J��skel�inen 2005 (vjaaskel-no.spam-cs.tut.fi)
 * @note rating: red
 */

#include "HDBEditorAboutDialog.hh"
#include "tce_config.h"
#include "WxConversion.hh"
#include "HDBEditorConstants.hh"

/**
 * The Constructor.
 * 
 * @param parent Parent window of the dialog.
 */
HDBEditorAboutDialog::HDBEditorAboutDialog(wxWindow* parent):
    wxDialog(parent, -1, _T("About HDB Editor"), wxDefaultPosition) {

    createContents(this, true, true);
    dynamic_cast<wxStaticText*>(FindWindow(ID_TEXT_PROGRAM_VERSION))->SetLabel(
        _T("OpenASIP ") + WxConversion::toWxString(VERSION));
}

/**
 * The Destructor.
 */
HDBEditorAboutDialog::~HDBEditorAboutDialog() {
}


/**
 * Creates contents of the dialog window. Code generated by wxDesigner.
 * 
 * @param parent Parent dialog of the contents.
 * @param call_fit If true, fits sizer in dialog window.
 * @param set_sizer If true, sets sizer as dialog's sizer.
 * @return Top level sizer of the contents.
 */ 
wxSizer*
HDBEditorAboutDialog::createContents(
    wxWindow *parent, bool call_fit, bool set_sizer) {

    wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );

    item0->Add( 20, 20, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item1 = new wxStaticText( parent, ID_TEXT_PROGRAM_NAME, wxT("HDB Editor"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->SetFont( wxFont( 25, wxROMAN, wxNORMAL, wxNORMAL ) );
    item0->Add( item1, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item2 = new wxStaticText( parent, ID_TEXT_PROGRAM_VERSION, wxT("Version ?.??"), wxDefaultPosition, wxDefaultSize, 0 );
    item0->Add( item2, 0, wxALIGN_CENTER|wxALL, 5 );
    
    wxStaticText *item3 = new wxStaticText( parent, ID_TEXT_PROGRAM_COPYRIGHT, HDBEditorConstants::HDB_EDITOR_COPYRIGHT, 
                                            wxDefaultPosition, wxDefaultSize, 0 );
    item0->Add( item3, 0, wxALIGN_CENTER|wxALL, 5 );

    item0->Add( 20, 20, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticLine *item4 = new wxStaticLine( parent, ID_LINE, wxDefaultPosition, wxSize(200,-1), wxLI_HORIZONTAL );
    item0->Add( item4, 0, wxGROW|wxALL, 5 );

    wxButton *item5 = new wxButton( parent, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    item0->Add( item5, 0, wxALIGN_CENTER|wxALL, 5 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}
