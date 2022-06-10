#include "Fase_Floresta.h"
#include "Jogo.h"
Fase_Floresta::Fase_Floresta(bool doisJogadores): Fase(doisJogadores, Jogo::getGerenciadorGrafico()) {
    vector<string> nomEntid = { "Goblin", "Agua", "Espinho", "Vampiro" };
    
    geraEntidades(&nomEntid);
    
    entidades->inserir(player1);
    if (doisJogadores)
        entidades->inserir(player2);

    sf::Texture* grama = gerenciadorGrafico->carregarTextura("./Assets/Grama.png");
    for (int i = 0; i < plataformas.size(); i++) {
        plataformas[i]->setTextura(grama, 0, 0, 1, 2);
    }
    for (int i = 0; i < entidades->getTam(); i++) {
        (*entidades)[i]->setGerenciadorGrafico(gerenciadorGrafico);
        (*entidades)[i]->setVivo(true);
    }
}
Fase_Floresta::Fase_Floresta():Fase() {

}
Fase_Floresta::~Fase_Floresta() {

}