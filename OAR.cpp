#include <ncurses.h>
#include <cstdlib>
#include "Campo.hpp"
#include "Registro.hpp"
#include "Archivo.hpp"
#include <string>
#include <vector>

//#define columna1 5
//#define columna2 38

using namespace std;

void CrearCampos(vector<Campo>& campos);
void ValidarRegistros(vector<Campo>& campos);

int main(int argc, char* argv[]){
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	int opcion;
    
    vector<Campo> campos;
    vector<Registro> registros;

	printw("***MENU*** \n");
	printw("1. Crear un Archivo \n");
	printw("2. Abrir un nuevo Archivo \n");
	printw("3. Salir \n");
	scanw("%d", &opcion);

	if(opcion == 1){
		int opcion2;
		clear();
		refresh();
		char r;
		do{
			addstr("Crear Campos \n")
			Campo.CrearCampos(campos);
			printw("Desea crear mas campos? 1.S/2.N \n");
			scanw("%d", &r);
		}while(r != 2);

		clear();
		refresh();
		
		printw("1. Desea ingresar registros \n");
		printw("2. Guardar el Archivo \n");
		printw("3. Salir \n");

		//IMPRIMIR LOS NOMBRES DE LOS CAMPOS EN FORMA BONITA
		move(4, 4);
		for(int i = 0; i < campos.size(); i++){
			printw("Tamaño %d \n", campos[i].getSize());
			//mvprintw(21, 10, "%s", (campos[i].getTipo()).c_str());
		}
		scanw("%d", &opcion2);

		if(opcion2 == 1){
			//Validar los registros que el usuario ingresa
			int rsp;
			do{	
				ValidarRegistros(campos);
				printf("Desea ingresar mas registros 1.S/2.N \n");
				scanw("%d", &rsp);
			}while(rsp == 1);
			
		}
		if(opcion2 == 2){
			string nombre_ar;
			printf("Ingrese el nombre del Archivo \n");
			scanw("%d", &nombre_ar);
		}

	}

	if(opcion == 2){
	}

	getch();

	endwin();
	return 0;
}
void CrearCampos(vector<Campo>& campos){
		string nombre_campo;
		string tipo_campo;
		int tamano;
		int decimales;
		bool key;

		printw("Nombre del Campo: \n");
		scanw("%d", &nombre_campo);
		printw("Tipo del campo: \n");
		//scanw("%d", &tipo_campo);
		//getstr(tipo_campo);
		tipo_campo = "string";
		printw("Tamaño del campo: \n");
		scanw("%d", &tamano);
		//tamano = "string";
		if(tipo_campo == "double"){
			printw("Cantidad de decimales: \n");
			scanw("%d", &decimales);
		}else{
			decimales = 0;
		}
		printw("Desea que este campo sea una llave 1.S/2.N? \n");
		char p;
		scanw("%d", &p);
		if(p == 1){
			key = TRUE;
			//campos.push_back(Campo(nombre_campo, tipo_campo, tamano, decimales, key));
		}else{
			key = FALSE;
		}

	campos.push_back(Campo(nombre_campo, tipo_campo, tamano, decimales, key));
}

void ValidarRegistros(vector<Campo>& campos){
	for(int i = 0; i < campos.size(); i++){
		if(campos[i].getTipo() == "string"){
			char dato[campos[i].getSize()];
			printw("Ingrese %d", campos[i].getNombre());
			scanw("%d", dato);
		}
		if(campos[i].getTipo() == "double"){
			double dato;
			do{
				m = -1;
				printw("Ingrese %d", campos[i].getNombre());
				scanw("%d", dato);
				int m;
				m = pow(10, campo[i].getSize());
				//validar los decimales;
				double lim;
				if(campos[i].getSize_dec() != 1){
					lim = ( (m-1)*(1/(10(pow(campos[i].getSize()-(campos[i].getSize() - campos[i].getSize_dec()))))) );
				}else{
					lim = ( (m-1)*(1/(10(pow(campos[i].getSize()-campos[i].getSize_dec())))) );
				}

				if(dato > lim){
					printw("Tu dato no es valido para este campo \n");
				}else{
					m = 0;
				}
			}while(m == -1);
		}
		if(campos[i].getTipo() == "int"){
			int dato;
			do{
				int m;
				m = -1;
				printw("Ingrese %d", campos[i].getNombre());
				scanw("%d", dato);

				int limite;
				limite = pow(10, campo[i].getSize());

				if(dato >= limite){
					printf("Tu dato no es valido para este campo \n");
				}else{
					m = 0;
				}
			}while(m == -1);

		}
	}
	//Agregar a la lista de registo;
	registros.push_back(Registro(nombre_campo, tipo_campo, tamano, decimales, key));
}