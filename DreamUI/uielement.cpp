#include "uielement.h"
#include "label.h"
#include "button.h"
#include "groupbox.h"

UIElement::UIElement(
	UIElementType type,
	const std::string& name,
	const std::string& text,
	bool isControl,
	bool isVisible,
	bool isEnabled,
	bool hasFocus,
	Vector2 size,
	Vector2 position,
	UIElementPtr parent,
	FontPtr font,
	BrushPtr brush)
	: m_type(type)
	, m_id(0)
	, m_isVisible(isVisible)
	, m_isEnabled(isEnabled)
	, m_isControl(isControl)
	, m_hasFocus(hasFocus)
	, m_name(name)
	, m_text(text)
	, m_hwnd(nullptr)
	, m_parent(parent)
	, m_children()
	, m_position(position)
	, m_size(size)
	, m_backgroundBrush(brush)
	, m_font(font)
{
}

UIElement::~UIElement()
{
	::CloseWindow(m_hwnd);
}

void UIElement::initialize()
{
	::SetWindowLongPtr(m_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	m_id = GetWindowLong(m_hwnd, GWL_ID);

	m_isEnabled ? enable() : disable();
	
	m_isVisible ? show() : hide();

	setFont(m_font != nullptr ? m_font : Font::getDefault());

	setBackgroundBrush(m_backgroundBrush != nullptr ? m_backgroundBrush : Brush::getDefault());

	if (m_position != Vector2(0, 0))
		setPosition(m_position);
	
	if (m_size != Vector2(0, 0))
		setSize(m_size);

	m_hasFocus ? focus() : removeFocus();

	BringWindowToTop(m_hwnd);
}

void UIElement::show()
{
	::ShowWindow(m_hwnd, SW_NORMAL);

	m_isVisible = true;
}

void UIElement::hide()
{
	auto wasVisible = ::ShowWindow(m_hwnd, SW_HIDE);
	
	m_isVisible = false;
}

bool UIElement::isVisible()
{
	return m_isVisible;
}

void UIElement::enable()
{
	::EnableWindow(m_hwnd, true);

	m_isEnabled = true;
}

void UIElement::disable()
{
	::EnableWindow(m_hwnd, false);

	m_isEnabled = false;
}

bool UIElement::isEnabled()
{
	return (m_isEnabled = (::IsWindowEnabled(m_hwnd) != 0 ? true : false));
}

void UIElement::setParent(UIElementPtr parent)
{
	if (parent == m_parent) // is the same parent
		return;

	if (m_parent != nullptr) // already have a parent
	{
		m_parent->removeChild(shared_from_this());
		m_parent = nullptr;
	}

	if (parent == nullptr)
	{
		::SetParent(m_hwnd, 0);
		removeStyle(WS_CHILD);
	}
	else
	{
		addStyle(WS_CHILD);
		removeStyle(WS_CAPTION);

		m_parent = parent;
		
		::SetParent(m_hwnd, parent->getHandle());
	}

	if (m_parent != nullptr)
	{
		redraw();
	}
}

UIElementPtr UIElement::getParent()
{
	return m_parent;
}

void UIElement::addChild(UIElementPtr child)
{
	if (child->getParent() != shared_from_this())
		child->setParent(shared_from_this());
	else
		m_children.push_back(child);
}

void UIElement::removeChild(UIElementPtr child)
{
	auto it = std::find(m_children.begin(), m_children.end(), shared_from_this());
	if (it != m_children.end())
		m_children.erase(it);

	if (child->getParent() == shared_from_this())
		child->setParent(nullptr);
}

UIElementPtr UIElement::getChildByName(const std::string& name)
{
	UIElementPtr ptr = nullptr;
	for (auto& child : m_children)
	{
		if (child->m_name == name)
			ptr = child;
	}
	return ptr;
}

UIElementPtr UIElement::getChildByHandle(HWND hwnd)
{
	UIElementPtr ptr = nullptr;

	for (auto& child : m_children)
	{
		if (child->m_hwnd == hwnd)
			ptr = child;
	}
	return ptr;
}

UIElementPtr UIElement::getChildById(int32_t id)
{
	UIElementPtr ptr = nullptr;

	for (auto& child : m_children)
	{
		if (child->m_id == id)
			ptr = child;
	}
	return ptr;
}

const std::string UIElement::getName()
{
	return m_name;
}

void UIElement::setBackgroundBrush(BrushPtr brush)
{
	if (brush == nullptr)
		m_backgroundBrush = Brush::getDefault();
	else
		m_backgroundBrush = brush;
}

uint32_t UIElement::getStyle()
{
	return ::GetWindowLong(m_hwnd, GWL_STYLE);
}

void UIElement::setStyle(uint32_t style)
{
	::SetWindowLong(m_hwnd, GWL_STYLE, style);
}

void UIElement::addStyle(uint32_t style)
{
	setStyle(getStyle() | style);
}

void UIElement::removeStyle(uint32_t style)
{
	setStyle(getStyle() & (~style));
}

HWND UIElement::getHandle()
{
	return m_hwnd;
}

void UIElement::setFont(FontPtr font, bool redraw)
{
	::SendMessage(m_hwnd, WM_SETFONT, (WPARAM)(font->getHandle()), redraw);
	m_font = font;
}

FontPtr UIElement::getFont()
{
	return m_font;
}

void UIElement::setPosition(Vector2 position)
{
	m_position = position;
	::SetWindowPos(m_hwnd, 0, m_position.getX(), m_position.getY(), 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

Vector2 UIElement::getPosition()
{
	return m_position;
}

void UIElement::setSize(Vector2 size)
{
	m_size = size;
	::SetWindowPos(m_hwnd, 0, 0, 0, m_size.getX(), m_size.getY(), SWP_NOMOVE | SWP_NOZORDER);
}

Vector2 UIElement::getSize()
{
	return m_size;
}

void UIElement::setText(const std::string& text)
{
	m_text = text;
	
	SetWindowText(m_hwnd, m_text.c_str());
}

const std::string UIElement::getText()
{
	auto length = GetWindowTextLength(m_hwnd);

	auto str = std::unique_ptr<char>(new char[length + 1]);

	GetWindowText(m_hwnd, str.get(), length + 1);

	m_text = std::string(str.get());

	return m_text;
}

UIElementType UIElement::getType()
{
	return m_type;
}

int32_t UIElement::getId()
{
	return m_id;
}

BrushPtr UIElement::getBackgroundBrush()
{
	return m_backgroundBrush;
}

void UIElement::focus()
{
	SetFocus(m_hwnd);

	m_hasFocus = true;
}

void UIElement::removeFocus()
{
	SetFocus(nullptr);

	m_hasFocus = false;
}

bool UIElement::hasFocus()
{
	return m_hasFocus;
}

void UIElement::redraw()
{
	::InvalidateRect(m_hwnd, nullptr, true);
}

void UIElement::destroy()
{
	if (m_hwnd)
	{
		DestroyWindow(m_hwnd);
		m_hwnd = nullptr;
	}
}

void UIElement::update()
{
}

LRESULT UIElement::baseMessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	auto element = getWindowLongPtr<UIElement>(hwnd);

	if (element != nullptr)
	{
		switch (msg)
		{
		case WM_CTLCOLORSTATIC:
		case WM_CTLCOLORBTN:
		case WM_CTLCOLOREDIT:
		case WM_CTLCOLORLISTBOX:
		case WM_CTLCOLORSCROLLBAR:
		{
			auto control = getWindowLongPtr<UIElement>(reinterpret_cast<HWND>(lParam));

			if (control != nullptr && control->getBackgroundBrush() != nullptr)
				return reinterpret_cast<INT_PTR>(control->getBackgroundBrush()->getHandle());

			break;
		}
		case WM_COMMAND:
		{
			auto control = element->getChildByHandle(reinterpret_cast<HWND>(lParam));
			if (control == nullptr)
				break;

			switch (control->getType())
			{
			case UIElementType::None:
				break;

			case UIElementType::Label:

				switch (HIWORD(wParam))
				{
				case STN_CLICKED:
					control->onClick();
					break;

				case STN_DBLCLK:
					control->onDoubleClick();
					break;

				case STN_DISABLE:
					control->onEnableChanged();
					break;

				case STN_ENABLE:
					control->onEnableChanged();
					break;
				}
				break;
			case UIElementType::CommandLink:
			case UIElementType::Button:
				
				switch (HIWORD(wParam))
				{
				case BN_CLICKED:
					control->onClick();
					break;

				case BN_DOUBLECLICKED:
					control->onDoubleClick();
					break;

				case BN_KILLFOCUS:
					control->onLostFocus();
					break;

				case BN_SETFOCUS:
					control->onFocus();
					break;

				}
				break;

			case UIElementType::Window:
				break;
			}
			
			break;
		}
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_CLOSE:
			element->destroy();
			break;

		default:
			break;
		}
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}
