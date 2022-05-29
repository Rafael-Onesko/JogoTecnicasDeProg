#include "Gerenciador_Eventos.h"
Gerenciador_Eventos::Gerenciador_Eventos(Gerenciador_Grafico* gerenciadorGrafico) {
	this->gerenciadorGrafico = gerenciadorGrafico;
}
Gerenciador_Eventos::Gerenciador_Eventos() {
	gerenciadorGrafico = nullptr;
}
void Gerenciador_Eventos::pollEvents() {

}
