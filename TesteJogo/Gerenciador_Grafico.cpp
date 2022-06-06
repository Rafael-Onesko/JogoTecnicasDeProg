#pragma once
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
Gerenciador_Grafico::Gerenciador_Grafico() :texturas(),larguraJanela(800), alturaJanela(750) {
    janela = new sf::RenderWindow(sf::VideoMode(larguraJanela,alturaJanela), "Game");
    camera = new sf::View(sf::Vector2f((float)larguraJanela/2.f, (float)larguraJanela/2.f), sf::Vector2f((float) larguraJanela, (float) alturaJanela));
    janela->setView(*camera);
    camera->setCenter(sf::Vector2f((float) larguraJanela/2.f, (float)alturaJanela / 2.f));

}
Gerenciador_Grafico::~Gerenciador_Grafico(){
    delete janela;
    delete camera;
    std::map<const char*, sf::Texture*>::iterator it;

    for (it = texturas.begin(); it != texturas.end(); ++it) {
        delete (it->second);
    }

}
sf::Texture* Gerenciador_Grafico::carregarTextura(const char* caminho) {
    std::map<const char*, sf::Texture*>::iterator it = texturas.begin();
    while (it != texturas.end()) {
        if (!strcmp(it->first, caminho))
            return it->second;
        it++;
    }
    sf::Texture* textura = new sf::Texture();
    if (!textura->loadFromFile(caminho)) {
        printf("Deu ruim aqui\n");
        exit(1);
    }

    texturas.insert(std::pair<const char*, sf::Texture*>(caminho, textura));

    return textura;
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
    float centroCameraX = jogador->getPosition().x + 2.f * jogador->getSize().x;
    float centroCameraY = alturaJanela / 2.f;
    if (centroCameraX < larguraJanela / 2.f)
        centroCameraX = larguraJanela / 2.f;
    if(jogador->getPosition().y < alturaJanela/2.f)
        centroCameraY = alturaJanela / 2.f + ((jogador->getPosition().y - alturaJanela / 2.f) / 4.f);
    camera->setCenter(sf::Vector2f(centroCameraX, centroCameraY));
    janela->setView(*camera);
}
const unsigned int Gerenciador_Grafico::getlarguraJanela() {
    return this->larguraJanela;
}
const unsigned int Gerenciador_Grafico::getAlturaJanela() {
    return this->larguraJanela;
}