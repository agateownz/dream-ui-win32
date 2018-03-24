#include "label.h"

Label::Label(
	UIElementPtr parent, 
	const std::string& name, 
	const std::string& text,
	uint32_t style,
	Vector2 size,
	Vector2 position)
	: UIElement(UIElementType::Label, name, text, true, true, true, true, size, position)
{
	auto instance = GetModuleHandle(nullptr);

	m_hwnd = CreateWindowEx(
		0,
		"STATIC",
		text.c_str(),
		style | WS_TABSTOP,
		position.getX(),
		position.getY(),
		size.getX(),
		size.getY(),
		nullptr,
		nullptr,
		instance,
		nullptr);

	if (m_hwnd)
	{
		initialize();
		setParent(parent);
		setText(text);
	}
}

Label::~Label()
{
}
