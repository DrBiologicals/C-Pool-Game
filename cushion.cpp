//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   cushion.cpp
//  Description :   Template for implementation background files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "igutils.h"

// This Include
#include "cushion.h"

// Static Variables

// Static Function Prototypes

// Implementation
CCushion::CCushion()
{

}
CCushion::~CCushion()
{

}
bool
CCushion::Initialise(const int _SpriteID, const int _SpriteMaskID)
{
	//Intialises the cushions
	VALIDATE(CEntity::Initialise(_SpriteID, _SpriteMaskID));

	//Sets the position of the cushion sprites.
	return(true);
}
void
CCushion::Draw()
{
	CEntity::Draw();
}
void
CCushion::Process(float _fDeltaTick)
{
	CEntity::Process(_fDeltaTick);
	
}