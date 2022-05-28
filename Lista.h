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
	}
	void push(TIPO* info) {
		if (info != nullptr) {
			Elemento<TIPO>* elemenInfo = new Elemento<TIPO>;
			if (pPrimeiro == nullptr) {
				elemenInfo->setAnt(nullptr);
				elemenInfo->setProx(nullptr);
				pPrimeiro = elemenInfo;
				pUltimo = elemenInfo;
			}
			else {
				pUltimo->setProx() = elemenInfo;
				elemenInfo->setAnt(pUltimo);
				elemenInfo->setProx(nullptr);
				pUltimo = elemenInfo;
				pUltimo = elemenInfo;
			}
		}
	}
	void pop(TIPO* info) {
		if (info != nullptr) {
			Elemento<TIPO>* elemenInfo = new Elemento<TIPO>;
			elemenInfo = pPrimeiro;
			if (elemenInfo->getInfo() == info) {
				pPrimeiro = pPrimeiro->getProx();
				pPrimeiro->setAnt(nullptr);
				delete elemenInfo;
				return;
			}
			while (elemenInfo->getInfo() != info) {
				elemenInfo = elemenInfo->getProx();
			}
			elemenInfo->getAnt()->setProx(elemenInfo->getProx());
			elemenInfo->getProx()->setAnt(elemenInfo->getAnt());
			delete elemenInfo;
		}
	}

};

