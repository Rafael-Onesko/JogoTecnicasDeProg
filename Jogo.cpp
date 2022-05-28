#include <SFML/Graphics.hpp>
#include "Jogo.h"
Jogo::Jogo (){
    player1 = new Jogador(100.f,100.f,0.7f);
    gerenciadorGrafico = new Gerenciador_Grafico;
    executar();
}
Jogo::~Jogo(){
    delete gerenciadorGrafico;
    delete player1;
}
void Jogo::executar(){
    while (gerenciadorGrafico->janelaAberta())
    {
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();
        player1->move();
        player1->getCorpo()->setPosition(sf::Vector2f(player1->getPosX(), player1->getPosY()));
        gerenciadorGrafico->draw(player1->getCorpo());
        gerenciadorGrafico->display();
    }
}