#pragma once
#include "Gerenciador_Grafico.h"
#include<exception>
#include <SFML/Graphics.hpp>
namespace Gerenciadores {
    
    Gerenciador_Grafico::Gerenciador_Grafico() :texturas(), larguraJanela(800), alturaJanela(750) {
        janela = new sf::RenderWindow(sf::VideoMode(larguraJanela, alturaJanela), "Game");
        camera = new sf::View(sf::Vector2f((float)larguraJanela / 2.f, (float)larguraJanela / 2.f), sf::Vector2f((float)larguraJanela, (float)alturaJanela));
        janela->setView(*camera);
        camera->setCenter(sf::Vector2f((float)larguraJanela / 2.f, (float)alturaJanela / 2.f));
    }

    Gerenciador_Grafico::~Gerenciador_Grafico() {
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
        try {
            textura->loadFromFile(caminho);
        }
        catch (const std::exception & e) {
            printf("Deu ruim aqui, falha ao carregar textura\n");
            exit(1);
        }

        texturas.insert(std::pair<const char*, sf::Texture*>(caminho, textura));

        return textura;
    }

    void Gerenciador_Grafico::colocaTextura(sf::Texture* text, sf::RectangleShape* corpo, int rectX, int rectY, float scaleX, float scaleY) {
        corpo->setTexture(text);
        corpo->setTextureRect(sf::IntRect(rectX, rectY, (int)((text->getSize().x) / scaleX), (int)((text->getSize().y) / scaleY)));
    }

    
    int Gerenciador_Grafico::janelaAberta() {
        return janela->isOpen();

    }
    
    void Gerenciador_Grafico::pollEvent() {
        sf::Event event;
        while (janela->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela->close();
        }
    }
    
    void Gerenciador_Grafico::fechaJanela() {
        janela->close();
    }
    
    void Gerenciador_Grafico::clear() {
        if (janelaAberta())
            janela->clear();
    }
    
    void Gerenciador_Grafico::display() {
        if (janelaAberta())
            janela->display();
    }




    void Gerenciador_Grafico::draw(sf::RectangleShape* forma) {
        janela->draw(*forma);
    }
    void Gerenciador_Grafico::draw(sf::Text* texto) {
        janela->draw(*texto);
    }




    void Gerenciador_Grafico::ajustarCamera(sf::RectangleShape* jogador) {
        float centroCameraX = jogador->getPosition().x + 2.f * jogador->getSize().x;
        float centroCameraY = alturaJanela / 2.f;
        if (centroCameraX < larguraJanela / 2.f)
            centroCameraX = larguraJanela / 2.f;
        camera->setCenter(sf::Vector2f(centroCameraX, centroCameraY));
        janela->setView(*camera);
    }
    
    void Gerenciador_Grafico::ajustarCameraInicio() {
        camera->setCenter(sf::Vector2f(larguraJanela / 2.f, alturaJanela / 2.f));
    }
    void Gerenciador_Grafico::ajustarCameraCentro(sf::RectangleShape* forma) {
        float centroCameraX = forma->getPosition().x + forma->getSize().x / 2;
        float centroCameraY = forma->getPosition().y + forma->getSize().y / 2;
        camera->setCenter(sf::Vector2f(centroCameraX, centroCameraY));
    }
    
    
    const unsigned int Gerenciador_Grafico::getlarguraJanela()const {
        return this->larguraJanela;
    }
    
    const unsigned int Gerenciador_Grafico::getAlturaJanela()const {
        return this->larguraJanela;
    }
    
    float Gerenciador_Grafico::getCentroCameraX()const {
        float centroX = camera->getCenter().x;
        return centroX;
    }
    
    float Gerenciador_Grafico::getCentroCameraY()const {
        float centroY = camera->getCenter().y;
        return centroY;
    }
    
    float Gerenciador_Grafico::getDireitaCamera()const {
        float direita = camera->getCenter().x + larguraJanela / 2.f;
        return direita;
    }
    
    float Gerenciador_Grafico::getEsquerdaCamera()const {
        float esquerda = camera->getCenter().x - larguraJanela / 2.f;
        return esquerda;
    }
    
    float Gerenciador_Grafico::getCimaCamera()const {
        float cima = camera->getCenter().y - alturaJanela / 2.f;
        return cima;
    }
    
    float Gerenciador_Grafico::getBaixoCamera()const {
        float baixo = camera->getCenter().y + alturaJanela / 2.f;
        return baixo;
    }
}