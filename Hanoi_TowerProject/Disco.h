#pragma once

#include "Pino.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

#include <iostream>

using std::cout;
using std::endl;

class Disco{

private:
	int x;
	int y;
	int dx;
	int dy;

	int xCopia;
	int yCopia;
	int dxCopia;
	int dyCopia;

	int sizeDx;

	int codUnico;
	int posicNaPilha;
	int codPinoOndeSeEncontra; //codigo do pino onde se enconta (numero de 1 até 3)
	//int codPilhaAnterior;

	Pino pino;


public:
	Disco(int,int); //o segundo parametro é o sizeDx

	Pino processEmpilhamentoDisco(Pino);
	Pino processEmpilhamentoDisco(Pino,bool&);

	Pino empilharNaPosic(int, Pino); //primeiro atributo posic (1 até 4) segundo o pino

	bool isOnOver(int mouseXPosit, int mouseYPosit, ALLEGRO_EVENT_TYPE eventType);

	Pino tentativaMoverDisco(Pino, ALLEGRO_EVENT_TYPE, int mouseXPosit, int mouseYPosit,bool);
	Pino mover(Pino, ALLEGRO_EVENT_TYPE, int mouseXPosit, int mouseYPosit,bool);

	void setCorrectPosit(Pino&, Pino&, Pino&);

	void drawDisco(ALLEGRO_COLOR);
	
};

