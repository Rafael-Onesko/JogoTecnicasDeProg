#include "Goblin.h"
#include "Jogo.h"
namespace Entidades {
    namespace Personagens {
        int Goblin::numGoblins = 0;
        int Goblin::getNumGoblins() {
            return numGoblins;
        }
        Goblin::Goblin() :Inimigo() {

        }
        Goblin::Goblin(float pX, float pY, Jogador* jog1, Jogador* jog2) : Inimigo(100.f, 100.f, 80.f, ID::goblin, jog1, jog2) {
            this->setPosX(pX);
            this->setPosY(pY);
            textura = Jogo::getGerenciadorGrafico()->carregarTextura("./Assets/Goblin.png");
            setTextura(textura, 0, 0, 1, 1);
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
            if (direcao > 0)
                setTextura(textura, textura->getSize().x, 0, -1, 1);
            else
                setTextura(textura, 0, 0, 1, 1);
        }
    }
}
