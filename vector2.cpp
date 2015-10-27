#include <cmath>

#include "vector2.h"

CVector2::CVector2()
:m_fX(0)
,m_fY(0)
{

}
CVector2::~CVector2()
{

}
CVector2&
CVector2::Add(CVector2& _rA, CVector2& _rB, CVector2& _rResultant)
{
	
	_rResultant.SetX(_rA.GetX() + _rB.GetX());
	_rResultant.SetY(_rA.GetY() + _rB.GetY());

	return(_rResultant);

}
CVector2&
CVector2::Subtract(CVector2& _rA, CVector2& _rB, CVector2& _rResultant)
{
	_rResultant.SetX(_rA.GetX() - _rB.GetX());
	_rResultant.SetY(_rA.GetY() - _rB.GetY());

	return(_rResultant);
}
CVector2&
CVector2::ScalarMultiply(CVector2& _rA, float _fScalar, CVector2& _rResultant)
{
	_rResultant.SetX(_fScalar * _rA.GetX());
	_rResultant.SetY(_fScalar * _rA.GetY());

	return(_rResultant);
}
float 
CVector2::Magnitude(CVector2& _rA)
{
	float fMagnitude = sqrt((_rA.GetX() * _rA.GetX()) + (_rA.GetY() * _rA.GetY()));

	return(fMagnitude);
}
float 
CVector2::DotProduct(CVector2& _rA, CVector2& _rB)
{
	float fDotResult = ((_rA.GetX() * _rB.GetX()) + (_rA.GetY() * _rB.GetY()));

	return(fDotResult);
}
CVector2&
CVector2::CrossProduct(CVector2& _rA, CVector2& _rB, CVector2& _rResultant)
{
	_rResultant.SetX(((_rA.GetY() * _rB.GetX()) - (_rA.GetX() * _rA.GetY())));
	_rResultant.SetY(((_rA.GetX() * _rB.GetX()) - (_rA.GetY() * _rA.GetX())));

	return(_rResultant);
}
bool 
CVector2::Equals(CVector2& _rA, CVector2& _rB)
{
	bool bEqual = false;
	if(_rA.GetX() == _rB.GetX() && _rA.GetY() == _rB.GetY())
	{
		bEqual = true;
		return(bEqual);
	}
	else
	{
		return(bEqual);
	}

}
CVector2&
CVector2::Normalise(CVector2& _rA, CVector2& _rResultant)
{
	_rResultant.SetX(_rA.GetX() / sqrt((_rA.GetX() * _rA.GetX()) + (_rA.GetY() * _rA.GetY())));
	_rResultant.SetY(_rA.GetY() / sqrt((_rA.GetX() * _rA.GetX()) + (_rA.GetY() * _rA.GetY())));

	return(_rResultant);
}
CVector2&
CVector2::Projection(CVector2& _rA, CVector2& _rB, CVector2& _rResultant)
{
	_rResultant.SetX((((_rA.GetX() * _rB.GetX()) + (_rA.GetY() * _rB.GetY())) /
					((_rB.GetX() * _rB.GetX()) + (_rB.GetY() * _rB.GetY()))) 
					* _rB.GetX());
	_rResultant.SetY((((_rA.GetX() * _rB.GetX()) + (_rA.GetY() * _rB.GetY())) /
					((_rB.GetX() * _rB.GetX()) + (_rB.GetY() * _rB.GetY()))) 
					* _rB.GetY());

	return(_rResultant);
}

void 
CVector2::SetX(float _fX)
{
	m_fX = _fX;
	
}
void 
CVector2::SetY(float _fY)
{
	m_fY = _fY;
	
}
float 
CVector2::GetX()
{
	return(m_fX);
}
float 
CVector2::GetY()
{
	return(m_fY);
}
std::string& 
CVector2::ToString(std::string& _rString)
{
	return(_rString);
}