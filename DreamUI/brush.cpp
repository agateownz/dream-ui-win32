#include "brush.h"

Brush::Brush(int32_t r, int32_t g, int32_t b)
	: m_handle(CreateSolidBrush(RGB(r, g, b)))
{
}

Brush::~Brush()
{
	if (m_handle)
		DeleteObject(m_handle);
}

HBRUSH Brush::getHandle()
{
	return m_handle;
}

BrushPtr Brush::getDefault()
{
	auto brush = std::make_shared<Brush>(0, 0, 0);
	brush->m_handle = (HBRUSH)(COLOR_WINDOW);
	return brush;
}
