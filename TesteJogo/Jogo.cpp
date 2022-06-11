#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <iostream>
using namespace std;

Gerenciadores::Gerenciador_Grafico* Jogo::gerenciadorGrafico = new Gerenciadores::Gerenciador_Grafico();
Gerenciadores::Gerenciador_Grafico* Jogo::getGerenciadorGrafico() {
    return gerenciadorGrafico;
}
Jogo::Jogo (){
    //gerenciadorGrafico = new Gerenciador_Grafico;
    srand((unsigned int) time(NULL));
    faseFloresta = new Fases::Fase_Floresta(true);
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
    bool doisJogadores = true;
    ID jogViv = vazio;
    while (gerenciadorGrafico->janelaAberta())
    {

        float dt = dt_clock.restart().asSeconds();
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();
        if ((faseAtual) && faseAtual->getFim() == false) {
            faseAtual->executar(dt);
        }
        else if(fasePrimeira) {
            if (faseAtual == faseFloresta) {
                if (faseFloresta->getJogador1Vivo() && faseFloresta->getJogador2Vivo())
                    jogViv = jogador1jogador2;

                else if (!faseFloresta->getJogador1Vivo() && faseFloresta->getJogador2Vivo())
                    jogViv = faseFloresta->getPlayer2()->getId();

                else if (faseFloresta->getJogador1Vivo() && !faseFloresta->getJogador2Vivo())
                    jogViv = faseFloresta->getPlayer1()->getId();

                else
                    jogViv = vazio;
                
                delete faseFloresta;
                faseFloresta = nullptr;
            }
            
            if (jogViv != vazio) {
                faseCastelo = new Fases::Fase_Castelo(doisJogadores, jogViv);
                faseAtual = faseCastelo;
            }
            else {
                faseAtual = nullptr;
            }
            
            fasePrimeira = false;
        }
        else {
            Jogo::getGerenciadorGrafico()->clear();
            if (faseAtual) {
                delete faseAtual;
                faseCastelo = nullptr;
                faseFloresta = nullptr;
                faseAtual = nullptr;
            }
            //sf::Text(sf::String("Fim"), sf::Font::, )
        }

        gerenciadorGrafico->display();
    }
    faseAtual = nullptr;

}