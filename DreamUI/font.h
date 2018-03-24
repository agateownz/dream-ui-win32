#ifndef DREAMUI_FONT_H
#define DREAMUI_FONT_H

#include "base.h"

enum class FontWeigth
{
	Default = 0,
	Thin = 100,
	ExtraLight = 200,
	Light = 300,
	Normal = 400,
	Medium = 500,
	SemiBold = 600,
	Bold = 700,
	ExtraBold = 800,
	Heavy = 900
};

enum class FontOutputPrecision
{
	Default = 1,
	Character = 2,
	Stroke = 3,
	TrueType = 4,
	Device = 5,
	Raster = 6,
	TrueTypeOnly = 7,
	Outline = 8,
	ScreenOutline = 9,
	PostScriptOnly = 10
};

enum class FontClipPrecision
{
	Default = 0,
	Character = 1,
	Stroke = 2,
	Angles = 16,
	DisableFontAssociation = 64,
	Embedded = 128
};

enum class FontQuality
{
	Default = 0,
	Draft = 1,
	Proof = 2,
	NonAntialised = 3,
	Antialised = 4,
	ClearType = 5,
	ClearTypeNatural = 6
};

enum FontPitch
{
	Default = 0,
	Fixed = 1,
	Variable = 2
};

enum FontFamily
{
	DontCare = 0,
	Roman = 16,
	Swiss = 32,
	Modern = 48,
	Script = 64,
	Decorative = 80
};

class Font
{
public:
	Font(
		const std::string& typefaceName, 
		bool italic = false,
		bool underline = false,
		bool strikeOut = false,
		int32_t height = 0,
		int32_t width = 0,
		int32_t escapement = 0,
		int32_t orientation = 0,
		FontWeigth fontWeigth = FontWeigth::Default,
		FontOutputPrecision outputPrecision = FontOutputPrecision::Default,
		FontClipPrecision clipPrecision = FontClipPrecision::Default,
		FontQuality quality = FontQuality::Default,
		uint32_t pitchAndFamily = FontPitch::Default | FontFamily::DontCare,
		uint32_t charSet = DEFAULT_CHARSET);
	virtual ~Font();

	HFONT getHandle();

	static FontPtr getDefault();

protected:
	// Font Handle
	HFONT m_handle;

	// Font Settings
	std::string m_typefaceName;
	bool m_italic;
	bool m_strikeOut;
	bool m_underline;
	int32_t m_height;
	int32_t m_width;
	int32_t m_escapement;
	int32_t m_orientation;
	FontWeigth m_fontWeigth;
	FontOutputPrecision m_outputPrecision;
	FontClipPrecision m_clipPrecision;
	FontQuality m_quality;
	uint32_t m_pitchAndFamily;
	uint32_t m_charSet;
};
#endif // !DREAMUI_FONT_H

