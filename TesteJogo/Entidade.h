#pragma once
#include<SFML/Graphics.hpp>
#include "Ente.h"
class Entidade : public Ente
{
protected:
    sf::RectangleShape* corpo;
    float tamX;
    float tamY;
    float posX;
    float posY;
public:
    Entidade(int id, float tX, float tY);
    Entidade();
    ~Entidade();
    float getTamX();
    float getTamY();
    void setTamX(float tX);
    void setTamY(float tY);
    float getPosX();
    float getPosY();
    void setPosX(float pX);
    void setPosY(float pY);
    sf::RectangleShape* getCorpo();
};






/*#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int windowWidth = 400;
int windowHeight = 300;

class playerClass
{
public:
    bool playerFaceRight;
    float xpos;
    float ypos;
    float xvel;
    float yvel;
    playerClass()
    {
        playerFaceRight = true;
        xvel = 0;
        yvel = 0;
        xpos = 0;
        ypos = 0;
    }
    ~playerClass() {}
    void update(bool playerUp, bool playerDown, bool playerRight, bool playerLeft)
    {
        if (playerRight)
        {
            playerFaceRight = true;
            xvel = 5;
        }
        if (playerLeft)
        {
            playerFaceRight = false;
            xvel = -5;
        }
        if (playerUp)
        {
            yvel = -5;
        }
        if (playerDown)
        {
            yvel = 5;
        }
        xpos += xvel;
        ypos += yvel;
    }
};


int main()
{
    RenderWindow app(VideoMode(windowWidth, windowHeight), "Jogo Maneiro!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    bool playerUp = false, playerDown = false, playerLeft = false, playerRight = false;

    playerClass playerObject;

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
        }

        app.clear();
        app.draw(shape);
        app.display();
        if (Keyboard::isKeyPressed(Keyboard::Right)) playerRight = true;
        if (Keyboard::isKeyPressed(Keyboard::Left)) playerLeft = true;
        if (Keyboard::isKeyPressed(Keyboard::Up)) playerUp = true;
        if (Keyboard::isKeyPressed(Keyboard::Down)) playerDown = true;
        if (!(Keyboard::isKeyPressed(Keyboard::Right))) playerRight = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Up))) playerUp = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown = false;
        playerObject.update(playerUp, playerDown, playerRight, playerLeft);
    }

    return 0;
}*/