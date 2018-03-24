#ifndef DREAMUI_UIELEMENT_H
#define DREAMUI_UIELEMENT_H

#include "base.h"
#include "vector2.h"
#include "brush.h"
#include "font.h"
#include "enumhelper.h"
#include "uievent.h"

/// <summary>
/// The types of UIElements.
/// </summary>
enum class UIElementType
{
	None = -1,
	Window,
	Label,
	Button,
	GroupBox,
	CommandLink,
};

/// <summary>
/// Base UIElement.
/// </summary>
class UIElement : public std::enable_shared_from_this<UIElement>
{
public:
	/// <summary>
	/// Show the UIElement.
	/// </summary>
	void show();

	/// <summary>
	/// Hides the UIElement.
	/// </summary>
	void hide();

	/// <summary>
	/// Gets the visibility status of this UIElement.
	/// </summary>
	/// <returns>True if is visible, false otherwise.</returns>
	bool isVisible();

	/// <summary>
	/// Enables the current UIElement.
	/// </summary>
	virtual void enable();

	/// <summary>
	/// Disables the current UIElement.
	/// </summary>
	virtual void disable();

	/// <summary>
	/// Gets the enabled status of this UIElement.
	/// </summary>
	/// <returns>Return true if is enabled, false otherwise.</returns>
	virtual bool isEnabled();

	/// <summary>
	/// Sets the parent of this UIElement.
	/// </summary>
	/// <param name="parent">A pointer to the parent.</param>
	void setParent(UIElementPtr parent);

	/// <summary>
	/// Gets the parent of this UIElement.
	/// </summary>
	/// <returns>Returns the parent of this UIElement.</returns>
	UIElementPtr getParent();

	/// <summary>
	/// Adds a child UIElement.
	/// </summary>
	/// <param name="child">A pointer to the child.</param>
	void addChild(UIElementPtr child);

	/// <summary>
	/// Removes a child from this UIElement.
	/// </summary>
	/// <param name="child">A pointer to the child to be removed.</param>
	void removeChild(UIElementPtr child);

	/// <summary>
	/// Gets a child by its name.
	/// </summary>
	/// <param name="name">The name of the child.</param>
	/// <returns>Returns a pointer to the child.</returns>
	UIElementPtr getChildByName(const std::string& name);

	/// <summary>
	/// Gets a child by its window handle.
	/// </summary>
	/// <param name="hwnd">The window handle.</param>
	/// <returns>Returns a pointer to the child.</returns>
	UIElementPtr getChildByHandle(HWND hwnd);

	/// <summary>
	/// Gets a child by its identifier.
	/// </summary>
	/// <param name="id">The identifier associated with the window.</param>
	/// <returns>Returns a pointer to the child.</returns>
	UIElementPtr getChildById(int32_t id);

	/// <summary>
	/// Gets the name of this UIElement.
	/// </summary>
	/// <returns>Returns the unique name of this UIElement.</returns>
	const std::string getName();

	/// <summary>
	/// Sets the background brush.
	/// </summary>
	/// <param name="brush">A pointer to the brush.</param>
	void setBackgroundBrush(BrushPtr brush);

	/// <summary>
	/// Gets the current UIElement style.
	/// </summary>
	/// <returns>Returns the current UIElement style.</returns>
	uint32_t getStyle();

	/// <summary>
	/// Sets the style of the UIElement.
	/// </summary>
	/// <param name="style">The new style.</param>
	void setStyle(uint32_t style);

	/// <summary>
	/// Add some style flags to the actual style.
	/// </summary>
	/// <param name="style">The style flag to be appended.</param>
	void addStyle(uint32_t style);

	/// <summary>
	/// Remove some existing style flag from the actual style.
	/// </summary>
	/// <param name="style">The style flag to be removed.</param>
	void removeStyle(uint32_t style);
	
	/// <summary>
	/// Gets the native window handle.
	/// </summary>
	/// <returns>Returns the native window handle.</returns>
	HWND getHandle();

	/// <summary>
	/// Sets the Font used to draw text in this UIElement.
	/// </summary>
	/// <param name="font">A pointer to the font.</param>
	/// <param name="redraw">If true, will redraw the entire window.</param>
	void setFont(FontPtr font, bool redraw = true);

	/// <summary>
	/// Gets the current Font used to draw text in this UIElement.
	/// </summary>
	/// <returns>Returns a pointer to the current Font.</returns>
	FontPtr getFont();

	/// <summary>
	///  Sets the position of the UIElement.
	/// </summary>
	/// <param name="position">A vector containing the new position.</param>
	void setPosition(Vector2 position);

	/// <summary>
	/// Gets the current position of this UIElement.
	/// </summary>
	/// <returns>Returns a vector containing the current position.</returns>
	Vector2 getPosition();

	/// <summary>
	/// Sets the size of the UIElement.
	/// </summary>
	/// <param name="size">A vector containing the new size.</param>
	void setSize(Vector2 size);

