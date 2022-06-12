#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int gerenciador()
{
	MainMenu* menu = new MainMenu();
	menu->run_menu();
	delete menu;
	return EXIT_SUCCESS;
	menu = nullptr;
}