#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include <vector>
#include <string>

class CVector2
{
public:
	CVector2();
	~CVector2();
	
	static CVector2& Add(CVector2& _rA, CVector2& _rB, CVector2& _rResultant);
	static CVector2& Subtract(CVector2& _rA, CVector2& _rB, CVector2& _rResultant);
	static CVector2& ScalarMultiply(CVector2& _rA, float _fScalar, CVector2& _rResultant);
	static float Magnitude(CVector2& _rA);
	static float DotProduct(CVector2& _rA, CVector2& _rB);
	static CVector2& CrossProduct(CVector2& _rA, CVector2& _rB, CVector2& _rResultant);
	static bool Equals(CVector2& _rA, CVector2& _rB);
	static CVector2& Normalise(CVector2& _rA, CVector2& _rResultant);
	static CVector2& Projection(CVector2& _rA, CVector2& _rB, CVector2& _rResultant);

	void SetX(float _fX);
	void SetY(float _fY);

	float GetX();
	float GetY();

	std::string& ToString(std::string& _rString);

public:
	float m_fX;
	float m_fY;

};
#endif //__VECTOR2_H__