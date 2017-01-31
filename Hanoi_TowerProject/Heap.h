#pragma once

#include <vector>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <string>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Heap{

private:
	

public:
	vector<int> pilha;
	Heap(void);
	~Heap(void);

	void add(int);
	int retrive();
	void remove();//remove primeria posicao

	int quantElements();



};

