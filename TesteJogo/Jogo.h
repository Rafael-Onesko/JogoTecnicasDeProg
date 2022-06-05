#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Goblin.h"
#include "Vampiro.h"
#include "Dragao.h"
#include "Obstaculo.h"
#include "ListaEntidades.h"
class Jogo {
private:
    Jogador* player1;
    Goblin* enemy1;
    Vampiro* enemy2;
    Dragao* enemy3;
    Obstaculo* obst1;
    Obstaculo* obst2;
    Gerenciador_Grafico* gerenciadorGrafico;
    Gerenciador_Colisoes* gerenciadorColisoes;
    ListaEntidades* entidades;
public:
    Jogo();
    ~Jogo();
    void executar();
};