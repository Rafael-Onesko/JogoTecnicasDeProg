#pragma once
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
Gerenciador_Grafico::Gerenciador_Grafico(){
    janela = new sf::RenderWindow(sf::VideoMode(800,400), "Game");
}
Gerenciador_Grafico::~Gerenciador_Grafico(){
    delete janela;
}
int Gerenciador_Grafico::janelaAberta(){
return janela->isOpen();

}
void Gerenciador_Grafico::pollEvent(){
    sf::Event event;
        while (janela->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela->close();
        }
}
void Gerenciador_Grafico::clear(){
    if (janelaAberta())
            janela->clear();
}
void Gerenciador_Grafico::display(){
    if (janelaAberta())
            janela->display();
}
void Gerenciador_Grafico::draw(sf::RectangleShape* forma){
            janela->draw(*forma);
}