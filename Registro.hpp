#pragma once
#include <string>
#include <vector>
#include "Campo.hpp"

using std::string;
using std::vector;

class Registro{
	vector<Campo> lista_campos;
	int size;
	//char marca;

public:
	Registro();
	Registro(int size);
	Registro(const Registro&);
	~Registro();

};