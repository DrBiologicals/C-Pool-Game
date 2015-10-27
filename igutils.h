//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   igutils.h
//  Description :   Template for declaration igutil files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once

#if !defined (__IGUTILS_H__)
#define __IGUTILS_H__

// Library Includes
#include <strstream>
#include <string>
#include <algorithm>

#define VALIDATE(a) if (!a) return (false)

template<typename T>
std::string ToString(const T& _value)
{
	std::strstream theStream;
	theStream << _value << std::ends;
	return (theStream.str());
}
template<typename s>
std::wstring StringToWString(const s& _string)
{
	std::wstring temp(_string.length(), L'');
	std::copy(_string.begin(), _string.end(), temp.begin());
	return temp;
}


#endif // __IGUTILS_H__