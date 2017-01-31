#include "Heap.h"


Heap::Heap(void){


}


Heap::~Heap(void){
}

void Heap::add(int disco){

	pilha.insert(pilha.begin(), disco);

}



int Heap::retrive(){

	if(pilha.size() == 0)
		return -1;

	int element = pilha[0];

	return element;
}

int Heap::quantElements(){

	return pilha.size();

}


void Heap::remove(){

	 pilha.erase(pilha.begin());

}