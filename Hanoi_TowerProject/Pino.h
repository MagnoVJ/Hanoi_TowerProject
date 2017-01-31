#pragma once

#include "Heap.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

#include <iostream>

using std::cout;
using std::endl;

class Pino{

private:

	int x;
	int y;
	int dx;
	int dy;

	int quantOfDiscos;


public:
	Pino(int,int,int);
	Pino(){
	}
	~Pino(void);

	int numPino;
	int codUnico;

	Heap pilhaDeDiscos;

	int getX();
	int getY();
	int getDx();
	int getDy();

	int getQuantOfDiscos();
	void setQuantOfDiscos(int);

	void drawPino();

};

