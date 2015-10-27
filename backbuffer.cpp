//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   backbuffer.cpp
//  Description :   Template for implementation BackBuffer files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "resource.h"

// This Include
#include "backbuffer.h"

// Static Variables

// Static Function Prototypes

// Implementation
CBackBuffer::CBackBuffer()
: m_hWnd(0)
, m_hDC(0)
, m_hSurface(0)
, m_hOldObject(0)
, m_iWidth(0)
, m_iHeight(0)
{

}
CBackBuffer::~CBackBuffer()
{
	SelectObject(m_hDC, m_hOldObject);

	DeleteObject(m_hSurface);
	DeleteObject(m_hDC);
}
bool 
CBackBuffer::Initialise(HWND _hWnd, int _iWidth, int _iHeight)
{
	m_hWnd = _hWnd;
	m_iWidth = _iWidth;
	m_iHeight = _iHeight;

	HDC hWindowDC = ::GetDC(m_hWnd);
	m_hDC = CreateCompatibleDC(hWindowDC);
	m_hSurface = CreateCompatibleBitmap(hWindowDC, m_iWidth, m_iHeight);
	ReleaseDC(m_hWnd, hWindowDC);

	m_hOldObject = static_cast<HBITMAP>(SelectObject(m_hDC, m_hSurface));

	HBRUSH brushWhite = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));

	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(m_hDC, brushWhite));
	Rectangle(m_hDC, 0, 0, m_iWidth, m_iHeight);
	SelectObject(m_hDC, oldBrush);

	return (true);
}
HDC
CBackBuffer::GetBackDC() const
{
	return(m_hDC);
}
int 
CBackBuffer::GetHeight() const
{
	return(m_iHeight);
}
int 
CBackBuffer::GetWidth() const
{
	return(m_iWidth);
}
void 
CBackBuffer::Clear()
{

	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(GetBackDC(), GetStockObject(WHITE_BRUSH)));

	Rectangle(m_hDC, 0, 0, m_iWidth, m_iHeight);

	SelectObject(m_hDC, oldBrush);
}
void 
CBackBuffer::Present()
{
	HDC hWndDC = ::GetDC(m_hWnd);

	BitBlt(hWndDC, 0, 0, m_iWidth, m_iHeight, m_hDC, 0, 0, SRCCOPY);

	ReleaseDC(m_hWnd, hWndDC);

}