#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <iostream>
using namespace std;
Jogo::Jogo (){
    entidades = new ListaEntidades;
    player1 = new Jogador(100.f,100.f,0.5f);
    enemy1 = new Inimigo (200.f, 50.f, 0.7f);
    obst1 = new Obstaculo(2400.f, 50.f);
    enemy1->setPosX(200.f);
    enemy1->setPosY(300.f);
    obst1->setPosY(600.f);
    obst1->setPosX(0.f);
    entidades->push(player1);
    entidades->push(enemy1);
    entidades->push(obst1);
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
    delete obst1;
}
void Jogo::executar(){
    while (gerenciadorGrafico->janelaAberta())
    {
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();
        player1->move();
        gerenciadorColisoes->verificarColisoes();
        gerenciadorGrafico->ajustarCamera(player1->getCorpo());
        for(int i = 0; i < entidades->getTam(); i++)
            gerenciadorGrafico->draw((*entidades)[i]->getCorpo());
        //cout << player1->getPosX() << endl;
        gerenciadorGrafico->display();
    }
}