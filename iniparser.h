//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   iniParser.h
//  Description :   Template for declaration CINIParser files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

#pragma once
#if !defined (__IGFEB10_CINIPARSER_H__)
#define __IGFEB10_CINIPARSER_H__

// Library Includes
#include <map>
#include <string>
#include <fstream>

class CINIParser
{
    // Member Functions
public:
	CINIParser();
	~CINIParser();

	bool LoadIniFile(const char* _pcFilename);
	bool AddValue(const char* _pcSection, const char* _pcKey, const char* _pcValue);
	bool GetStringValue(const char* _pcSection, const char* _pcKey, std::string& _rStrValue);
	bool GetIntValue(const char* _pcSection, const char* _pcKey, int& _riValue);
	bool GetFloatValue(const char* _pcSection, const char* _pcKey, float& _rfValue);
	bool GetBoolValue(const char* _pcSection, const char* _pcKey, bool& _rbValue);


private:
	std::map<std::string, std::string> m_mapPairs;
	std::string m_strFilename;
	std::fstream m_filestream;

};

#endif // __IGFEB10_CININPARSER_H__