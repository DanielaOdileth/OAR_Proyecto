exe:		OAR.o Archivo.o AvailList.o Indice.o Nodo.o Registro.o Header.o Campo.o
			g++ OAR.o Archivo.o AvailList.o Indice.o Nodo.o Registro.o Header.o Campo.o -o exe -lncurses

OAR.o:		OAR.cpp Archivo.hpp AvailList.hpp Indice.hpp Nodo.hpp Registro.hpp Header.hpp Campo.hpp
			g++ -c OAR.cpp

Archivo.o:		Archivo.cpp Archivo.hpp
					g++ -c Archivo.cpp

AvailList.o:	AvailList.cpp AvailList.hpp
					g++ -c AvailList.cpp

Indice.o:		Indice.cpp Indice.hpp
					g++ -c Indice.cpp

Nodo.o:			Nodo.cpp Nodo.hpp
					g++ -c Nodo.cpp	

Registro.o: 	Registro.cpp Registro.hpp
					g++ -c Registro.cpp

Header.o: 		Header.cpp Header.hpp
					g++ -c Header.cpp

Campo.o: 		Campo.cpp Campo.hpp
					g++ -c Campo.cpp