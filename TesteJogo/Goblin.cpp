#include "Goblin.h"
int Goblin::numGoblins = 0;
int Goblin::getNumGoblins() {
    return numGoblins;
}
Goblin::Goblin() :Inimigo() {

}
Goblin::Goblin(float pX, float pY, Jogador* jog1, Jogador* jog2) : Inimigo(100.f, 100.f, 80.f, ID:: goblin, jog1, jog2) {
    this->setPosX(pX);
    this->setPosY(pY);
    numGoblins++;
}
Goblin::~Goblin() {
    numGoblins--;
}

void Goblin::receberDano(int dano) {

    vivo = false;
}

void Goblin::executar(float dt) {
    ajustarDeslocamento(dt);
    mover();
}
