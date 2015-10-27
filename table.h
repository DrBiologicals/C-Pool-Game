//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   table.h
//  Description :   Template for declaration table files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined(__TABLE_H__)
#define __TABLE_H__

// Library Includes
#include <windows.h>
#include <windowsx.h>
// Local Includes
#include "entity.h"
// Types

// Constants

// Prototypes

class CTable : public CEntity
{
    // Member Functions
public:
	CTable();
	virtual ~CTable();

	virtual bool Initialise(float _fPosX, float _fPosY);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

protected:

private:
	CTable (const CTable & _kr);
	CTable & operator= (const CTable & _kr);

    // Member Variables
public:

protected:

private:

};

#endif // __TABLE_H__