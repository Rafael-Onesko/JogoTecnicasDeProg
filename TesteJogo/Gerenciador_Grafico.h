#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico {
private:
    sf::RenderWindow* janela;
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();
    int janelaAberta();
    void pollEvent();
    void clear();
    void display();
    void draw(sf::RectangleShape* forma);
};