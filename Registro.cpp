#include <string>
#include <vector>
#include "Registro.hpp"

using std::string;
using std::vector;

Registro::Registro(){
	size = 0;
}

Registro::Registro(int size){
	this->size = size;
}
	
Registro::Registro(const Registro& other){
	size = other.size;
}

Registro::~Registro(){

}
