#include "Fase.h"
Fase::Fase(bool doisJogadores, Gerenciador_Grafico* gerenciGrafc) :Ente(fase), numTotalPlataformas(25) {
    entidades = new ListaEntidades;
    player1 = new Jogador(100.f, 100.f, 200.0f);
    entidades->inserir(player1);
    if (doisJogadores) {
        player2 = new Jogador(100.f, 100.f, 200.0f);
        entidades->inserir(player2);
    }
    else
        player2 = nullptr;
    this->gerenciadorGrafico = gerenciGrafc;
    gerenciadorColisoes = new Gerenciador_Colisoes(entidades);
    entidades->inserir(new Plataforma(false));
    for (int i = 0; i < numTotalPlataformas; i++)
        entidadesGeradas.push_back(" ");
    geraEntidades();
    for (int i = 0; i < entidades->getTam(); i++) {
        (*entidades)[i]->setGerenciadorGrafico(gerenciadorGrafico);
        (*entidades)[i]->setVivo(true);
    }
}
Fase::~Fase() {
    entidadesGeradas.clear();
    if (entidades)
        delete entidades;
    if (gerenciadorColisoes)
        delete gerenciadorColisoes;
}
void Fase::imprimir_se() {

    for (int i = 0; i < entidades->getTam(); i++) {
        if (((*entidades)[i]->getDireita() > gerenciadorGrafico->getEsquerdaCamera()) ||
            ((*entidades)[i]->getPosX() < gerenciadorGrafico->getDireitaCamera()))
            (*entidades)[i]->imprimir_se();
    }
}
void Fase::executar(float dt) {
    gerenciadorColisoes->verificarColisoes();
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
    imprimir_se();
}

void Fase::randomizarPosicoes(string entidadeCriar) {
    int num = rand() % 2 + 3;
    int pos = rand() % 23 + 1;
    for (int i = 0; i < num; i++) {
        while (entidadesGeradas[pos] != " ") {
            pos = rand() % (numTotalPlataformas - 1);
        }
        entidadesGeradas[pos] = entidadeCriar;

    }
}

void Fase::geraEntidades() {
    randomizarPosicoes("Vampiro");
    randomizarPosicoes("Goblin");
    randomizarPosicoes("Dragao");
    randomizarPosicoes("Muralha");
    randomizarPosicoes("Espinho");
    randomizarPosicoes("Agua");
    bool posicao = false;
    string coisa;
    float lugar;
    float complemento;
    int platAtual;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            Plataforma* novaPlat = new Plataforma(posicao);
            entidades->inserir(novaPlat);
            platAtual = Plataforma::getNumPlataformas() - 1;
            coisa = entidadesGeradas[platAtual];
            lugar = (float)platAtual * 300.f;
            complemento = (float)(rand() % 201);
            if (coisa == "Goblin") {
                entidades->inserir(new Goblin(lugar + complemento, 550.f + (!posicao) * 50.f - 100.f, player1));
            }
            else if (coisa == "Vampiro") {
                entidades->inserir(new Vampiro(lugar + complemento, 550.f + (!posicao) * 50.f - 100.f, player1));
            }
            else if (coisa == "Dragao") {
                entidades->inserir(new Dragao(lugar + complemento, 250.f + (!posicao) * 50.f, entidades, player1));
            }
            else if (coisa == "Muralha") {
                entidades->inserir(new Muralha(lugar + complemento, 550.f + (!posicao) * 50.f - 200.f));
            }
            else if (coisa == "Espinho") {
                entidades->inserir(new Espinho(lugar + complemento, 550.f + (!posicao) * 50.f - 50.f));
            }
            else if (coisa == "Agua") {
                entidades->inserir(new Agua(lugar + 150.f, 550.f + (!posicao) * 50.f));
                novaPlat->setTamX(150.f);
            }
        }
        posicao = !posicao;
    }
}