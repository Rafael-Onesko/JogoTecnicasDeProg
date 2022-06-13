#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <iostream>
using namespace std;

Gerenciadores::Gerenciador_Grafico* Jogo::gerenciadorGrafico = new Gerenciadores::Gerenciador_Grafico();
Gerenciadores::Gerenciador_Grafico* Jogo::getGerenciadorGrafico() {
    return gerenciadorGrafico;
}

Jogo::Jogo (){
    menu = new Menu();

    srand((unsigned int) time(NULL));
    faseCastelo = nullptr;
    fasePrimeira = true;
    doisJogadores = true;
    executar();
}

Jogo::~Jogo(){
    if (menu)
        delete menu;
    if (gerenciadorGrafico) {
        delete gerenciadorGrafico;
        gerenciadorGrafico = nullptr;
    }
    if (faseFloresta)
        delete faseFloresta;
    if (faseCastelo)
        delete faseCastelo;
}

void Jogo::recebeMenu() {

    botao bot = menu->getBotaoClicado();
    switch (bot) {
    case fase1jogador1:
        fasePrimeira = true;
        doisJogadores = false;
        break;
    case fase1jogador2:
        fasePrimeira = true;
        doisJogadores = true;
        break;
    case fase2jogador1:
        fasePrimeira = false;
        doisJogadores = false;
        break;
    case fase2jogador2:
        fasePrimeira = false;
        doisJogadores = true;
        break;
    default:
        break;
    }
    menu->limpar();
}

void Jogo::inicializaFases() {
    recebeMenu();
    if (fasePrimeira) {
        faseFloresta = new Fases::Fase_Floresta(doisJogadores);
        faseAtual = faseFloresta;
    }
    else {
        faseCastelo = new Fases::Fase_Castelo(doisJogadores, jogador1jogador2);
        faseAtual = faseCastelo;
    }
    inicializado = true;
}
void Jogo::executar(){
    sf::Clock dt_clock;
    
    //printf("aqui %d\n", menu->getBotaoClicado());
    
    ID jogViv = ID::vazio;
    inicializado = false;
    int jogada = 0;
    float pontuacao = 0;
    while (gerenciadorGrafico->janelaAberta())
    {
        float dt = dt_clock.restart().asSeconds();
        gerenciadorGrafico->pollEvent();

        gerenciadorGrafico->clear();
        if (menu->getBotaoClicado() == nenhum) {
            menu->executar(0);
        }
        else {
            if (!inicializado) {
                inicializaFases();
            }
            if ((faseAtual) && faseAtual->getFim() == false) {
                faseAtual->executar(dt);
                pontuacao += dt;
            }
            else if (fasePrimeira) {
                if (faseAtual == faseFloresta) {
                    if (faseFloresta->getJogador1Vivo() && faseFloresta->getJogador2Vivo())
                        jogViv = jogador1jogador2;

                    else if (!faseFloresta->getJogador1Vivo() && faseFloresta->getJogador2Vivo())
                        jogViv = faseFloresta->getPlayer2()->getId();

                    else if (faseFloresta->getJogador1Vivo() && !faseFloresta->getJogador2Vivo())
                        jogViv = faseFloresta->getPlayer1()->getId();

                    else
                        jogViv = ID::vazio;

                    delete faseFloresta;
                    faseFloresta = nullptr;
                }

                if (jogViv != vazio) {
                    faseCastelo = new Fases::Fase_Castelo(doisJogadores, jogViv);
                    faseAtual = faseCastelo;
                }
                else {
                    faseAtual = nullptr;
                    fasePrimeira = false;
                }
            }
            else {
                if (faseCastelo) {
                    delete faseCastelo;
                    faseCastelo = nullptr;
                }
                if (inicializado) {
                    jogada++;
                    menu->adicionaJogada((int)pontuacao, jogada);
                    faseAtual = nullptr;
                    menu->set_values();
                    inicializado = false;
                }
                menu->executar(0);
            }
        }
        gerenciadorGrafico->display();
    }
    faseAtual = nullptr;

}