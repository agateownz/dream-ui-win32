#ifndef DREAMUI_WINDOW_H
#define DREAMUI_WINDOW_H

#include "uielement.h"

class Window : public UIElement
{
public:

	/// <summary>
	/// The window styles.
	/// </summary>
	struct WindowStyle 
	{
		static constexpr uint32_t 
			Overlapped = 0x00000000L,
			Popup = 0x80000000L,
			Child = 0x40000000L,
			Minimize = 0x20000000L,
			Visible = 0x10000000L,
			Disabled = 0x08000000L,
			ClipSiblings = 0x04000000L,
			ClipChildren = 0x02000000L,
			Maxmize = 0x01000000L,
			Caption = 0x00C00000L,
			Border = 0x00800000L,
			DialogFrame = 0x00400000L,
			VerticalScroll = 0x00200000L,
			HorizontalScroll = 0x00100000L,
			SystemMenu = 0x00080000L,
			ThickFrame = 0x00040000L,
			Group = 0x00020000L,
			TabStop = 0x00010000L,
			MinimizeBox = 0x00020000L,
			MaxmizeBox = 0x00010000L,

			// Common Styles
			OverlappedWindow = Overlapped | Caption | SystemMenu | ThickFrame | MinimizeBox | MaxmizeBox,
			PopupWindow = Popup | Border | SystemMenu,
			ChildWindow = Child;
	};

	/// <summary>
	/// The extended window style.
	/// </summary>
	struct ExWindowStyle
	{
		static constexpr uint32_t
			DialogModalFrame = 0x00000001L,
			NoParentNotify = 0x00000004L,
			TopMost = 0x00000008L,
			AcceptFiles = 0x00000010L,
			Transparent = 0x00000020L,
			MdiChild = 0x00000040L,
			ToolWindow = 0x00000080L,
			WindowEdge = 0x00000100L,
			ClientEdge = 0x00000200L,
			ContextHelp = 0x00000400L,
			// WinVer >= 0x400
			RightAlign = 0x00001000L,
			LeftAlign = 0x00000000L, // Default
			RightToLeftReading = 0x00002000L,
			LeftToRightReading = 0x00000000L, // Default
			LeftScrollBar = 0x00004000L,
			RightScrollBar = 0x00000000L, // Default
			ControlParent = 0x00010000L,
			StaticEdge = 0x00020000L,
			AppWindow = 0x00040000L,
			// WinVer >= 0x500
			Layered = 0x00080000L,
			NoInheritLayout = 0x00100000L,
			LayoutRightToLeft = 0x00400000L,
			NoActivate = 0x08000000L,
			// WinVer >= 0x501
			Composited = 0x02000000L,
			// WinVer >= 0x602
			NoRedirectionBitmap = 0x00200000L,

			// Common Styles
			OverlappedWindow = WindowEdge | ClientEdge,
			PalleteWindow = WindowEdge | ToolWindow | TopMost;
	};

	/// <summary>
	/// The window class style.
	/// </summary>
	struct ClassStyle
	{
		static constexpr uint32_t
			VerticalRedraw = 0x0001,
			HorizontalRedraw = 0x0002,
			DobleClicks = 0x0008,
			OwnDC = 0x0020,
			ClassDC = 0x0040,
			ParentDC = 0x0080,
			NoClose = 0x0200,
			SaveBits = 0x0800,
			ByteAlignClient = 0x1000,
			ByteAlignWindow = 0x2000,
			GlobalClass = 0x4000,
			DropShadow = 0x00020000;
	};

	/// <summary>
	/// Creates a new instance of Window class.
	/// </summary>
	/// <param name="classStyle">The specified <paramref name="ClassStyle"/></param>
	/// <param name="className">The name of the window class.</param>
	/// <param name="style">The window style. <paramref name="WindowStyle"/></param>
	/// <param name="exStyle">The extended window style. <paramref name="ExWindowStyle"/></param>
	/// <param name="windowTitle">The title of the window.</param>
	/// <param name="height">The height of the window.</param>
	/// <param name="width">The width of the window.</param>
	Window(
		uint32_t classStyle,
		const std::string& className,
		uint32_t style,
		uint32_t exStyle,
		const std::string& windowTitle,
		int32_t height,
		int32_t width);

	virtual ~Window();

	/// <summary>
	/// Runs the message loop for this Window.
	/// </summary>
	/// <returns>Returns true if the loop should continue.
	/// False if some errors ocurred.</returns>
	virtual bool run();

	/// <summary>
	/// Sets the window title.
	/// </summary>
	/// <param name="title">The new title.</param>
	void setWindowTitle(const std::string& title);

	/// <summary>
	/// Gets the current window title.
	/// </summary>
	/// <returns></returns>
	const std::string getWindowTitle();

protected:

	virtual bool registerWindowClass(uint32_t classStyle, const std::string& className);

private:
	HINSTANCE m_instance;
};
#endif // !DREAMUI_WINDOW_H


