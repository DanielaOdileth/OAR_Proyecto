#pragma once
#include <string>
#include <vector>
#include "Nodo.hpp"

using std::string;
using std::vector;

class Indice{
	vector<Nodo> nodos; 

public:
	Indice();
	Indice(vector<Nodo> nodos);
	//Registro(int size);
	Indice(const Indice&);
	~Indice();
	const vector<Nodo> getNodo()const;
	void addINodo(const Nodo nodo_n);
};