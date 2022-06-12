#include "Fase_Castelo.h"
#include "Jogo.h"
namespace Fases {
    
    
    Fase_Castelo::Fase_Castelo(bool doisJogadores, ID idJogador): 
        Fase(doisJogadores) {
       
        if (doisJogadores) {
            if (idJogador == jogador2 || idJogador == jogador1) {
                player1 = new Entidades::Personagens::Jogador(150.0f, 0.0f, idJogador, 100);
                player2 = nullptr;
            }
            else if (idJogador == jogador1jogador2) {
                player1 = new Entidades::Personagens::Jogador(0.0f, 0.0f, jogador1, 100);
                player2 = new Entidades::Personagens::Jogador(150.0f, 0.0f, jogador2, 100);
            }
        }
        else {
            player1 = new Entidades::Personagens::Jogador(150.0f, 0.0f, jogador1, 100);
            player2 = nullptr;
        }

        gerenciadorGrafico->colocaTextura(gerenciadorGrafico->carregarTextura("./Assets/bg_castle.png"), &fundo);
        
        vector<string> nomEntid = { "Goblin", "Espinho", "Vampiro", "Dragao", "Muralha" };
        geraEntidades(&nomEntid);
        
        
        if(player1)
            entidades->inserir(player1);
        if (player2)
            entidades->inserir(player2);

        
        for (int i = 0; i < entidades->getTam(); i++) {
            (*entidades)[i]->setGerenciadorGrafico(gerenciadorGrafico);
            (*entidades)[i]->setVivo(true);
        }
    }
    
    Fase_Castelo::Fase_Castelo() :Fase() {

    }
    
    Fase_Castelo::~Fase_Castelo() {

    }
}