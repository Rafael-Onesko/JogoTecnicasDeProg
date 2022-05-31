#pragma once
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
Gerenciador_Grafico::Gerenciador_Grafico(){
    larguraJanela = 800;
    alturaJanela = 800;
    janela = new sf::RenderWindow(sf::VideoMode(larguraJanela,alturaJanela), "Game");
    camera = new sf::View(sf::Vector2f((float)larguraJanela/2.f, (float)larguraJanela/2.f), sf::Vector2f((float) larguraJanela, (float) alturaJanela));
    janela->setView(*camera);
    camera->setCenter(sf::Vector2f((float) larguraJanela/2.f, (float)alturaJanela / 2.f));

}
Gerenciador_Grafico::~Gerenciador_Grafico(){
    delete janela;
    delete camera;
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
void Gerenciador_Grafico::ajustarCamera(sf::RectangleShape* jogador) {
    float centroCamera = jogador->getPosition().x + 2.f * jogador->getSize().x;
    if(jogador->getPosition().x >= (jogador->getSize().x)*2)
        camera->setCenter(sf::Vector2f(centroCamera, (float) alturaJanela/2.f));
    janela->setView(*camera);
}