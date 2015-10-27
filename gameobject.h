//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   gameobject.h
//  Description :   Template for declaration gameobject files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined(__GAMEOBJECT_H__)
#define __GAMEOBJECT_H__

// Library Includes
#include <vector>
#include <string>

// Local Includes

// Types

// Constants

// Prototypes
class CTable;
class CCue;
class CBall;
class CCushion;
class CPocket;

class CGameObject
{
    // Member Functions
public:
	CGameObject();
	virtual ~CGameObject();

	virtual bool Initialise(int _iWidth, int _iHeight);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);


protected:
	
	void CheckForWin();


private:
	CGameObject(const CGameObject& _kr);
	CGameObject& operator= (const CGameObject& _kr);

    // Member Variables
public:

protected:
	std::vector<CBall*> m_vecBall;
	std::vector<CCushion*> m_vecCushion;
	std::vector<CPocket*> m_vecPocket;
	CCue* m_pCue;
	CTable* m_pTable;
	
	int m_iWidth;
	int m_iHeight;

	std::string m_strScore;

private:

};

#endif // __LEVEL_H__
