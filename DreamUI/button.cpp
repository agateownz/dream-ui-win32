#include "button.h"

Button::Button(
	UIElementPtr parent, 
	const std::string& name,
	const std::string& text, 
	uint32_t style,
	Vector2 size, 
	Vector2 position)
	: UIElement(UIElementType::Button, name, text, true, true, true, true, size, position)
{
	auto instance = GetModuleHandle(nullptr);

	m_hwnd = CreateWindowEx(
		0,
		"BUTTON",
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
		setIdealSize();
	}

}

Button::~Button()
{
}

void Button::setElevationRequired(bool value)
{
	Button_SetElevationRequiredState(m_hwnd, value);
}

void Button::setIdealSize()
{
	SIZE s;
	Button_GetIdealSize(m_hwnd, &s);

	setSize(Vector2(s.cx, s.cy));
}
