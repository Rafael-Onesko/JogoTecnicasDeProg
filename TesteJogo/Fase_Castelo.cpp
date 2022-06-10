#include "Fase_Castelo.h"
#include "Jogo.h"
Fase_Castelo::Fase_Castelo(bool doisJogadores):Fase(doisJogadores, Jogo::getGerenciadorGrafico()){
    vector<string> nomEntid = {"Goblin", "Espinho", "Vampiro", "Dragao", "Muralha" };
    geraEntidades(&nomEntid);
    entidades->inserir(player1);
    if (doisJogadores)
        entidades->inserir(player2);

    for (int i = 0; i < entidades->getTam(); i++) {
        (*entidades)[i]->setGerenciadorGrafico(gerenciadorGrafico);
        (*entidades)[i]->setVivo(true);
    }
}
Fase_Castelo::Fase_Castelo():Fase(){

}
Fase_Castelo::~Fase_Castelo() {

}