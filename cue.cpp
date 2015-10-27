//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   cue.cpp
//  Description :   Template for implementation background files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "igutils.h"
#include "iniParser.h"

// This Include
#include "cue.h"

// Static Variables

// Static Function Prototypes

// Implementation
CCue::CCue()
{

}
CCue::~CCue()
{

}
bool
CCue::Initialise(float _fPosX, float _fPosY)
{
	//Intialises the table sprite
	//VALIDATE(CEntity::Initialise(IDB_BULLET, IDB_BULLETMASK));

	//Sets the position of the table sprite.
	m_fX = _fPosX;
	m_fY = _fPosY;

	return(true);
}
void
CCue::Draw()
{
	CEntity::Draw();
}
void
CCue::Process(float _fDeltaTick)
{
	CEntity::Process(_fDeltaTick);
	
}