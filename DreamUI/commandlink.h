#ifndef DREAMUI_COMMANDLINK_H
#define DREAMUI_COMMANDLINK_H

#include "uielement.h"

class CommandLink : public UIElement
{
public:

	static constexpr uint32_t
		Default = 0x0000000FL,
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

	CommandLink(
		UIElementPtr parent,
		const std::string& name,
		const std::string& text,
		const std::string& note,
		uint32_t style,
		Vector2 size = Vector2(0, 0),
		Vector2 position = Vector2(0, 0));

	virtual ~CommandLink();

	void setNote(const std::string& note);

	const std::string getNote();

	void setElevationRequired(bool value);

protected:
	std::string m_note;

	// Events
public:
	UIEvent Click;

	virtual void onClick() final
	{
		this->Click.invoke(shared_from_this());
	}
};
#endif // !DREAMUI_COMMANDLINK_H

