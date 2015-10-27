//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   game.cpp
//  Description :   Template for implementation game files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes
#include "clock.h"
#include "backbuffer.h"
#include "igutils.h"
#include "gameobject.h"
#include "iniparser.h"

// Local Includes

// This Include
#include "game.h"

// Static Variables

// Static Function Prototypes
CGame* CGame::s_pGame = 0;

// Implementation
CGame::CGame()
: m_pClock(0)
, m_pGameObject(0)
, m_pIniParser(0)
, m_hApplicationInstance(0)
, m_hMainWindow(0)
, m_iHeight(0)
, m_iWidth(0)
, m_pBackBuffer(0)
{

}
CGame::~CGame()
{
	delete m_pIniParser;
	m_pIniParser = 0;

	delete m_pGameObject;
	m_pGameObject = 0;

	delete m_pBackBuffer;
	m_pBackBuffer = 0;

	delete m_pClock;
	m_pClock = 0;
}
bool
CGame::Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight)
{

	m_hApplicationInstance = _hInstance;
	m_hMainWindow = _hWnd;
	m_iWidth = _iWidth;
	m_iHeight = _iHeight;

	//Initialises the clock.
	m_pClock = new CClock();
	VALIDATE(m_pClock->Initialise());
	m_pClock->Process();

	//Intialises the Backbuffer.
	m_pBackBuffer = new CBackBuffer();
	VALIDATE(m_pBackBuffer->Initialise(_hWnd, m_iWidth, m_iHeight));

	//Initialises Lives, Cannon and ammo.
	m_pGameObject = new CGameObject();
	VALIDATE(m_pGameObject->Initialise(m_iWidth, m_iHeight));

	return (true);
}
void 
CGame::Process(float _fDeltaTick)
{
	m_pGameObject->Process(_fDeltaTick);
}
void 
CGame::Draw()
{
	m_pBackBuffer->Clear();

	m_pGameObject->Draw();

	m_pBackBuffer->Present();

}
void 
CGame::ExecuteOneFrame()
{

	double fDT = m_pClock->GetDeltaTick();
			
	Process(static_cast<float>(fDT));
	Draw();

	m_pClock->Process();

	Sleep(1);
	
}
CGame&
CGame::GetInstance()
{
	if (s_pGame == 0)
	{
		s_pGame = new CGame();
	}

	return (*s_pGame);
}
void
CGame::GameOverWon()
{
	MessageBox(m_hMainWindow, L"LEVEL 1 COMPLETE! \nAdvancing to level 2", L"LEVEL 1", MB_OK);
}

void
CGame::GameOverLost()
{
	//This messagebox is shown once the player has lost all the lives.
	MessageBox(m_hMainWindow, L"***GAME OVER***", L"Game Over", MB_OK);
}
void
CGame::DestroyInstance()
{
	delete s_pGame;
	s_pGame = 0;
}
CBackBuffer*
CGame::GetBackBuffer()
{
	return (m_pBackBuffer);
}

CGameObject*
CGame::GetObject()
{
	return (m_pGameObject);
}

HINSTANCE
CGame::GetAppInstance()
{
	return (m_hApplicationInstance);
}

HWND
CGame::GetWindow()
{
	return (m_hMainWindow);
}

void
CGame::Instruction()
{
	//Displays the instructions for the player.
	MessageBox(m_hMainWindow, L"***INSTRUCTIONS***\n\nGoal of Cannon Blitz is too shoot"
		L" Parachuting Soldiers coming down the screen.\nIf a Soldier Reaches the bottom"
		L" the player loses a life.\nRotate the cannon in order to adjust the angel in which"
		L" you fire bullets at. \nIf the player kills 100 soldiers the player advances to the next"
		L" level \nif the player kills all 100 soldiers during level three the player wins."
		L" \nHowever if the player loses all three lives the player loses.\n\n ***CONTROLS***\n SpaceBar == Shoot"
		L"\n Left Arrow == Cannon Rotates Left\n Right Arrow == Cannon Rotates Right"
		L"\n Pause == Pauses the game", L"Instructions", MB_OK);

}

