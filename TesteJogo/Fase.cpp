#include "Fase.h"
#include "Jogo.h"
namespace Fases {
    Fase::Fase(bool doisJogadores) :Ente(fase), numTotalPlataformas(25), plataformas() {
        entidades = new Listas::ListaEntidades;
        this->gerenciadorGrafico = Jogo::getGerenciadorGrafico();
        gerenciadorColisoes = new Gerenciadores::Gerenciador_Colisoes(entidades);
        entidades->inserir(new Entidades::Obstaculos::Plataforma(false));
        for (int i = 0; i < numTotalPlataformas; i++)
            entidadesGeradas.push_back(" ");
        tamanhoFase = numTotalPlataformas * 300.f;
        fim = false;
    }

    Fase::Fase() :Ente(), numTotalPlataformas(0) {

    }
    Fase::~Fase() {
        plataformas.clear();
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
            if ((*entidades)[i]->getVivo()) {
                if (((*entidades)[i]->getDireita() > gerenciadorGrafico->getEsquerdaCamera()) ||
                    ((*entidades)[i]->getPosX() < gerenciadorGrafico->getDireitaCamera()))
                    (*entidades)[i]->executar(dt);
            }
            else {
                if ((*entidades)[i]->getId() == jogador1) {
                    if((player1) && player1->getId() == jogador1)
                        player1 = nullptr;
                    else if ((player2) && player2->getId() == jogador1)
                        player2 = nullptr;
                }
                else if ((*entidades)[i]->getId() == jogador2) {
                    if ((player1) && player1->getId() == jogador2)
                        player1 = nullptr;
                    else if ((player2) && player2->getId() == jogador2)
                        player2 = nullptr;
                }
                entidades->retirar((*entidades)[i]);
            }
        }
        imprimir_se();
        if (Jogo::getGerenciadorGrafico()->getCentroCameraX() > tamanhoFase) {
            fim = true;
        }
        else if (!getJogador1Vivo() && !getJogador2Vivo()) {
            fim = true;
        }
    }


    bool Fase::getJogador1Vivo() const {
        if (!player1)
            return false;
        return player1->getVivo();
    }
    bool Fase::getJogador2Vivo() const {
        if (!player2)
            return false;
        return player2->getVivo();
    }

    Entidades::Personagens::Jogador* Fase::getPlayer1() const {
        return player1;
    }
    Entidades::Personagens::Jogador* Fase::getPlayer2() const {
        return player2;
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

    void Fase::geraEntidades(vector<string>* nomesEntidades) {
        for (unsigned int i = 0; i < (nomesEntidades->size()); i++)
            randomizarPosicoes((*nomesEntidades)[i]);

        bool posicao = false;
        string coisa;
        float lugar;
        float complemento;
        int platAtual;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                Entidades::Obstaculos::Plataforma* novaPlat = new Entidades::Obstaculos::Plataforma(posicao);
                entidades->inserir(novaPlat);
                plataformas.push_back(novaPlat);
                platAtual = Entidades::Obstaculos::Plataforma::getNumPlataformas() - 1;
                coisa = entidadesGeradas[platAtual];
                lugar = (float)platAtual * 300.f;
                complemento = (float)(rand() % 201);
                if (coisa == "Goblin") {
                    (*entidades) += (new Entidades::Personagens::Goblin(lugar + complemento, 550.f + (!posicao) * 50.f - 100.f, player1, player2));
                }
                else if (coisa == "Vampiro") {
                    (*entidades) += (new Entidades::Personagens::Vampiro(lugar + complemento, 550.f + (!posicao) * 50.f - 100.f, player1, player2));
                }
                else if (coisa == "Dragao") {
                    (*entidades) += (new Entidades::Personagens::Dragao(lugar + complemento, 250.f + (!posicao) * 50.f, entidades, player1, player2));
                }
                else if (coisa == "Muralha") {
                    (*entidades) += (new Entidades::Obstaculos::Muralha(lugar + complemento, 550.f + (!posicao) * 50.f - 200.f));
                }
                else if (coisa == "Espinho") {
                    (*entidades) += (new Entidades::Obstaculos::Espinho(lugar + complemento, 550.f + (!posicao) * 50.f - 50.f));
                }
                else if (coisa == "Agua") {
                    (*entidades) += (new Entidades::Obstaculos::Agua(lugar + 150.f, 550.f + (!posicao) * 50.f));
                    novaPlat->setTamX(150.f);
                }
            }
            posicao = !posicao;
        }
    }

    const float  Fase::getTamanhoFase() const {
        return tamanhoFase;
    }

    bool Fase::getFim() const {
        return fim;
    }
}