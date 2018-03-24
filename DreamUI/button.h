#ifndef DREAMGUI_BUTTON_H
#define DRAEMGUI_BUTTON_H

#include "uielement.h"

struct ButtonClickEventArgs : public UIEventArgs 
{
	ButtonClickEventArgs(UIElementPtr& s) : UIEventArgs(s)
	{
	}
};

class Button : public UIElement
{
public:

	static constexpr uint32_t
		Default = 0x00000001L,
		OwnerDraw = 0x0000000BL,
		Text = 0x00000000L,
		Icon = 0x00000040L,
		Bitmap = 0x00000080L,
		LeftAlign = 0x00000100L,
		RightAlign = 0x00000200L,
		CenterAlign = 0x00000300L,
		TopAlign = 0x00000400L,
		BottomAlign = 0x00000800L,
		VerticalCenter = 0x00000C00L,
		PushLike = 0x00001000L,
		MultiLine = 0x00002000L,
		Notify = 0x00004000L,
		Flat = 0x00008000L;

	Button(
		UIElementPtr parent,
		const std::string& name,
		const std::string& text,
		uint32_t style,
		Vector2 size = Vector2(0, 0),
		Vector2 position = Vector2(0, 0));

	virtual ~Button();

	void setElevationRequired(bool value);

	void setIdealSize();

public:
	/* Events */

	UIEvent Click;
	UIEvent DoubleClick;
	UIEvent EnableChanged;
	UIEvent Focus;
	UIEvent LostFocus;

	virtual void onClick() final
	{
		this->Click.invoke(shared_from_this());
	}
	virtual void onDoubleClick() final
	{
		this->DoubleClick.invoke(shared_from_this());
	}
	virtual void onEnableChanged() final
	{
		this->EnableChanged.invoke(shared_from_this());
	}
	virtual void onFocus() final
	{
		this->Focus.invoke(shared_from_this());
	}
	virtual void onLostFocus() final
	{
		this->LostFocus.invoke(shared_from_this());
	}
};

#endif // !DREAMGUI_BUTTON_H

