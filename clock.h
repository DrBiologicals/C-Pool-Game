//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   clock.h
//  Description :   Template for declaration Clock files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once
#if !defined (__CLOCK_H__)
#define __CLOCK_H__

// Library Includes
#include <windows.h>

class CClock
{
	// Member Functions
public:
	CClock();
	virtual ~CClock();
	virtual bool Initialise();
	virtual void Process();
	float GetDeltaTick();

private:
	CClock(const CClock& _kr);
	CClock& operator= (const CClock& _kr);

	// Member Variables
protected:
	float m_fDeltaTime;
	float m_fCurrentTime;
	float m_fLastTime;
};
#endif // __CLOCK_H__