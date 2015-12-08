#pragma once
#include <string>
#include <vector>
//#include "AvailList.hpp"
#include "Indice.hpp"
#include "Header.hpp"
#include "Registro.hpp"

using std::string;
using std::vector;

class Archivo{
	vector<Registro> lista_registro;
	//AvailList availList;
	//Header header;
	Indice indice_a;
	string nombre;

public:
	Archivo();
	Archivo(vector<Registro> lista_registro, Indice a, string nombre);
	Archivo(const Archivo&);
	~Archivo();
	const vector<Registro> getLista();
	const Indice getIndice();
	const string getNombre();
	//const Header getHeader()const;
};