#ifndef DREAMUI_BASE_H
#define DREAMUI_BASE_H

// Base Windows include.
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <commctrl.h>

// C Headers
#include <cstdint>

// STL Headers
#include <string>
#include <list>
#include <vector>
#include <memory>
#include <typeinfo>
#include <functional>
#include <map>
#include <initializer_list>
#include <type_traits>
#include <locale>
#include <codecvt>

// Foward declarations & usings
class UIElement;
using UIElementPtr = std::shared_ptr<UIElement>;

class Window;
using WindowPtr = std::shared_ptr<Window>;

class Label;
using LabelPtr = std::shared_ptr<Label>;

class Button;
using ButtonPtr = std::shared_ptr<Button>;

class GroupBox;
using GroupBoxPtr = std::shared_ptr<GroupBox>;

class CommandLink;
using CommandLinkPtr = std::shared_ptr<CommandLink>;

class Brush;
using BrushPtr = std::shared_ptr<Brush>;

class Font;
using FontPtr = std::shared_ptr<Font>;

class UIEvent;
struct UIEventArgs;
struct UIEventCallback;

struct MouseButton
{
	static constexpr uint32_t
		LeftButton = 0,
		MiddleButton = 1,
		RightButton = 2;
};

template<typename T>
inline T* getWindowLongPtr(HWND hwnd)
{
	return reinterpret_cast<T*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
}

inline std::wstring stringToWString(const std::string& str)
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
}
inline std::string wstringToString(const std::wstring& str)
{
	return std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>>().to_bytes(str);
}

#endif // !DREAMUI_BASE_H

