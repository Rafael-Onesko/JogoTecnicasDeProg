#include "Fase_Floresta.h"
#include "Jogo.h"
namespace Fases {
    Fase_Floresta::Fase_Floresta(bool doisJogadores) : Fase(doisJogadores) {

        
        player1 = new Entidades::Personagens::Jogador( 0.0, 0.0, jogador1, 100);
        if (doisJogadores) 
                player2 = new Entidades::Personagens::Jogador( 150.0, 0.0, jogador2, 100);
        else
            player2 = nullptr;

        vector<string> nomEntid = { "Goblin", "Agua", "Espinho", "Vampiro" };
        geraEntidades(&nomEntid);

        entidades->inserir(player1);
        if (doisJogadores)
            entidades->inserir(player2);

        sf::Texture* grama = gerenciadorGrafico->carregarTextura("./Assets/Grama.png");
        for (unsigned int i = 0; i < plataformas.size(); i++) {
            plataformas[i]->setTextura(grama, 0, 0, 1, 2);
        }

        gerenciadorGrafico->colocaTextura(gerenciadorGrafico->carregarTextura("./Assets/bg.png"), &fundo);

        for (int i = 0; i < entidades->getTam(); i++) {
            (*entidades)[i]->setGerenciadorGrafico(gerenciadorGrafico);
            (*entidades)[i]->setVivo(true);
        }
    }
    Fase_Floresta::Fase_Floresta() :Fase() {

    }
    Fase_Floresta::~Fase_Floresta() {

    }
}