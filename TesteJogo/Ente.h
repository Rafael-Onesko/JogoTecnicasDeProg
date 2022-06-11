#pragma once
#include "Gerenciador_Grafico.h"
enum ID {
	vazio = 0,
	jogador1,
	plataforma,
	goblin,
	vampiro,
	dragao,
	agua,
	espinho,
	muralha,
	jogador2,
	bolaDeFogo,
	fase,
	barraVida,
	jogador1jogador2,
	menu
};
class Ente
{
protected:
	Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
	ID id;
public:
	Ente(ID id = vazio);
	virtual ~Ente();
	void setId(ID id);
	ID getId();
	void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico* gerenciGraf);
	virtual void imprimir_se() = 0;
	virtual void executar(float dt) = 0;
};

