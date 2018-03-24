#ifndef DREAMGUI_LABEL_H
#define DREAMGUI_LABEL_H

#include "uielement.h"

struct LabelEventArgs : public UIEventArgs
{
	LabelEventArgs(UIElementPtr& s) : UIEventArgs(s)
	{
	}
};

class Label : public UIElement
{
public:

	static constexpr uint32_t 
		LeftAlign = 0x00000000L,
		CenterAlign = 0x00000001L,
		RightAlign = 0x00000002L,
		Simple = 0x0000000BL,
		OwnerDrawn = 0x0000000DL,
		NoPrefix = 0x00000080L,
		Notify = 0x00000100L,
		Sunken = 0x00001000L,
		EditControl = 0x00002000L,
		EndEllipsis = 0x00004000L,
		PathEllipsis = 0x00008000L,
		WordEllipsis = 0x0000C000L;

	Label(
		UIElementPtr parent,
		const std::string& name, 
		const std::string& text, 
		uint32_t style,
		Vector2 size = Vector2(20, 20),
		Vector2 position = Vector2(0, 0));

	virtual ~Label();

public:
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
#endif // !DREAMGUI_LABEL_H

