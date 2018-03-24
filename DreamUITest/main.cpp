#include <dreamui.h>
#include <iostream>

#pragma comment( lib, "comctl32.lib") 

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")  


int main(int argc, char** argv)
{
	InitCommonControls();

	auto window = std::make_shared<Window>(
		Window::ClassStyle::DobleClicks | Window::ClassStyle::DropShadow,
		"MainWindow", 
		Window::WindowStyle::OverlappedWindow | Window::WindowStyle::ClipSiblings,
		Window::ExWindowStyle::OverlappedWindow | Window::ExWindowStyle::ControlParent,
		"TestWindow", 
		800, 
		600);

	auto label = std::make_shared<Label>(
		window,
		"label1",
		"This is a label.",
		Label::Simple | Label::Notify,
		Vector2(0, 0),
		Vector2(200, 10));
	
	auto groupBox = std::make_shared<GroupBox>(
		window,
		"groupbox1",
		"This is a group box.",
		Vector2(200, 200),
		Vector2(80, 80));

	auto button = std::make_shared<Button>(
		window,
		"button1",
		"Click me",
		Button::Notify,
		Vector2(30, 30),
		Vector2(100, 100));
	button->setElevationRequired(true);
	button->setIdealSize();

	auto cmdLink = std::make_shared<CommandLink>(
		window,
		"commandlink1",
		"This is a sample button.",
		"This is a caption text.",
		CommandLink::Notify,
		Vector2(200, 150),
		Vector2(350, 100));

	button->Click += UIEventCallback([](const UIEventArgs& e) {
		std::cout << e.sender->getName() << " foi clicado." << std::endl;
	});

	cmdLink->Click += UIEventCallback([](const UIEventArgs& e) {
		std::cout << e.sender->getName() << " foi clicado." << std::endl;
	});

	window->addChild(cmdLink);
	window->addChild(label);
	window->addChild(button);
	window->addChild(groupBox);

	
	while (window->run()) {

		continue;
	}
	return 0;
}