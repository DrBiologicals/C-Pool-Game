//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   ball.cpp
//  Description :   Template for implementation background files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "igutils.h"
#include "resource.h"

// This Include
#include "ball.h"

// Static Variables

// Static Function Prototypes

// Implementation
CBall::CBall()
: m_fVelocityX(0.0f)
, m_fVelocityY(0.0f)
, m_bPocketCollision(false)
{

}
CBall::~CBall()
{

}
bool
CBall::Initialise(const int _SpriteID, const int _SpriteMaskID)
{
	//Intialises the balls
	VALIDATE(CEntity::Initialise(_SpriteID, _SpriteMaskID));


	return(true);
}
void
CBall::Draw()
{
	CEntity::Draw();
}
void
CBall::Process(float _fDeltaTick)
{
	
	//m_fX += m_fVelocityX * _fDeltaTick;
	//m_fY += m_fVelocityY * _fDeltaTick;

	CEntity::Process(_fDeltaTick);
	
}
void 
CBall::SetPocketCollision(bool _b)
{
	m_bPocketCollision = _b;
}
bool 
CBall::GetPocketCollision() const
{
	return(m_bPocketCollision);
}
float
CBall::GetVelocityX() const
{
	return (m_fVelocityX);
}

float
CBall::GetVelocityY() const
{
	return (m_fVelocityY);
}

void
CBall::SetVelocityX(float _fX)
{
	m_fVelocityX = _fX;
}

void
CBall::SetVelocityY(float _fY)
{
	m_fVelocityY = _fY;
}

float
CBall::GetRadius() const
{
	return (GetWidth() / 2.0f);
}