//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   dialogbox.cpp
//  Description :   Template for implementation dialogbox files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes
#include <windows.h>
#include <windowsx.h>

// Local Includes
#include "resource.h"
#include "game.h"
#include "gameobject.h"

// This Include
#include "dialogbox.h"

// Static Variables

int iResult;
CGameObject* m_pGameObject;
CGame* m_pGame;
HINSTANCE _hInstance;

// Static Function Prototypes

// Implementation
BOOL CALLBACK DialogProc(HWND _hDlg, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	switch(_msg)
	{
	case WM_INITDIALOG:
		{
			return true;
		}
		break;
	case WM_COMMAND:
		{
			switch(LOWORD(_wparam))
			{
			case ID_APPLY1:
				{
					DestroyWindow(_hDlg);
					return(0);
				}
				break;
			}
		}
		break;
	default:
		{
			return false;
		}
	}

}
int
CDialog::Initialise()
{
	//Initialises the dialog box.
	DialogBox(_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);

	return(0);
}




