//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   ball.h
//  Description :   Template for declaration ball files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined(__BALL_H__)
#define __BALL_H__

// Library Includes
#include <windows.h>
#include <windowsx.h>
// Local Includes
#include "entity.h"
// Types

// Constants

// Prototypes

class CBall : public CEntity
{
    // Member Functions
public:
	CBall();
	virtual ~CBall();

	virtual bool Initialise(const int _SpriteID, const int _SpriteMaskID);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	void SetPocketCollision(bool _b);
	bool GetPocketCollision() const;

	float GetVelocityX() const;
	float GetVelocityY() const;
	void SetVelocityX(float _fX);
	void SetVelocityY(float _fY);

	float GetRadius() const;

protected:

private:
	CBall (const CBall & _kr);
	CBall & operator= (const CBall & _kr);

    // Member Variables
public:

protected:
	float m_fVelocityX;
	float m_fVelocityY;
	float m_fX;
	float m_fY;

	bool m_bPocketCollision;

private:

};

#endif // __BALL_H__