#pragma once
#include <iostream>
#include "Elemento.h"
template <class TIPO>
class Lista{
private:
	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pUltimo;
	int tam;
public:
	Lista() {
		pPrimeiro = nullptr;
		pUltimo = nullptr;
		tam = 0;
	}
	~Lista() {
		Elemento<TIPO>* aux = new Elemento<TIPO>;
		for (aux = pPrimeiro->getpProx(); aux != nullptr; aux = aux->getpProx()) {
			delete pPrimeiro;
			pPrimeiro = aux;
		}
		delete aux;
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}
	void push(TIPO* info) {
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
	void pop(TIPO* info) {
		if (info != nullptr) {
			Elemento<TIPO>* elemenInfo = new Elemento<TIPO>;
			elemenInfo = pPrimeiro;
			if (elemenInfo->getpInfo() == info) {
				pPrimeiro = pPrimeiro->getpProx();
				pPrimeiro->setpAnt(nullptr);
				delete elemenInfo;
				tam--;
				return;
			}
			while (elemenInfo != nullptr && elemenInfo->getpInfo() != info) {
				elemenInfo = elemenInfo->getpProx();
			}
			if (elemenInfo) {
				if (elemenInfo == pUltimo) {
					pUltimo = pUltimo->getpAnt();
					pUltimo->setpProx(nullptr);
				}
				else {
					elemenInfo->getpAnt()->setpProx(elemenInfo->getpProx());
					elemenInfo->getpProx()->setpAnt(elemenInfo->getpAnt());
				}
				delete elemenInfo;
				tam--;
			}
		}
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

};

