//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   game.h
//  Description :   Template for declaration game files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined __GAME_H__
#define __GAME_H__

#include <windows.h>

#include "clock.h"
#include "iniParser.h"

class CGameObject;
class CBackBuffer;

class CGame
{
public:
	
	virtual ~CGame();

	virtual bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);

	virtual void Process(float _fDeltTick);
	virtual void Draw();

	void ExecuteOneFrame();

	CBackBuffer* GetBackBuffer();
	CGameObject* GetObject();
	HINSTANCE GetAppInstance();
	HWND GetWindow();

	void GameOverWon();
	void GameOverLost();

	void Instruction();

	// Singleton Methods
	static CGame& GetInstance();
	static void DestroyInstance();

private:
	CGame();
	CGame(const CGame& _kr);
	CGame& operator= (const CGame& _kr);

protected:
	//Singleton instance
	static CGame* s_pGame;

	int m_iHeight;
	int m_iWidth;

	CClock* m_pClock;
	CGameObject* m_pGameObject;
	CINIParser* m_pIniParser;

	CBackBuffer* m_pBackBuffer;

	HINSTANCE m_hApplicationInstance;
	HWND m_hMainWindow;

};
#endif // __GAME_H__
