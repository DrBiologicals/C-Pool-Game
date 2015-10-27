//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   sprite.h
//  Description :   Template for declaration sprite files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined __SPRITE_H__
#define __SPRITE_H__

// Library Includes
#include <windows.h>

class CSprite
{
	// Member Functions
public:
	CSprite();
	virtual ~CSprite();

	virtual bool Initialise(int _iSpriteResourceID, int _iMaskResourceID);

	virtual void Process(float _fDeltaTick);
	virtual void Draw();

	int GetWidth() const;
	int GetHeight() const;

	int GetX() const;
	int GetY() const;
	void SetX(int _i);
	void SetY(int _i);

	void TranslateRelative(int _iX, int _iY);
	void TranslateAbsolute(int _iX, int _iY);

private:
	CSprite(const CSprite& _kr);
	CSprite& operator= (const CSprite& _kr);

	// Member Variables
protected:
	static int s_iRefCount;
	static HDC s_hSharedSpriteDC;

	int m_iX;
	int m_iY;

	HBITMAP m_hSprite;
	HBITMAP m_hMask;

	BITMAP m_bitmapSprite;
	BITMAP m_bitmapMask;
};
#endif // __SPRITE_H__
