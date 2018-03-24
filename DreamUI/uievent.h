#ifndef DREAMUI_UIEVENT_H
#define DREAMUI_UIEVENT_H

#include "base.h"

struct UIEventArgs
{
	UIEventArgs(UIElementPtr& s)
		: sender(s)
	{
	}
	virtual ~UIEventArgs() {}

	UIElementPtr sender;
};

struct UIEventCallback
{
	UIEventCallback(std::function<void(const UIEventArgs&)> fn)
		: handler(fn)
	{
	}
	std::function<void(const UIEventArgs&)> handler;
};

class UIEvent
{
	using UIEventList = std::vector<UIEventCallback>;
	using UIEventHandle = UIEventList::iterator;

public:
	UIEventHandle operator+=(UIEventCallback callback)
	{
		return m_subscribers.insert(m_subscribers.end(), callback);
	}

	UIEvent& operator-=(UIEventHandle handle)
	{
		m_subscribers.erase(handle);
		return *this;
	}

	void invoke(const UIEventArgs& args)
	{
		for (UIEventCallback i : m_subscribers)
			i.handler(args);
	}

protected:
	UIEventList m_subscribers;
};
#endif // !DREAMUI_UIEVENT_H