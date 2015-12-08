#include <ncurses.h>
#include <cstdlib>
#include <cmath>
#include "Campo.hpp"
#include "Registro.hpp"
#include "Archivo.hpp"
#include "Header.hpp"
#include "AvailList.hpp"
#include "Indice.hpp"
#include "Nodo.hpp"
#include <string>
#include <vector>
#include <fstream>

//#define columna1 5
//#define columna2 38

using namespace std;

void CrearCampos(vector<Campo>& campos);
Indice ValidarRegistros(vector<Campo>& campos, vector<Registro>& registros, vector<string>& c);
void CrearArchivos(string nombre_archivo, vector<Registro>& registros, Indice nuevo_indice);

int main(int argc, char* argv[]){
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	int opcion;
    
    vector<Campo> campos;
    vector<Registro> registros;
    vector<string> c;
    Indice nuevo_indice;
   	//availList = AvailList();
   	int cantidad;
   	cantidad = 0;
   	int lista[cantidad];

	printw("***MENU*** \n");
	printw("1. Crear un Archivo \n");
	printw("2. Abrir un Archivo \n");
	printw("3. Salir \n");
	scanw("%d", &opcion);

	if(opcion == 1){
		int opcion2;
		clear();
		refresh();
		char r;
		do{
			addstr("Crear Campos \n");
			CrearCampos(campos);
			printw("Desea crear mas campos? 1.S/2.N \n");
			scanw("%d", &r);
		}while(r != 2);

		clear();
		refresh();
		
		printw("1. Desea ingresar registros \n");
		printw("2. Guardar el Archivo \n");
		printw("3. Mas opciones \n");
		printw("4. Salir \n");

		//IMPRIMIR LOS NOMBRES DE LOS CAMPOS EN FORMA BONITA
		move(4, 4);
		for(int i = 0; i < campos.size(); i++){
			printw("Tamaño %s \n", campos[i].getNombre().c_str());
			//mvprintw(21, 10, "%s", (campos[i].getTipo()).c_str());
		}
		scanw("%d", &opcion2);

		if(opcion2 == 1){
			//Validar los registros que el usuario ingresa
			int rsp;
			do{	
				nuevo_indice = ValidarRegistros(campos, registros, c);
				printf("Desea ingresar mas registros 1.S/2.N \n");
				scanw("%d", &rsp);
				if(rsp == 2){
					char nombre_ar[30];
					printf("Ingrese el nombre del Archivo \n");
					getstr(nombre_ar);
					//Guardar el archivo
					CrearArchivos(nombre_ar, registros, nuevo_indice);
					printw("Su archivo fue creado");
					scanw("%d", &opcion2);
				}
			}while(rsp == 1);
				
		}
		if(opcion2 == 2){
			char nombre_ar[30];
			printf("Ingrese el nombre del Archivo \n");
			getstr(nombre_ar);
		}
		if(opcion2 == 3){
			clear();
			refresh();

			int respuesta;
			printw("1. Campos \n");
			printw("2. Registro \n");
			printw("3. Salir \n");
			scanw("%d", &respuesta);

			if(respuesta == 1){
				int r;
				//printw("1. Agregar \n");
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				scanw("%d", &r);

				if(r == 1){
					char nombre_buscar[30];
					printw("Escriba el nombre del campo que desea modificar \n");
					for(int i = 0; i < campos.size(); i++){
						if((campos[i].getNombre()[1] != '*')){
							printw("%s \n ", campos[i].getNombre().c_str());
						}
					}
					getstr(nombre_buscar);

					for(int i = 0; i < campos.size(); i++){
						if(campos[i].getNombre() == nombre_buscar){
							int b;
							printw("Que desa modificar \n");
							printw("1. Nombre \n");
							printw("2. Size \n");
							printw("3. Salir \n");
							scanw("%d", b);

							if(b == 1){
								printw("Escriba dato \n");
								char n_dato[30];
								getstr(n_dato);

								campos[i].setNombre(n_dato);
							}
							if(b == 2){
								printw("Escriba el dato \n");
								int n_dato;
								scanw("%d",n_dato);

								campos[i].setSize(n_dato);
							}

							if(b == 3){
								exit(EXIT_FAILURE);
							}
						}
					}
				}

			 	//AQUI
			 	clear();
				refresh();
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				printw("3. Salir \n");
				scanw("%d", &r);

				if(r == 2){
					char nombre_eliminar[30];
					printw("Escriba el nombre del campo que desea eliminar \n");
					for(int i = 0; i < campos.size(); i++){
						if((campos[i].getNombre()[1] != '*')){
							printw("%s \n ", campos[i].getNombre().c_str());
						}
					}
					getstr(nombre_eliminar);

					for(int i = 0; i < campos.size(); i++){
						if(campos[i].getNombre() == nombre_eliminar){
							string m = "*";
							string final;
							final = m+=campos[i].getNombre();
							campos[i].setNombre(final);
						}
					}
				}
				clear();
				refresh();
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				printw("3. Salir \n");
				scanw("%d", &r);

				if(r == 3){
					exit(EXIT_FAILURE);
				}
			}
			if(respuesta == 2){
				int r;
				//printw("1. Agregar \n");
				printw("1. Modificar \n");
				printw("2. Eliminar \n");
				printw("3. Salir \n");
				scanw("%d", &r);

				if(r == 1){
					//PENDIENTE
					printw("Ingrese la posicion a Modificar \n");
					for(int i = 0; i < registros.size(); i++){
						printw(registros[i].toString(c).c_str(), "\n");
					}
				}
				if(r == 2){
					int posicion;
					printw("Ingrese la posicion a eliminar \n");
					for(int i = 0; i< registros.size(); i++){
						printw(registros[i].toString(c).c_str(), "\n");
					}
					scanw("%d",posicion);
					printw("%d \n", registros.size());
					int cantidad = 0;
					int lista[cantidad];
					lista[cantidad] = posicion;
					cantidad++;
					string m = "*";
					string final;
					final = m+=registros[posicion].getValor();
					printw("%d \n", registros.size());
					registros[posicion].setElemento(posicion, final);

						//availList.push(posicion);
					//availList.push(posicion, cantidad, lista[cantidad]);
				}
			}
			if(respuesta == 3){
				exit(EXIT_FAILURE);
			}
		}
		if(opcion2 == 4){
			exit(EXIT_FAILURE);
		}
	}

	if(opcion == 2){
		clear();
		refresh();

		FILE *archivo;
		char nombre[30];
		int rsp;
		printw("Ingrese el nombre del archivo a abrir \n");
		getstr(nombre);
		archivo = fopen(nombre, "r");

		printw("1. Desea ingresar registros \n");
		printw("2. Mas opciones \n");
		printw("3. Salir \n");
		scanw("%d", &rsp);

		if(rsp == 1){
			do{	
				nuevo_indice = ValidarRegistros(campos, registros, c);
				printf("Desea ingresar mas registros 1.S/2.N \n");
				scanw("%d", &rsp);
				if(rsp == 2){
					//Guardar el archivo

				}
			}while(rsp == 1);
		}

		if(rsp == 2){
			clear();
			refresh();

			int respuesta;
			printw("1. Campos \n");
			printw("2. Registro \n");
			scanw("%d", &respuesta);

			if(respuesta == 1){
				int r;
				printw("1. Agregar \n");
				printw("2. Modificar \n");
				printw("3. Eliminar \n");
				scanw("%d", &r);
			}
			if(respuesta == 2){
				int r;
				printw("1. Agregar \n");
				printw("2. Modificar \n");
				printw("3. Eliminar \n");
				scanw("%d", &r);
			}
		}
		if(rsp == 3){
			exit(EXIT_FAILURE);
		}

	}if (opcion == 3){
		exit(EXIT_FAILURE);
	}

	getch();

	endwin();
	return 0;
}
void CrearCampos(vector<Campo>& campos){
		char nombre_campo[30];
		//char nc[30];
		string tipo_campo;
		int tamano;
		int decimales;
		bool key;

		printw("Nombre del Campo: \n");
		//scanw("%s", nombre_campo);
		//nombre_campo = "Hola";
		//getstr(nc);
		getstr(nombre_campo);
		printw("Tipo del campo: \n");
		int opcion_t;
		printw("1. String \n");
		printw("2. Int \n");
		printw("3. Double \n");
		scanw("%d", &opcion_t);
		//printw("Me imprimir la variable nc  %s \n", nombre_campo);
		//scanw("%d", &tipo_campo);
		//getstr(tipo_campo);
		if(opcion_t == 1){
			tipo_campo = "String";
		}
		if(opcion_t == 2){
			tipo_campo = "Int";
		}
		if(opcion_t == 3){
			tipo_campo = "Double";
		}
		printw("Tamaño del campo: \n");
		scanw("%d", &tamano);
		//tamano = "string";
		if(tipo_campo == "Double"){
			printw("Cantidad de decimales: \n");
			scanw("%d", &decimales);
		}else{
			decimales = 0;
		}
		printw("Desea que este campo sea una llave 1.S/2.N? \n");
		int p;
		scanw("%d", &p);
		if(p == 1){
			if(tipo_campo == "String"){
				printw("Solo se permiten llaves numericas \n");
				key = false;
			}else{
				key = true;
			}

			//campos.push_back(Campo(nombre_campo, tipo_campo, tamano, decimales, key));
		}else{
			key = false;
		}

	campos.push_back(Campo(nombre_campo, tipo_campo, tamano, decimales, key));
}

