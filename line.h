#ifndef __LINE_H__
#define __LINE_H__

#include "vector2.h"

class CLine
{
public:
	CLine();
	~CLine();

	void SetQ(const CVector2& _krvec2q);
	void SetV(const CVector2& _krvec2v);
	const CVector2& GetQ() const;
	const CVector2& GetV() const;

public:
	CVector2 m_vec2q;
	CVector2 m_vec2v;
};
#endif //__LINE_H__