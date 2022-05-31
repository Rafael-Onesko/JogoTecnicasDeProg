#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"

class Gerenciador_Grafico {
private:
    sf::RenderWindow* janela;
    sf::View* camera;
    int larguraJanela;
    int alturaJanela;
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();
    int janelaAberta();
    void pollEvent();
    void clear();
    void display();
    void draw(sf::RectangleShape* forma);
    void ajustarCamera(sf::RectangleShape* jogador);
};