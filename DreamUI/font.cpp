#include "font.h"

Font::Font(
	const std::string& typefaceName,
	bool italic,
	bool underline,
	bool strikeOut,
	int32_t height,
	int32_t width ,
	int32_t escapement,
	int32_t orientation,
	FontWeigth fontWeigth,
	FontOutputPrecision outputPrecision,
	FontClipPrecision clipPrecision,
	FontQuality quality,
	uint32_t pitchAndFamily,
	uint32_t charSet)
	: m_typefaceName(typefaceName)
	, m_italic(italic)
	, m_underline(underline)
	, m_strikeOut(strikeOut)
	, m_height(height)
	, m_width(width)
	, m_escapement(escapement)
	, m_orientation(orientation)
	, m_fontWeigth(fontWeigth)
	, m_outputPrecision(outputPrecision)
	, m_clipPrecision(clipPrecision)
	, m_quality(quality)
	, m_pitchAndFamily(pitchAndFamily)
	, m_charSet(charSet)
{
	m_handle = CreateFont(
		height,
		width,
		escapement,
		orientation,
		static_cast<int32_t>(fontWeigth),
		italic ? TRUE : FALSE,
		underline ? TRUE : FALSE,
		strikeOut ? TRUE : FALSE,
		charSet,
		static_cast<uint32_t>(outputPrecision),
		static_cast<uint32_t>(clipPrecision),
		static_cast<uint32_t>(quality),
		static_cast<uint32_t>(pitchAndFamily),
		typefaceName.c_str());
}

Font::~Font()
{
	if (m_handle)
		DeleteObject(m_handle);
}

HFONT Font::getHandle()
{
	return m_handle;
}

FontPtr Font::getDefault()
{
	auto font = std::make_shared<Font>(
		"Arial",
		false,
		false,
		false,
		0,
		0,
		0,
		0,
		FontWeigth::Default,
		FontOutputPrecision::Default,
		FontClipPrecision::Default,
		FontQuality::Default,
		FontPitch::Default | FontFamily::DontCare,
		DEFAULT_CHARSET);

	return font;
}
