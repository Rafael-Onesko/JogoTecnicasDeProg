#pragma once
template <class TIPO>
class Elemento
{
private:
	TIPO* pInfo;
	TIPO* pProx;
	TIPO* pAnt;
public:
	Elemento() {
		pInfo = nullptr;
	}
	~Elemento() {
		delete pInfo;
	}
	void setpInfo(TIPO* pI) {
		pInfo = pI;
	}
	TIPO* getpInfo() {
		return pInfo;
	}
	void setpProx(Elemento <TIPO>* elem) {
		this->pProx = elem;
	}
	void setpAnt(Elemento <TIPO>* elem) {
		this->Ant = elem;
	}
	Elemento <TIPO>* getpProx() {
		return this->pProx;
	}
	Elemento <TIPO>* getpAnt() {
		return this->pAnt;
	}
};

