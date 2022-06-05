#pragma once
#include<SFML/Graphics.hpp>
#include "Ente.h"
#define GRAVIDADE 500.0f

class Entidade : public Ente
{
protected:
    sf::RectangleShape* corpo;
    float tamX;
    float tamY;
    float posX;
    float posY;
    float posXant;
    float posYant;
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
    virtual bool getVivo() { return true; }
    sf::RectangleShape* getCorpo();
    virtual void colidir(ID IdOutro, float colisaoX, float colisaoY) {};
    void imprimir_se();
};
