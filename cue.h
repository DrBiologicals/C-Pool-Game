//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   cue.h
//  Description :   Template for declaration cue files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined(__CUE_H__)
#define __CUE_H__

// Library Includes
#include <windows.h>
#include <windowsx.h>
// Local Includes
#include "entity.h"
// Types

// Constants

// Prototypes

class CCue : public CEntity
{
    // Member Functions
public:
	CCue();
	virtual ~CCue();

	virtual bool Initialise(float _fPosX, float _fPosY);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

protected:

private:
	CCue (const CCue & _kr);
	CCue & operator= (const CCue & _kr);

    // Member Variables
public:

protected:

private:

};

#endif // __CUE_H__