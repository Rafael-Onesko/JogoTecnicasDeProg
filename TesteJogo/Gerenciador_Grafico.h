#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico {
private:
    sf::RenderWindow* janela;
    sf::View* camera;
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
    void draw(sf::RectangleShape* forma);
    sf::Texture* carregarTextura(const char* caminho);
    void ajustarTextura();
    void ajustarCamera(sf::RectangleShape* jogador);
    const unsigned int getlarguraJanela();
    const unsigned int getAlturaJanela();
};