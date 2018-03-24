#ifndef DREAMGUI_ENUMHELPER_H
#define DREAMGUI_ENUMHELPER_H

#include "base.h"

template<typename T>
inline T enumValue(T first, T second)
{
	auto firstValue = static_cast<std::underlying_type<T>::type>(first);
	auto secondValue = static_cast<std::underlying_type<T>::type>(second);

	return static_cast<T>(firstValue | secondValue);
}

template<typename T, typename ...R>
inline T enumValue(T first, T second, R ...tail)
{
	return enumValue(first, enumValue(second, tail...));
}

#endif // !DREAMGUI_ENUMHELPER_H

