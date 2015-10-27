//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   backbuffer.h
//  Description :   Template for declaration BackBuffer files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//
#pragma once

#if !defined (__BACKBUFFER_H__)
#define __BACKBUFFER_H__

// Library Includes
#include <windows.h>

class CBackBuffer
{
	// Member Functions
public:
	CBackBuffer();
	virtual ~CBackBuffer();

	virtual bool Initialise(HWND _hWnd, int _iWidth, int _iHeight);

	HDC GetBackDC() const;

	int GetHeight() const;
	int GetWidth() const;

	void Clear();
	void Present();

private:
	CBackBuffer(const CBackBuffer& _kr);
	CBackBuffer& operator= (const CBackBuffer& _kr);

	// Member Variables
protected:
	HWND m_hWnd;
	HDC m_hDC;
	HBITMAP m_hSurface;
	HBITMAP m_hOldObject;
	int m_iWidth;
	int m_iHeight;
};
#endif //__BACKBUFFER_H__
