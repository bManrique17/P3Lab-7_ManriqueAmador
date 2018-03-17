temp.o:	mainLab7.o Racional.o
	g++ mainLab7.o Racional.o

mainLab7.o:	mainLab7.cpp
	g++ -c -std=c++11 mainLab7.cpp

Racional.o:	Racional.cpp Racional.h
	g++ -c -std=c++11 Racional.cpp
