//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   pocket.h
//  Description :   Template for declaration pocket files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined(__POCKET_H__)
#define __POCKET_H__

// Library Includes
#include <windows.h>
#include <windowsx.h>
// Local Includes
#include "entity.h"
// Types

// Constants

// Prototypes

class CPocket : public CEntity
{
    // Member Functions
public:
	CPocket();
	virtual ~CPocket();

	virtual bool Initialise(float _fPosX, float _fPosY);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

protected:

private:
	CPocket (const CPocket & _kr);
	CPocket & operator= (const CPocket & _kr);

    // Member Variables
public:

protected:

private:

};

#endif // __POCKET_H__