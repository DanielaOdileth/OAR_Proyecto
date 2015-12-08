#pragma once
#include <string>
#include <vector>
#include "Campo.hpp"

using std::string;
using std::vector;

class Registro{
	vector<string> lista_campos;
	int size;
	string lista;
	//char marca;

public:
	Registro();
	Registro(string lista);
	//Registro(int size);
	Registro(const Registro&);
	~Registro();
	const vector<string> getLista()const;
	const string getValor() const;
	const string getElemento(int posicion) const;
	void setElemento(int posicion, string nuevo);
	void setValor(string nuevo);
	string toString(vector<string> lista_campos)const;
};