//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   table.cpp
//  Description :   Template for implementation background files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "igutils.h"
#include "resource.h"

// This Include
#include "table.h"

// Static Variables

// Static Function Prototypes

// Implementation
CTable::CTable()
{

}
CTable::~CTable()
{

}
bool
CTable::Initialise(float _fPosX, float _fPosY)
{
	//Intialises the table sprite
	VALIDATE(CEntity::Initialise(IDB_TABLE, IDB_TABLEMASK));

	//Sets the position of the table sprite.
	m_fX = _fPosX;
	m_fY = _fPosY;

	return(true);
}
void
CTable::Draw()
{
	CEntity::Draw();
}
void
CTable::Process(float _fDeltaTick)
{
	CEntity::Process(_fDeltaTick);
	
}