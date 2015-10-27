#include "line.h"

CLine::CLine()
{

}
CLine::~CLine()
{

}
void
CLine::SetQ(const CVector2 &_krvec2q)
{
	m_vec2q = _krvec2q;
}
void
CLine::SetV(const CVector2 &_krvec2v)
{
	m_vec2v = _krvec2v;
}
const CVector2&
CLine::GetQ() const
{
	return(m_vec2q);
}
const CVector2&
CLine::GetV() const
{
	return(m_vec2v);
}