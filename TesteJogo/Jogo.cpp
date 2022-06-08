#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <list>
using namespace std;
Jogo::Jogo (){
    gerenciadorGrafico = new Gerenciador_Grafico;
    srand(time(NULL));
    faseTeste = new Fase(true, gerenciadorGrafico);

    executar();
}
Jogo::~Jogo(){
    if (gerenciadorGrafico)
        delete gerenciadorGrafico;
    if (faseTeste)
        delete faseTeste;
}
void Jogo::executar(){
    sf::Clock dt_clock;
    while (gerenciadorGrafico->janelaAberta())
    {

        float dt = dt_clock.restart().asSeconds();
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();

        faseTeste->executar(dt);

        gerenciadorGrafico->display();
    }
}