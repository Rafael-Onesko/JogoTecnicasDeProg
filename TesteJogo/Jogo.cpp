#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <iostream>
using namespace std;

Gerenciador_Grafico* Jogo::gerenciadorGrafico = new Gerenciador_Grafico();
Gerenciador_Grafico* Jogo::getGerenciadorGrafico() {
    return gerenciadorGrafico;
}
Jogo::Jogo (){
    //gerenciadorGrafico = new Gerenciador_Grafico;
    srand(time(NULL));
    faseFloresta = new Fase_Floresta(true);
    faseCastelo = nullptr;
    fasePrimeira = true;
    executar();
}
Jogo::~Jogo(){
    if (gerenciadorGrafico)
        delete gerenciadorGrafico;
    if (faseFloresta)
        delete faseFloresta;
    if (faseCastelo)
        delete faseCastelo;
}
void Jogo::executar(){
    sf::Clock dt_clock;
    //Fase_Castelo* faseProxima = nullptr;
    //Fase* faseProxima = nullptr;
    faseAtual = faseFloresta;
    while (gerenciadorGrafico->janelaAberta())
    {

        float dt = dt_clock.restart().asSeconds();
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();
        if( (faseAtual) && faseAtual->getFim() == false)
            faseAtual->executar(dt);
        else if(fasePrimeira) {
            if (faseAtual == faseFloresta) {
                delete faseFloresta;
                faseFloresta = nullptr;
            }
            faseCastelo = new Fase_Castelo(true);
            faseAtual = faseCastelo;
            fasePrimeira = false;
        }
        else {
            Jogo::getGerenciadorGrafico()->clear();
            if (faseAtual) {
                delete faseAtual;
                faseCastelo = nullptr;
                faseAtual = nullptr;
            }
        }

        gerenciadorGrafico->display();
    }
    faseAtual = nullptr;

}