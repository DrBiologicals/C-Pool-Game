//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   pocket.cpp
//  Description :   Template for implementation background files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "igutils.h"
#include "iniParser.h"

// This Include
#include "pocket.h"

// Static Variables

// Static Function Prototypes

// Implementation
CPocket::CPocket()
{

}
CPocket::~CPocket()
{

}
bool
CPocket::Initialise(float _fPosX, float _fPosY)
{
	//Intialises the cushions
	//VALIDATE(CEntity::Initialise(IDB_BULLET, IDB_BULLETMASK));

	//Sets the position of the cushion sprites.
	m_fX = _fPosX;
	m_fY = _fPosY;

	return(true);
}
void
CPocket::Draw()
{
	CEntity::Draw();
}
void
CPocket::Process(float _fDeltaTick)
{
	CEntity::Process(_fDeltaTick);
	
}