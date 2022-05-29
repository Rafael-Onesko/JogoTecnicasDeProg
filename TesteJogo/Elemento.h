#pragma once
template <class TIPO>
class Elemento
{
private:
	TIPO* pInfo;
	Elemento<TIPO>* pProx;
	Elemento<TIPO>* pAnt;
public:
	Elemento() {
		pInfo = nullptr;
	}
	~Elemento() {
		delete pInfo;
		pProx = nullptr;
		pAnt = nullptr;
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
		this->pAnt = elem;
	}
	Elemento <TIPO>* getpProx() {
		return this->pProx;
	}
	Elemento <TIPO>* getpAnt() {
		return this->pAnt;
	}
};

