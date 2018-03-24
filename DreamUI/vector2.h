#ifndef DREAMUI_VECTOR2_H
#define DREAMUI_VECTOR2_H

#include "base.h"

struct Vector2
{
	Vector2();

	Vector2(int32_t x, int32_t y);

	int32_t getX() { return m_x; }
	int32_t getY() { return m_y; }

	void setX(int32_t x) { m_x = x; }
	void setY(int32_t y) { m_y = y; }

	Vector2& operator+(const Vector2& rhs);
	Vector2& operator-(const Vector2& rhs);
	Vector2& operator*(const Vector2& rhs);
	Vector2& operator/(const Vector2& rhs);

	friend bool operator<(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.m_x < rhs.m_x && lhs.m_y < rhs.m_y;
	}
	friend bool operator>(const Vector2& lhs, const Vector2& rhs)
	{
		return rhs < lhs;
	}
	friend bool operator<=(const Vector2& lhs, const Vector2& rhs)
	{
		return !(lhs > rhs);
	}
	friend bool operator>=(const Vector2& lhs, const Vector2& rhs)
	{
		return !(lhs < rhs);
	}
	friend bool operator==(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y;
	}
	friend bool operator!=(const Vector2& lhs, const Vector2& rhs)
	{
		return !(lhs == rhs);
	}

private:
	int32_t m_x;
	int32_t m_y;
};

#endif // !DREAMUI_VECTOR2_H

