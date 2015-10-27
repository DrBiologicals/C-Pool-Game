//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   clock.cpp
//  Description :   Template for implementation clock files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes
#include <windows.h>

// Local Includes

// This Include
#include "clock.h"

// Static Variables

// Static Function Prototypes

// Implementation
CClock::CClock()
: m_fDeltaTime(0.0f)
, m_fLastTime(0.0f)
, m_fCurrentTime(0.0f)
{

}

CClock::~CClock()
{

}

bool
CClock::Initialise()
{

	return (true);
}

void
CClock::Process()
{


	m_fLastTime = m_fCurrentTime;

	m_fCurrentTime = static_cast<float>(timeGetTime());

	if (m_fLastTime == 0.0f)
	{
		m_fLastTime = m_fCurrentTime;
	}

	m_fDeltaTime = m_fCurrentTime - m_fLastTime;

	
}

float
CClock::GetDeltaTick()
{
	return (m_fDeltaTime / 1000.0f);
}