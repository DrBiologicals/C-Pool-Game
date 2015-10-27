//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   gameobject.cpp
//  Description :   Template for implementation gameobject files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes
#include <cmath>

// Local Includes
#include "table.h"
#include "igutils.h"
#include "backbuffer.h"
#include "game.h"
#include "ball.h"
#include "cushion.h"
#include "pocket.h"
#include "resource.h"

// This Include
#include "gameobject.h"

// Static Variables

// Static Function Prototypes

// Implementation
CGameObject::CGameObject()
: m_pTable(0)
{

}

CGameObject::~CGameObject()
{
	delete m_pTable;
	m_pTable = 0;

}
bool
CGameObject::Initialise(int _iWidth, int _iHeight)
{
	m_iWidth = _iWidth;
	m_iHeight = _iHeight;

	//Initialises the Table, which just acts as a background.
	m_pTable = new CTable();
	VALIDATE(m_pTable->Initialise(m_iWidth / 2.0f, m_iHeight / 2.0f));

	//Number of Balls being intialised.
	const int m_iNumBalls = 16;
	const int kiBallStartY = 275;
	const int kiBallStartX = 700;
	const int kiBallGap = 15;

	int iBallCurrentX = kiBallStartX;
	int iBallCurrentY = kiBallStartY;

	//Iterates through the balls creating all 16 of them.
	for (int i = 0; i < m_iNumBalls; ++i)
	{
		int iBallSprite = 100;
		iBallSprite += (8 + i);

		CBall* pBall = new CBall();
		VALIDATE(pBall->Initialise(iBallSprite, IDB_BALLMASK));

		if(i == 0)
		{
			int iCueBallX = 295;
			int iCueBallY = 275;
			pBall->SetX(static_cast<float>(iCueBallX));
			pBall->SetY(static_cast<float>(iCueBallY));

			iBallCurrentX += static_cast<int>(pBall->GetWidth());
		}
		else if(i == 2 || i == 4 || i == 7 || i == 8 || i == 9 || i == 11 || i == 14)
		{
			pBall->SetX(static_cast<float>(iBallCurrentX));
			pBall->SetY(static_cast<float>(iBallCurrentY));
			iBallCurrentY -= (kiBallGap * 2);
		}
		else if(i == 5 || i == 12 || i == 13)
		{
			pBall->SetX(static_cast<float>(iBallCurrentX));
			pBall->SetY(static_cast<float>(iBallCurrentY));
			iBallCurrentY += (kiBallGap * 4);
		}
		else
		{
			//Sets the position of the Ball sprites
			pBall->SetX(static_cast<float>(iBallCurrentX));
			pBall->SetY(static_cast<float>(iBallCurrentY));

			iBallCurrentX += (static_cast<int>(pBall->GetWidth()) - 5);
			iBallCurrentY += kiBallGap;
		}

		m_vecBall.push_back(pBall);
	}

	const int m_iNumCushions = 6;
	const int kiCushionStartY = 57;
	const int kiCushionStartX = 300;
	const int kiCushionGap = 50;

	int iCushionCurrentX = kiCushionStartX;
	int iCushionCurrentY = kiCushionStartY;

	for(int i = 0; i < m_iNumCushions; ++i)
	{
		int j = i;
		int iCushionSprite = 124;

		if(j == 1)
		{
			j = (i - 1);
		}
		else if (j == 3 || j == 5)
		{
			j = (i + 1);
		}
		else if(j == 4)
		{
			j = (i + 2);
		}

		iCushionSprite += j;

		CCushion* pCushion = new CCushion;
		VALIDATE(pCushion->Initialise(iCushionSprite, (iCushionSprite + 1)));

		pCushion->SetX(static_cast<float>(iCushionCurrentX));
		pCushion->SetY(static_cast<float>(iCushionCurrentY));

		iCushionCurrentX += static_cast<int>(pCushion->GetWidth()) + kiCushionGap;

		if(i == 1)
		{
			iCushionCurrentX = 35;
			iCushionCurrentY = 287;
		}
		else if(i == 2)
		{
			iCushionCurrentX = 1060;
		}
		else if(i == 3)
		{
			iCushionCurrentX = 300;
			iCushionCurrentY = 527;
		}
			
		m_vecCushion.push_back(pCushion);
	}




	return(true);
}
//Draws all the sprites currently on the window.
void
CGameObject::Draw()
{
	m_pTable->Draw();

	for (unsigned int i = 0; i < m_vecBall.size(); ++i)
	{
		m_vecBall[i]->Draw();
	}	
	for (unsigned int i = 0; i < m_vecCushion.size(); ++i)
	{
		m_vecCushion[i]->Draw();
	}	

}
//Processes all classes which are required to play the game.
void
CGameObject::Process(float _fDeltaTick)
{
	m_pTable->Process(_fDeltaTick);

	for (unsigned int i = 0; i < m_vecBall.size(); ++i)
	{
		m_vecBall[i]->Process(_fDeltaTick);
	}
	for (unsigned int i = 0; i < m_vecCushion.size(); ++i)
	{
		m_vecCushion[i]->Process(_fDeltaTick);
	}	

 }
void
CGameObject::CheckForWin()
{

	CGame::GetInstance().GameOverWon();
	
}






