#ifndef DREAMUI_GROUPBOX_H
#define DREAMUI_GROUPBOX_H

#include "uielement.h"

class GroupBox : public UIElement
{
public:

	static constexpr uint32_t
		Left = 0x00000100L,
		Right = 0x00000200L,
		Center = 0x00000300L;

	GroupBox(
		UIElementPtr parent,
		const std::string& name,
		const std::string& text,
		Vector2 size = Vector2(0, 0),
		Vector2 position = Vector2(0, 0));

	virtual ~GroupBox();
};
#endif // !DREAMUI_GROUPBOX_H

