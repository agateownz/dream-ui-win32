#include "groupbox.h"

GroupBox::GroupBox(
	UIElementPtr parent, 
	const std::string& name, 
	const std::string& text, 
	Vector2 size, 
	Vector2 position)
	: UIElement(UIElementType::GroupBox, name, text, true, true, true, true, size, position)
{
	auto instance = GetModuleHandle(nullptr);

	m_hwnd = CreateWindowEx(
		0,
		"BUTTON",
		text.c_str(),
		WS_TABSTOP | BS_GROUPBOX | WS_VISIBLE,
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
	}
}

GroupBox::~GroupBox()
{
}
