
#include "Disco.h"
#include "Pino.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>


using std::cout;
using std::endl;

const int WIDTH = 750;
const int HEIGHT = 500;
const int FPS = 60;

ALLEGRO_DISPLAY* display;
ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* event_queue;

ALLEGRO_EVENT event;

bool running = true;

Pino pino1(200,HEIGHT-200, 1);
Pino pino2(400,HEIGHT-200, 2);
Pino pino3(600,HEIGHT-200, 3);

Disco disco3(3, 150);
Disco disco2(2, 130);
Disco disco1(1, 110);
Disco disco0(0, 90);

void input_method();
void update_method();
void render_method();
void destroy();

bool mousePressed;

int main(){

	al_init();
	al_init_primitives_addon();
	al_install_mouse();

	display = al_create_display(WIDTH, HEIGHT);
	timer = al_create_timer(1.0/FPS);
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);

	pino1 = disco3.processEmpilhamentoDisco(pino1);
	pino1 = disco2.processEmpilhamentoDisco(pino1);
	pino1 = disco1.processEmpilhamentoDisco(pino1);
	pino1 = disco0.processEmpilhamentoDisco(pino1);

	while(running){

		al_wait_for_event(event_queue, &event);

		//INPUT METHOD
		input_method();

		//UPDATE METHOD
		update_method();

		//RENDER METHOD
		render_method();

	}

	destroy();

}

void input_method(){

	if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		mousePressed = true;
	else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		mousePressed = false;


}

void update_method(){

	if(disco3.isOnOver(event.mouse.x, event.mouse.y, event.type)){
		if(mousePressed){
			pino1 = disco3.tentativaMoverDisco(pino1, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino2 = disco3.tentativaMoverDisco(pino2, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino3 = disco3.tentativaMoverDisco(pino3, event.type, event.mouse.x, event.mouse.y, mousePressed);
		}
		else{
			disco3.setCorrectPosit(pino1, pino2, pino3);
		}
	}
	else if(disco2.isOnOver(event.mouse.x, event.mouse.y, event.type)){
		if(mousePressed){
			pino1 = disco2.tentativaMoverDisco(pino1, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino2 = disco2.tentativaMoverDisco(pino2, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino3 = disco2.tentativaMoverDisco(pino3, event.type, event.mouse.x, event.mouse.y, mousePressed);
		}
		else{
			disco2.setCorrectPosit(pino1, pino2, pino3);
		}
	}
	else if(disco1.isOnOver(event.mouse.x, event.mouse.y, event.type)){
		if(mousePressed){
			pino1 = disco1.tentativaMoverDisco(pino1, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino2 = disco1.tentativaMoverDisco(pino2, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino3 = disco1.tentativaMoverDisco(pino3, event.type, event.mouse.x, event.mouse.y, mousePressed);
		}
		else{
			disco1.setCorrectPosit(pino1, pino2, pino3);
		}
	}
	else if(disco0.isOnOver(event.mouse.x, event.mouse.y, event.type)){
		if(mousePressed){
			pino1 = disco0.tentativaMoverDisco(pino1, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino2 = disco0.tentativaMoverDisco(pino2, event.type, event.mouse.x, event.mouse.y, mousePressed);
			pino3 = disco0.tentativaMoverDisco(pino3, event.type, event.mouse.x, event.mouse.y, mousePressed);
		}
		else{
			disco0.setCorrectPosit(pino1, pino2, pino3);
		}
	}


}

void render_method(){

	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//Draw pinos
	pino1.drawPino();
	pino2.drawPino();
	pino3.drawPino();


	disco3.drawDisco(al_map_rgb(0, 255, 0));
	disco2.drawDisco(al_map_rgb(239, 247, 10));
	disco1.drawDisco(al_map_rgb(255, 136, 0));
	disco0.drawDisco(al_map_rgb(255, 0, 0));


}

void destroy(){

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

}