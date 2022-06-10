#pragma once
#include <iostream>
//#include "Elemento.h"
template <class TIPO>
class Lista{
private:

	template <class TIP>
	class Elemento
	{
	private:
		TIP* pInfo;
		Elemento<TIP>* pProx;
		Elemento<TIP>* pAnt;
	public:
		Elemento() {
			pInfo = nullptr;
		}
		~Elemento() {
			if (pInfo != nullptr)
				delete pInfo;
			pProx = nullptr;
			pAnt = nullptr;
		}
		void setpInfo(TIP* pI) {
			pInfo = pI;
		}
		TIP* getpInfo() {
			return pInfo;
		}
		void setpProx(Elemento <TIP>* elem) {
			this->pProx = elem;
		}
		void setpAnt(Elemento <TIP>* elem) {
			this->pAnt = elem;
		}
		Elemento <TIP>* getpProx() {
			return this->pProx;
		}
		Elemento <TIP>* getpAnt() {
			return this->pAnt;
		}
	};
	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pUltimo;
	int tam;
public:
	Lista();
	~Lista();
	void inserir(TIPO* info) {
		if (info != nullptr) {
			Elemento<TIPO>* elemenInfo = new Elemento<TIPO>;
			if (pPrimeiro == nullptr) {
				elemenInfo->setpAnt(nullptr);
				elemenInfo->setpProx(nullptr);
				pPrimeiro = elemenInfo;
				pUltimo = elemenInfo;
			}
			else {
				pUltimo->setpProx(elemenInfo);
				elemenInfo->setpAnt(pUltimo);
				elemenInfo->setpProx(nullptr);
				pUltimo = elemenInfo;
				pUltimo = elemenInfo;
			}
			elemenInfo->setpInfo(info);
			tam++;
		}
	}
	void retirar(TIPO* info) {
		printf(" ok\n");
		if (info == nullptr)
			return;
		Elemento<TIPO>* pElemento;
		pElemento = pPrimeiro;
		while (pElemento != nullptr && pElemento->getpInfo() != info) {
			pElemento = pElemento->getpProx();
		}
		if (pElemento == nullptr)
			return;

		if (pPrimeiro == pElemento) {
			pPrimeiro = pElemento->getpProx();
			pPrimeiro->setpAnt(nullptr);
		}
		else if (pElemento == pUltimo) {
			pUltimo = pElemento->getpAnt();
			pUltimo->setpProx(nullptr);
		}
		else  {
			pElemento->getpProx()->setpAnt(pElemento->getpAnt());
			pElemento->getpAnt()->setpProx(pElemento->getpProx());
		}
		delete pElemento;
		tam--;
	}
	int getTam() {
		return tam;
	}
	TIPO* operator[](int index) {
		if (index < tam) {
			Elemento<TIPO>* aux = pPrimeiro;
			for (int i = 0; i < index; i++) {
				aux = aux->getpProx();
			}
			return aux->getpInfo();
		}
		return nullptr;
	}
	void limpar() {

		Elemento<TIPO>* aux = pPrimeiro;
		int i = 0;
		while (aux != nullptr && i < tam) {
			pPrimeiro = aux->getpProx();
			delete aux;
			aux = pPrimeiro;
			i++;
		}

		pPrimeiro = nullptr;
		pUltimo = nullptr;
		tam = 0;
	}

};

template<class TIPO>
Lista<TIPO>::Lista() {
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	tam = 0;
}
template<class TIPO>
Lista<TIPO>::~Lista() {
	this->limpar();
}

