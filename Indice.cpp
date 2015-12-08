#include <string>
#include <vector>
#include "Indice.hpp"

using std::string;
using std::vector;

Indice::Indice(){

}

Indice::Indice(vector<Nodo> nodos){
	for(int i = 0; i < nodos.size(); i++){
		this->nodos[i] = nodos[i];
	}

}

Indice::Indice(const Indice& other){
	for(int i = 0; i < other.nodos.size(); i++){
		nodos.push_back(other.nodos[i]);
	}
}

Indice::~Indice(){

}

const vector<Nodo> Indice::getNodo()const{
	return nodos;
}

//void Indice::addNodo(const Nodo nodo_n){
	//nodos.push_back(nodo_n);
//}
