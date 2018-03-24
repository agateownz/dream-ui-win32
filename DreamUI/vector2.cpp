#include "vector2.h"

Vector2::Vector2()
	: Vector2(0, 0)
{
}

Vector2::Vector2(int32_t x, int32_t y)
	: m_x(x)
	, m_y(y)
{
}

Vector2& Vector2::operator+(const Vector2& rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	return *this;
}

Vector2& Vector2::operator-(const Vector2& rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	return *this;
}

Vector2& Vector2::operator*(const Vector2 & rhs)
{
	this->m_x = (rhs.m_x * this->m_x);
	this->m_y = (rhs.m_y * this->m_y);
	return *this;
}

Vector2& Vector2::operator/(const Vector2 & rhs)
{
	this->m_x = (rhs.m_x / this->m_x);
	this->m_y = (rhs.m_y / this->m_y);
	return *this;
}