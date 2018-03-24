#ifndef DREAMUI_BRUSH_H
#define DREAMUI_BRUSH_H

#include "base.h"

class Brush
{
public:
	Brush(int32_t r, int32_t g, int32_t b);

	virtual ~Brush();

	HBRUSH getHandle();

	static BrushPtr getDefault();
protected:
	HBRUSH m_handle;
};

#endif // !DREAMUI_BRUSH_H

