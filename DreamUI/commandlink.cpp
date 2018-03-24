#include "commandlink.h"


CommandLink::CommandLink(
	UIElementPtr parent, 
	const std::string& name, 
	const std::string& text, 
	const std::string& note, 
	uint32_t style, 
	Vector2 size, 
	Vector2 position)
	: UIElement(UIElementType::CommandLink, name, text, true, true, true, true, size, position)
	, m_note(note)
{
	auto instance = GetModuleHandle(nullptr);

	bool hasDefCmdLink = false;

	if (style & BS_DEFCOMMANDLINK)
		hasDefCmdLink = true;

	if (hasDefCmdLink)
		style |= WS_TABSTOP;
	else
		style |= BS_COMMANDLINK | WS_TABSTOP;


	m_hwnd = CreateWindowEx(
		0,
		"BUTTON",
		text.c_str(),
		style,
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

		auto str = stringToWString(m_note);
		Button_SetNote(m_hwnd, str.c_str());
	}
}

CommandLink::~CommandLink()
{
}

void CommandLink::setNote(const std::string& note)
{
	m_note = note;
	Button_SetNote(m_hwnd, stringToWString(m_note).c_str());
}

const std::string CommandLink::getNote()
{
	int32_t length = Button_GetNoteLength(m_hwnd);

	if (length <= 0)
		return m_note;
	
	auto strPtr = std::unique_ptr<wchar_t>(new wchar_t[length + 1]);

	length++;

	Button_GetNote(m_hwnd, strPtr.get(), &length);

	auto tmp = std::wstring(strPtr.get());

	m_note = wstringToString(tmp);

	return m_note;
}

void CommandLink::setElevationRequired(bool value)
{
	Button_SetElevationRequiredState(m_hwnd, value);
}
