#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "SobreMenu.h"
#include "ComoMenu.h"
#include "RankingMenu.h"
#include "FasesMenu.h"
#include "JogadoresMenu.h"

int gerenciador()
{
	int activeMenu=1;
	MainMenu* menu = new MainMenu();
	menu->run_menu();
	while (activeMenu==1)
	{
		sf::Event event;
		while (menu->window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				menu->window->close();
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					menu->moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					menu->moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return) 
				{
					
					SobreMenu* menuS = new SobreMenu();
					ComoMenu* menuC = new ComoMenu();
					RankingMenu* menuR = new RankingMenu();
					JogadoresMenu* menuJ = new JogadoresMenu();
					FasesMenu* menuF = new FasesMenu();

					int x = menu->returnPos();
					//Jogar->selecionaJogadores->selecionaFase->Play
					/*
					if (x == 1)
					{
						menuJ->run_menu();
						while (menuJ->returnState()) {
							sf::Event aevent;
							while (menuJ->window->pollEvent(aevent))
							{

								if (event.type == sf::Event::Closed)
								{
									menuJ->window->close();
								}
								menu->close_menu();
								menuJ->run_menu();
								if (aevent.type == sf::Event::KeyPressed) {
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										menuJ->close_menu();
										gerenciador();

									}
								}
							}
						}
					}
					*/
					//Como Jogar
					
					if (x == 2)
					{
						menu->close_menu();
						menuC->run_menu();
						while (menuC->returnState()) {
							sf::Event aevent;
							while (menuC->window->pollEvent(aevent))
							{
								if (event.type == sf::Event::Closed)
								{
									menuC->window->close();
								}
								if (aevent.type == sf::Event::KeyPressed) {
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										menuC->close_menu();
										gerenciador();

									}
								}
							}
						}
					}
					
					//Sobre
					
					if (x == 3)
					{
						menuS->run_menu();
						while (menuS->returnState()) {
							sf::Event aevent;
							while (menuS->window->pollEvent(aevent))
							{

								if (event.type == sf::Event::Closed)
								{
									menuS->window->close();
								}
								menu->close_menu();
								menuS->run_menu();
								if (aevent.type == sf::Event::KeyPressed) {
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										menuS->close_menu();
										gerenciador();

									}
								}
							}
						}
					}
				
					//Ranking
					/*
					if (x == 4)
					{
						menuR->run_menu();
						while (menuR->returnState()) {
							sf::Event aevent;
							while (menuR->window->pollEvent(aevent))
							{

								if (event.type == sf::Event::Closed)
								{
									menuR->window->close();
								}
								menu->close_menu();
								menuR->run_menu();
								if (aevent.type == sf::Event::KeyPressed) {
									if (aevent.key.code == sf::Keyboard::Escape)
									{
										menuR->close_menu();
										gerenciador();

									}
								}
							}
						}
					}
					*/
					//Sair
					if (x == 5) 
					{

						delete menu;
						delete menuS;
						delete menuC;
						delete menuR;
						delete menuJ;
						delete menuF;
						menu = nullptr;
						menuS = nullptr;
						menuC = nullptr;
						menuR = nullptr;
						menuJ = nullptr;
						menuF = nullptr;
						return EXIT_SUCCESS;
					}

				}
			}
		}
	}
}