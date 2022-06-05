#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <iostream>
using namespace std;
Jogo::Jogo (){
    entidades = new ListaEntidades;
    player1 = new Jogador(100.f,100.f,200.0f);
    enemy1 = new Goblin (100.f, 100.f, player1);
    enemy2 = new Vampiro(100.f, 100.f, player1);
    enemy3 = new Dragao(player1);
    obst1 = new Obstaculo(2400.f, 50.f, plataforma);
    obst2 = new Obstaculo(100.f, 100.f, plataforma);
    enemy1->setPosX(600.f);
    enemy1->setPosY(500.f);
    enemy2->setPosX(1000.f);
    enemy2->setPosY(500.f);
    enemy3->setPosX(2000.f);
    enemy3->setPosY(0.0f);
    obst1->setPosY(600.f);
    obst1->setPosX(0.f);
    obst2->setPosY(500.f);
    obst2->setPosX(200.f);
    entidades->inserir(player1);
    entidades->inserir(obst1);
    entidades->inserir(obst2);
    entidades->inserir(enemy1);
    entidades->inserir(enemy2);
    entidades->inserir(enemy3);
    enemy1->getCorpo()->setFillColor(sf::Color::Yellow);
    enemy2->getCorpo()->setFillColor(sf::Color::Red);
    enemy3->getCorpo()->setFillColor(sf::Color::White);
    player1->getCorpo()->setFillColor(sf::Color::Green);
    obst1->getCorpo()->setFillColor(sf::Color::Cyan);
    obst2->getCorpo()->setFillColor(sf::Color::Blue);
    //obst1->getCorpo()->setTexture(gerenciadorGrafico->carregarTextura("Assets/Grama.png"));
    gerenciadorGrafico = new Gerenciador_Grafico;
    gerenciadorColisoes = new Gerenciador_Colisoes(entidades);
    for (int i = 0; i < entidades->getTam(); i++)
        (*entidades)[i]->setGerenciadorGrafico(gerenciadorGrafico);

    executar();
}
Jogo::~Jogo(){
    if(entidades)
        delete entidades;
    if(gerenciadorColisoes)
        delete gerenciadorColisoes;
    if(gerenciadorGrafico)
        delete gerenciadorGrafico;
}
void Jogo::executar(){
    sf::Clock dt_clock;
    while (gerenciadorGrafico->janelaAberta())
    {
        float dt = dt_clock.restart().asSeconds();
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();
        gerenciadorColisoes->verificarColisoes();
        for (int i = 0; i < entidades->getTam(); i++) {
           if ((*entidades)[i]->getVivo() == true) {
                   (*entidades)[i]->executar(dt);
           }
            else {
               entidades->retirar((*entidades)[i]); 
            }
        }
        gerenciadorGrafico->ajustarCamera(player1->getCorpo());
        for (int i = 0; i < entidades->getTam(); i++)
            (*entidades)[i]->imprimir_se();
        gerenciadorGrafico->display();
    }
}