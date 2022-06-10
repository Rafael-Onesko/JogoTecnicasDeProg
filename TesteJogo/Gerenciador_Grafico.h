#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico {
private:
    sf::RenderWindow* janela;
    sf::View* camera;
    float dt;
    const unsigned int larguraJanela;
    const unsigned int alturaJanela;
    std::map<const char*, sf::Texture*> texturas;
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();
    int janelaAberta();
    void pollEvent();
    void clear();
    void display();
    void fechaJanela();
    void draw(sf::RectangleShape* forma);
    sf::Texture* carregarTextura(const char* caminho);
    void colocaTextura(sf::Texture* text, sf::RectangleShape* corpo, int rectX  = 0, int rectY = 0, float scaleX = 1.f, float scaleY = 1.f);
    void ajustarCamera(sf::RectangleShape* jogador);
    const unsigned int getlarguraJanela();
    const unsigned int getAlturaJanela();
    float getCentroCameraX();
    float getCentroCameraY();
    float getDireitaCamera();
    float getEsquerdaCamera();
    float getCimaCamera();
    float getBaixoCamera();
};