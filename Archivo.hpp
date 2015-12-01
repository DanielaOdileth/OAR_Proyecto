#pragma once
#include <string>
#include <vector>
#include "Registro.hpp"

using std::string;
using std::vector;

class Archivo{
	vector<Registro> lista_registro;

public:
	Archivo();
	~Archivo();
};