	/// <summary>
	/// Gets the current size of this UIElement.
	/// </summary>
	/// <returns>Returns a vector containing the size.</returns>
	Vector2 getSize();

	/// <summary>
	/// Sets the text associated with this UIElement.
	/// </summary>
	/// <param name="text">The new text.</param>
	void setText(const std::string& text);

	/// <summary>
	/// Gets the text associated with this UIElement.
	/// </summary>
	/// <returns></returns>
	const std::string getText();

	/// <summary>
	/// Gets the type of this UIElement.
	/// </summary>
	/// <returns>Returns the type of this UIElement.</returns>
	UIElementType getType();

	/// <summary>
	/// Gets the ID of this UIElement.
	/// </summary>
	/// <returns>Returns the ID associated with this UIElement.</returns>
	int32_t getId();

	/// <summary>
	/// Gets the background brush pointer.
	/// </summary>
	/// <returns>Returns the current background brush pointer.</returns>
	BrushPtr getBackgroundBrush();

	/// <summary>
	/// Focus the current UIElement.
	/// </summary>
	void focus();

	/// <summary>
	/// Remove the focus from the current UIElement.
	/// </summary>
	void removeFocus();

	/// <summary>
	/// Gets a value that indicate wheter or not this UIElement has focus.
	/// </summary>
	/// <returns>Returns true if the UIElement has focus, false otherwise.</returns>
	bool hasFocus();

	/// <summary>
	/// Redraws the entire UIElement.
	/// </summary>
	void redraw();

	/// <summary>
	/// Destroy the UIElement.
	/// </summary>
	void destroy();

	/// <summary>
	/// Updates the current UIElement.
	/// </summary>
	virtual void update();

protected:
	UIElement(
		UIElementType type,
		const std::string& name,
		const std::string& text = "",
		bool isControl = true,
		bool isVisible = true,
		bool isEnabled = true,
		bool hasFocus = true,
		Vector2 size = Vector2(800, 600),
		Vector2 position = Vector2(0, 0),
		UIElementPtr parent = nullptr,
		FontPtr font = nullptr,
		BrushPtr brush = nullptr);

	virtual ~UIElement();
	
	/// <summary>
	/// Initialize the UIElement.
	/// </summary>
	void initialize();

	/// <summary>
	/// The default WindowProcedure.
	/// </summary>
	/// <param name="hwnd">The window that sent the message.</param>
	/// <param name="msg">The id of the message.</param>
	/// <param name="wParam">The wParam (usually handles or integers).</param>
	/// <param name="lParam">The lParam (usually pointers).</param>
	/// <returns></returns>
	static LRESULT CALLBACK baseMessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	/// <summary>
	/// The text associated with this UIElement.
	/// </summary>
	std::string m_text;

	/// <summary>
	/// The visibility state of this UIElement.
	/// </summary>
	bool m_isVisible;

	/// <summary>
	/// The enabled state of this UIElement.
	/// </summary>
	bool m_isEnabled;

	/// <summary>
	/// The focus state of this UIElement.
	/// </summary>
	bool m_hasFocus;

	/// <summary>
	/// The name of this UIElement. (used to identify it)
	/// </summary>
	std::string m_name;

	/// <summary>
	/// The window handle for this UIElement.
	/// </summary>
	HWND m_hwnd;

	/// <summary>
	/// The parent of this UIElement.
	/// </summary>
	UIElementPtr m_parent;

	/// <summary>
	/// The children of this UIElement.
	/// </summary>
	std::vector<UIElementPtr> m_children;

	/// <summary>
	/// The position of this UIElement.
	/// </summary>
	Vector2 m_position;
	/// <summary>
	/// The size of this UIElement.
	/// </summary>
	Vector2 m_size;

	/// <summary>
	/// The background brush of this UIElement.
	/// </summary>
	BrushPtr m_backgroundBrush;

	/// <summary>
	/// The font used to draw text for this UIElement.
	/// </summary>
	FontPtr m_font;

	/// <summary>
	/// The value that tells if this UIElement is a control or a window.
	/// </summary>
	bool m_isControl;

	/// <summary>
	/// The type of this UIElement. Used in the MainWndProc.
	/// </summary>
	UIElementType m_type;

	/// <summary>
	/// The identifier of the UIElement.
	/// </summary>
	int32_t m_id;

protected:
	// Virtual Functions

	/// <summary>
	/// The user has clicked this control.
	/// </summary>
	virtual void onClick() {}
	/// <summary>
	/// The user has double clicked this control.
	/// </summary>
	virtual void onDoubleClick() {}

	/// <summary>
	/// The enable state has been changed.
	/// </summary>
	virtual void onEnableChanged() {}

	/// <summary>
	/// The control has got focus
	/// </summary>
	virtual void onFocus() {}

	/// <summary>
	/// The control has lost focus.
	/// </summary>
	virtual void onLostFocus() {}

};


#endif // !DREAMUI_UIELEMENT_H

