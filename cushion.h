//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   cushion.h
//  Description :   Template for declaration cushion files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined(__CUSHION_H__)
#define __CUSHION_H__

// Library Includes
#include <windows.h>
#include <windowsx.h>
// Local Includes
#include "entity.h"
// Types

// Constants

// Prototypes

class CCushion : public CEntity
{
    // Member Functions
public:
	CCushion();
	virtual ~CCushion();

	virtual bool Initialise(const int _SpriteID, const int _SpriteMaskID);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

protected:

private:
	CCushion (const CCushion & _kr);
	CCushion & operator= (const CCushion & _kr);

    // Member Variables
public:

protected:

private:

};

#endif // __CUSHION_H__