Indice ValidarRegistros(vector<Campo>& campos, vector<Registro>& registros, vector<string>& c){
	string lista_datos;
	//Registro r;
	lista_datos = "";
	int cantidad = 0;
	int llave;

	for(int i = 0; i < campos.size(); i++){
		if(campos[i].getTipo() == "String"){
			char dato[campos[i].getSize()];
			printw("Ingrese %s \n", campos[i].getNombre().c_str());
			getstr(dato);
			lista_datos+=dato;
			printw("%d", campos[i].getSize());
			printw("%c", dato);
			c.push_back(dato);
			//r.getLista().push_back(dato);

		}
		if(campos[i].getTipo() == "Double"){
			double dato;
			int m;
			char record[campos[i].getSize()];
			do{
				m = -1;
				printw("Ingrese %s \n", campos[i].getNombre().c_str());
				scanw("%d", dato);
				getstr(record);
				int m;
				m = pow(10, campos[i].getSize());
				//validar los decimales;
				double lim;
				int n;
				int r;
				int total;
				double llave;
				if(campos[i].getSize_dec() != 1){
					n = campos[i].getSize();
					r = campos[i].getSize() - campos[i].getSize_dec();
					total = n-(n-r);
					lim = ( (m-1)*(1/(pow(10, total))));
				}else{
					r = campos[i].getSize() - campos[i].getSize_dec();
					lim = ( (m-1)*(1/(pow(10,r))) );
				}

				if(dato > lim){
					printw("Tu dato no es valido para este campo \n");
				}else{
					m = 0;
					lista_datos+=record;
					c.push_back(record);
					if(campos[i].getKey() == TRUE){
						//l((lave = record;
					}
				}
			}while(m == -1);
		}
		if(campos[i].getTipo() == "Int"){
			int m;

			do{
				int dato;
				char record[campos[i].getSize()];
	
			
				m = -1;
				printw("Ingrese %s \n", campos[i].getNombre().c_str());
				scanw("%d", &dato);

				int limite;
				limite = pow(10, campos[i].getSize());

				if(dato >= limite){
					printf("Tu dato no es valido para este campo \n");
				}else{
					m = 0;
					lista_datos+=record;
					c.push_back(record);
					if(campos[i].getKey() == true){
						//AQUI HACE EL INDICE
						llave = dato;
					}
				}
			}while(m == -1);

		}/*else{
			printw("Si entra pero no valida bien los string \n");
		}*/
		//cantidad++;
	}
	//Agregar a la lista de registo;
	printw("11111111111111111111111 \n");
	Indice indice_nuevo;
	//vector<Nodo> lista_nodos;
	registros.push_back(Registro(lista_datos)); //Imprimir los registros en la terminal
	//Nodo nodo_n;
	printw("22222222222222222222 \n");
	//nodo_n = Nodo(registros.size(), llave);
	//lista_nodos.push_back(nodo_n);
	//indice_nuevo = Indice(lista_nodos);
	printw("SHIT");
	printw("%s", lista_datos.c_str());

	return indice_nuevo;
}

void CrearArchivos(string nombre_archivo, vector<Registro>& registros, Indice nuevo_indice){
	char c;
	string m;
	Archivo nuevo;
	FILE *nuevo_archivo;
	nuevo_archivo = fopen(nombre_archivo.c_str(), "w");

	printw("ANtes del for \n");


	for(int i = 0; i < registros.size(); i++){
		printw("Entro al for \n");
		//for(int j = 0; j < registros[i].getValor().size(); i++){
			//printw("Segundo for \n");
			c = registros[i].getValor()[i];
			if(c != '*'){
				printw("%s \n", registros[i].getValor().c_str());
				printw("size %d \n", registros.size());
				fputc(c, nuevo_archivo);
				printw("Se supone que leyo");
			}
		//}
		//m =registros[i].getValor();
		//c = m.c_str();
	}

	nuevo = Archivo(registros, nuevo_indice, nombre_archivo);
}