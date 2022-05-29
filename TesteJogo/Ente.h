#pragma once
class Ente
{
protected:
	int id;
public:
	Ente(int id = -1);
	~Ente();
	void setId(int id);
	int getId();
};

