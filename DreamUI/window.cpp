#include "window.h"

Window::Window(
	uint32_t classStyle,
	const std::string& className,
	uint32_t style,
	uint32_t exStyle,
	const std::string& windowTitle,
	int32_t height,
	int32_t width)
	: UIElement(UIElementType::Window, className, windowTitle, false)
	, m_instance(GetModuleHandle(nullptr))
{
	if (registerWindowClass(classStyle, className))
	{
		m_hwnd = CreateWindowEx(
			exStyle,
			className.c_str(),
			windowTitle.c_str(),
			style,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			height,
			width,
			nullptr,
			nullptr,
			m_instance,
			nullptr);

		if (m_hwnd)
		{
			m_size = Vector2(height, width);
			initialize();
		}
	}
}

Window::~Window()
{
	destroy();
}

bool Window::run()
{
	MSG msg;

	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		if (!IsDialogMessage(m_hwnd, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	if (msg.message == WM_QUIT)
		return false;

	// se o parent for nullptr, ele não está junto com os child
	if (m_parent == nullptr)
		update();

	for (auto& i : m_children)
		i->update();

	return true;
}

void Window::setWindowTitle(const std::string& title)
{
	setText(title);
}

const std::string Window::getWindowTitle()
{
	return getText();
}

bool Window::registerWindowClass(uint32_t classStyle, const std::string& className)
{
	WNDCLASSEX wc { sizeof(WNDCLASSEX) };
	wc.style = classStyle;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(0);
	wc.hIcon = 0;
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = className.c_str();
	wc.lpszMenuName = 0;
	wc.hIconSm = 0;
	wc.lpfnWndProc = reinterpret_cast<WNDPROC>(UIElement::baseMessageHandler);
	
	return RegisterClassEx(&wc) != 0 ? true : false;
}
