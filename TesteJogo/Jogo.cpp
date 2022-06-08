#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <list>
using namespace std;
void randomiza(string coisa, vector<string>* vetor) {
    int num = rand() % 2 + 3;
    int pos = rand() % 23 + 1;
    for (int i = 0; i < num; i++) {
        while ((*vetor)[pos] != " ") {
            pos = rand() % 24;
        }
        (*vetor)[pos] = coisa;

    }
}
Jogo::Jogo (){
    /*entidades = new ListaEntidades;
    player1 = new Jogador(100.f,100.f,200.0f);*/
    gerenciadorGrafico = new Gerenciador_Grafico;
    srand(time(NULL));
    faseTeste = new Fase(false, gerenciadorGrafico);

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
        //float dt = gerenciadorGrafico->getDt();
        float dt = dt_clock.restart().asSeconds();
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();

        faseTeste->executar(dt);
        /*gerenciadorColisoes->verificarColisoes();
        for (int i = 0; i < entidades->getTam(); i++) {
            if ((*entidades)[i]->getVivo() == true) {
                if (((*entidades)[i]->getDireita() > gerenciadorGrafico->getEsquerdaCamera()) ||
                    ((*entidades)[i]->getPosX() < gerenciadorGrafico->getDireitaCamera()))
                (*entidades)[i]->executar(dt);
           }
            else {
               entidades->retirar((*entidades)[i]);
            }
        }


        for (int i = 0; i < entidades->getTam(); i++) {
            if(((*entidades)[i]->getDireita()> gerenciadorGrafico->getEsquerdaCamera()) ||
                ((*entidades)[i]->getPosX()  < gerenciadorGrafico->getDireitaCamera()))
            (*entidades)[i]->imprimir_se();
        }*/
        gerenciadorGrafico->display();
    }
}