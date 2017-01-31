#include "Pino.h"


Pino::Pino(int x, int y, int codUnico){

	this->x = x;
	this->y = y;
	dx = x + 20;
	dy = y + 200;

	this->codUnico = codUnico;

}


Pino::~Pino(void){

}

int Pino::getX(){return x;}
int Pino::getY(){return y;}
int Pino::getDx(){return dx;}
int Pino::getDy(){return dy;}


int Pino::getQuantOfDiscos(){
	return quantOfDiscos;
}

void Pino::setQuantOfDiscos(int quantOfDiscos){
	this->quantOfDiscos = quantOfDiscos;
}


void Pino::drawPino(){

	al_draw_filled_rounded_rectangle(x, y, dx, dy, 5, 5, al_map_rgb(179, 179, 179));


}