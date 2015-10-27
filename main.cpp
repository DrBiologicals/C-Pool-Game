//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   main.cpp
//  Description :   Template for implementation main files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//
#define WIN32_LEAN_AND_MEAN

// Library Includes
#include <windows.h>	//Include all the windows headers.
#include <windowsx.h>	//Include useful macros.

// Local Includes
#include "resource.h"
#include "game.h"
#include "clock.h"
#include "igutils.h"
#include "dialogbox.h"

// This Include

// Static Variables
bool bNewGame = false;

// Static Function Prototypes

// Implementation

#define WINDOW_CLASS_NAME "Pool Game"

LRESULT CALLBACK WindowProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
{
	CGame& rGame = CGame::GetInstance();
	//What is the message?
	switch (_uiMsg)
	{
		case WM_KEYDOWN:
		{
			//Initialises a bullet and changes the velocity of the bullet
			//Depending on the cannons position.
			if (_wParam == VK_SPACE)
			{			
				return(0);
			}
			
			//Changes the sprite of the cannon decreasing the angel by 15 degrees.
			if (_wParam == VK_LEFT)
			{

			}
			//Changes the sprite of the cannon increasing the angel by 15 degrees.
  			if (_wParam == VK_RIGHT)
			{

			}

		}
		break;

		case WM_COMMAND:
			{
				switch(LOWORD(_wParam))
				{
					//Sets NewGame to True and cannon postion to the start 
					//This then will make it so it reintialises the game in win main
				case ID_FILE_NEWGAME:
					{
						bNewGame = true;
						return(0);
	
					}
					break;
					//Intilaises the Debug window.
				case ID_FILE_DEBUG:
					{
						CDialog* m_pDialog = new CDialog;
						m_pDialog->Initialise();

					}
					break;
					//Exits the game.
				case ID_FILE_QUIT:
					{
						CGame::DestroyInstance();
						PostQuitMessage(0);
						return (0);
					}
					break;
					//Gives the player instructions and object of game.
				case ID_ABOUT_INSTRUCTIONS:
					{
						rGame.Instruction();
						bNewGame = true;
					}
					break;
				}
			}
			break;

		case WM_DESTROY:
		{
			//Kill the application, this sends a WM_QUIT message.
			PostQuitMessage(0);

			//Return success
			return (0);
		}
		break;
		default:break;
	} // End switch.

	//Process any messages that we didn't take care of...

	return (DefWindowProc(_hWnd, _uiMsg, _wParam, _lParam));
}

HWND CreateAndRegisterWindow(HINSTANCE _hInstance, int _iWidth, int _iHeight, LPCWSTR _pcTitle)
{
	WNDCLASSEX winclass;
	
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(_hInstance, MAKEINTRESOURCE(IDI_POOLICON));
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
	winclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	winclass.lpszClassName = L"Pool Game";
	winclass.hIconSm = LoadIcon(_hInstance, MAKEINTRESOURCE(IDI_POOLICON));

	if (!RegisterClassEx(&winclass))
	{
		//Failed to register.
		return (0);
	}

	HWND hwnd;
	hwnd = CreateWindowEx(NULL, 
		L"Pool Game", 
		_pcTitle, 
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, 
		CW_USEDEFAULT, CW_USEDEFAULT,
		_iWidth, _iHeight,
		NULL,
		NULL,
		_hInstance,
		NULL);

	if (!hwnd)
	{
		//Failed to create
		return (0);
	}

	return (hwnd);
}
int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _iCmdShow)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	
	const int kiWidth = 1110;
	const int kiHeight = 600;

	HWND hwnd = CreateAndRegisterWindow(_hInstance, kiWidth, kiHeight, L"Pool Game");
	
	CGame& rGame = CGame::GetInstance();

	if (!rGame.Initialise(_hInstance, hwnd, kiWidth, kiHeight))
	{
		//Failed
		return (0);
	}
	//Enter main event loop
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
 			DispatchMessage(&msg);
		}
		//Intialises a new game whenever bNewGame is true.
		//else if(bNewGame == true)
		//{
		//	rGame.Initialise(_hInstance, hwnd, kiWidth, kiHeight);
		//	bNewGame = false;
		//}
		else
		{

			rGame.ExecuteOneFrame();
		}

	}

	// Return to Windows like this...
	CGame::DestroyInstance();

	return (static_cast<int>(msg.wParam));
}