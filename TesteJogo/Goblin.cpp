#include "Goblin.h"
Goblin::Goblin() :Inimigo() {

}
Goblin::Goblin(float tX, float tY, Jogador* jog1, Jogador* jog2) : Inimigo(tX, tY, 80.f, ID:: goblin, jog1, jog2) {

}
Goblin::~Goblin() {

}

void Goblin::receberDano() {

    vivo = false;
}

void Goblin::executar(float dt) {
    ajustarDeslocamento(dt);
    mover();
}
