#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <iostream>
using namespace std;
Jogo::Jogo (){
    entidades = new ListaEntidades;
    player1 = new Jogador(100.f,100.f,0.7f);
    enemy1 = new Inimigo (50.f, 50.f, 0.7f);
    enemy1->setPosX(200.f);
    enemy1->setPosY(200.f);
    entidades->push(player1);
    entidades->push(enemy1);
    gerenciadorGrafico = new Gerenciador_Grafico;
    gerenciadorColisoes = new Gerenciador_Colisoes(entidades);
    cout << (*entidades)[0]->getPosX() << endl;
    cout << (*entidades)[1]->getPosX() << endl;

    executar();
}
Jogo::~Jogo(){
    delete gerenciadorGrafico;
    delete player1;
    delete enemy1;
}
void Jogo::executar(){
    while (gerenciadorGrafico->janelaAberta())
    {
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();
        gerenciadorColisoes->verificarColisoes();
        player1->move();
        gerenciadorGrafico->draw(player1->getCorpo());
        gerenciadorGrafico->draw(enemy1->getCorpo());
        gerenciadorGrafico->display();
    }
}