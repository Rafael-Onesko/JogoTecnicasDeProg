#pragma once
#include<SFML/Graphics.hpp>
#include "Ente.h"
#define GRAVIDADE 550.0f

namespace Entidades {
    class Entidade : public Ente
    {
    protected:
        sf::RectangleShape* corpo;
        sf::Texture* textura;
        float tamX;
        float tamY;
        float posX;
        float posY;
        float posXant;
        float posYant;
        bool vivo;
    public:
        Entidade(ID id, float tX, float tY);
        Entidade();
        virtual ~Entidade();
        float getTamX();
        float getTamY();
        void setTamX(float tX);
        void setTamY(float tY);
        float getPosX();
        float getPosY();
        void setPosX(float pX);
        void setPosY(float pY);
        float getPosXant();
        float getPosYant();
        float getCentroX();
        float getCentroY();
        float getDireita();
        bool getVivo();
        void setVivo(bool viv);
        sf::RectangleShape* getCorpo();
        sf::Texture* getTextura();
        void setTextura(sf::Texture* text, int rectX = 0, int rectY = 0, float scaleX = 1.f, float scaleY = 1.f);
        virtual void colidir(ID IdOutro, float colisaoX, float colisaoY) = 0;
        virtual void imprimir_se();
    };
}
