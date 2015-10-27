//
//  Diploma of Interactive Gaming
//  Game Development Faculty
//  Media Design School
//  Auckland
//  New Zealand
//
//  (c) 2005-2010 Media Design School
//
//  File Name   :   iniParser.cpp
//  Description :   Template for implementation IniParser files
//  Author      :   Carsten Scholz
//  Mail        :   carsten.scholz@mediadesign.school.nz
//

// Library Includes
#include <iostream>

// Local Includes

// This Include
#include "iniParser.h"

// Static Variables

// Static Function Prototypes

// Implementation
CINIParser::CINIParser()
{

}

CINIParser::~CINIParser()
{

}

bool
CINIParser::LoadIniFile(const char* _pcFilename)
{
	bool bResult = false;

	//Our string values for section and the current line.
	std::string strLine;
	std::string strSection;
	std::string strMapKey;

	//Setting the filename string
	std::string strFilename(_pcFilename);
	m_strFilename = strFilename + ".ini";
 
	m_filestream.open(m_strFilename.c_str());

	if (m_filestream.is_open())
	{
		while (!m_filestream.eof())
		{
			bool bReadingKey = true;
			std::string strKey = "";
			std::string strValue = "";

			getline( m_filestream, strLine );

			if (strLine[0] == ';')
			{
				//this line is a comment, ignore it
				continue;
			}
			else if (strLine[0] == '[')
			{
				//Its a section, read it
				strSection = "";

				for(int i = 0; i < static_cast<int>(strLine.size()); ++i)
				{
					if (strLine[i] == '[' || strLine[i] == ']')
					{
						continue;
					}
					
					strSection += strLine[i];
				}

				continue;
			}
			else if (strLine.empty())
			{
				//string is empty, read next line
				continue;
			}

			for(int i = 0; i < static_cast<int>(strLine.size()); ++i)
			{
				if (strLine[i] == ' ')
				{
					continue;
				}
				else if (strLine[i] == '"')
				{
					continue;
				}
				else if (strLine[i] == '=')
				{
					bReadingKey = false;
					continue;
				}
				else if (strLine[i] == ';')
				{
					//the rest of the line are comments
					break;
				}

				if (bReadingKey)
				{
					strKey += strLine[i];
				}
				else
				{
					strValue += strLine[i];
				}
			
			}
			strMapKey = strSection + "|" + strKey;
			m_mapPairs[strMapKey] = strValue;

		}

		m_filestream.close();
	}
	else
	{
		bResult = false;
	}

	return (bResult);
}

bool
CINIParser::AddValue(const char *_pcSection, const char *_pcKey, const char *_pcValue)
{
	bool bResult = true;

	std::string strValueCheck(_pcValue);
	if (strValueCheck == "")
	{
		bResult = false;
	}
	else
	{
		std::string strTempKey(_pcSection);
		strTempKey += "|";
		strTempKey += _pcKey;

		m_mapPairs[strTempKey] = strValueCheck;
	}

	return (bResult);
	
}

bool
CINIParser::GetStringValue(const char *_pcSection, const char *_pcKey, std::string &_rStrValue)
{
	bool bResult = false;

	std::string strSection(_pcSection);
	std::string strKey(strSection);
	strKey += "|";
	strKey += _pcKey;

	if(!m_mapPairs[strKey].empty())
	{
		_rStrValue = m_mapPairs[strKey];
		bResult = true;
	}

	return (bResult);
}

bool
CINIParser::GetIntValue(const char *_pcSection, const char *_pcKey, int &_riValue)
{
	bool bResult = false;

	std::string strSection(_pcSection);
	std::string strKey(strSection);
	strKey += "|";
	strKey += _pcKey;

	if(!m_mapPairs[strKey].empty())
	{
		_riValue = atoi(m_mapPairs[strKey].c_str());
		bResult = true;
	}

	return (bResult);
}

bool
CINIParser::GetFloatValue(const char *_pcSection, const char *_pcKey, float &_rfValue)
{
 	bool bResult = false;

	std::string strSection(_pcSection);
	std::string strKey(strSection);
	strKey += "|";
	strKey += _pcKey;

	if(!m_mapPairs[strKey].empty())
	{
		_rfValue = static_cast<float>(atof(m_mapPairs[strKey].c_str()));
		bResult = true;
	}

	return (bResult);
}

bool
CINIParser::GetBoolValue(const char *_pcSection, const char *_pcKey, bool &_rbValue)
{
 	bool bResult = false;

	std::string strSection(_pcSection);
	std::string strKey(strSection);
	strKey += "|";
	strKey += _pcKey;

	if(!m_mapPairs[strKey].empty())
	{
		_rbValue = (m_mapPairs[strKey] == "true");
		bResult = true;
	}

	return (bResult);
}
