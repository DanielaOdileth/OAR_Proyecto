rm: ejecutable
	rm *.o

ejecutable: Archivo.o Registro.o Campo.o
			g++ OAR.cpp Archivo.o Registro.o Campo.o -o exe -lncurses

Archivo.o: Registro.o Campo.o
		   g++ -c Archivo.cpp

Registro.o: Campo.o
			g++ -c Registro.cpp

Campo.o: 
		 g++ -c Campo.cpp 