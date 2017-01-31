#include "Disco.h"

Disco::Disco(int codUnico, int sizeDx){

	this->codUnico = codUnico;

	this->sizeDx = sizeDx;

	x = 0;
	y = 0;
	dx = x + this->sizeDx;
	dy = 0;

}

Pino Disco::processEmpilhamentoDisco(Pino pino, bool& foiAlterado){

	int primeiroElementoPino = pino.pilhaDeDiscos.retrive();

	if(primeiroElementoPino < codUnico && primeiroElementoPino!=-1){
		cout << endl <<"Nao foi possivel empilhar pois o primeiro disco da pilha e menor que o disco a ser empilhado..." << endl;
		foiAlterado = false;
		return pino;
	}
	else if(primeiroElementoPino == -1){

		cout << endl <<"A pilha se encontra vazia, iniciar processo de empilhamento..." << endl;

		pino = empilharNaPosic(4, pino);
		foiAlterado = true;

		return pino;

	}
	else if(primeiroElementoPino > codUnico){

		cout << endl <<"O disco atual é menor do que o primeiro elemento da pilha, logo é possível empilhar..." << endl;
		
		pino = empilharNaPosic(4 - pino.pilhaDeDiscos.pilha.size(), pino);
		foiAlterado = true;

		return pino;

	}



}

Pino Disco::processEmpilhamentoDisco(Pino pino){

	int primeiroElementoPino = pino.pilhaDeDiscos.retrive();

	if(primeiroElementoPino < codUnico && primeiroElementoPino!=-1){
		cout <<"Nao foi possivel empilhar pois o primeiro disco da pilha e menor que o disco a ser empilhado..." << endl;
		return pino;
	}
	else if(primeiroElementoPino == -1){

		cout <<"A pilha se encontra vazia, iniciar processo de empilhamento..." << endl;

		pino = empilharNaPosic(4, pino);

		return pino;

	}
	else if(primeiroElementoPino > codUnico){

		cout << "O disco atual é menor do que o primeiro elemento da pilha, logo é possível empilhar..." << endl;
		
		pino = empilharNaPosic(4 - pino.pilhaDeDiscos.pilha.size(), pino);

		return pino;

	}


}


Pino Disco::empilharNaPosic(int posic, Pino pino){

	//Posiciona o disco graficamente
	int meioPin = pino.getX() + ((pino.getDx()-pino.getX())/2);
	x = meioPin - ((dx-x)/2);
	dx = x + sizeDx;


	//Define o local do disco de acordo com a posic
	if(posic == 4)
		y  = pino.getDy() - 30;
	else if(posic == 3)
		y  = pino.getDy() - 60;
	else if(posic == 2)
		y  = pino.getDy() - 90;
	else if(posic == 1)
		y  = pino.getDy() - 120;
	dy = y + 20;

	//Informa o disco o pino que ele se encontra
	codPinoOndeSeEncontra = pino.codUnico;

	//Informa a posic atual
	posicNaPilha = posic;

	//Adiciona o disco na pilha
	pino.pilhaDeDiscos.add(codUnico);

	xCopia = x;
	yCopia = y;
	dxCopia = dx;
	dyCopia = dy;

	return pino;

}


void Disco::drawDisco(ALLEGRO_COLOR cor){

	al_draw_filled_rounded_rectangle(x, y, dx, dy, 5, 5, cor);

}

bool Disco::isOnOver(int mouseXPosit, int mouseYPosit, ALLEGRO_EVENT_TYPE eventType){

	if(eventType == ALLEGRO_EVENT_MOUSE_AXES){

		if(mouseXPosit >= x && mouseXPosit <= dx && mouseYPosit >= y && mouseYPosit <= dy)
			return true;
		else
			return false;
	}

	return false;

}

Pino Disco::tentativaMoverDisco(Pino pino, ALLEGRO_EVENT_TYPE eventType, int mouseXPosit, int mouseYPosit, bool mousePressed){

	if(codPinoOndeSeEncontra == pino.codUnico){

		if(pino.pilhaDeDiscos.retrive() == codUnico){
			cout << endl <<"Foi permitido mover...";
			pino = mover(pino, eventType, mouseXPosit, mouseYPosit, mousePressed);
			return pino;
		}
		else{
			cout << endl << "Não foi permitido mover...";
			cout << endl << "pino.pilhaDeDiscos.retrive(): " << pino.pilhaDeDiscos.retrive();
			cout << endl << "codUnico: " << codUnico;
			return pino;
		}

	}

	return pino;

}


Pino Disco::mover(Pino pino, ALLEGRO_EVENT_TYPE eventType, int mouseXPosit, int mouseYPosit, bool mousePressed){

	if(eventType == ALLEGRO_EVENT_MOUSE_AXES){
		x = (mouseXPosit>0&&mouseXPosit<750)?(mouseXPosit-((dx-x)/2)):x;
		y = (mouseYPosit>0&&mouseYPosit<500)?(mouseYPosit-((dy-y)/2)):y;
		dx = x + sizeDx;
		dy = y + 20;
	}


	return pino;

}

void Disco::setCorrectPosit(Pino& pino1, Pino& pino2, Pino& pino3){

	int pinoOndeOuveAColisao = 0;

	if(x < pino1.getDx() && dy > pino1.getY() && dx > pino1.getX())
		pinoOndeOuveAColisao = 1;
	else if(x < pino2.getDx() && dy > pino2.getY() && dx > pino2.getX())
		pinoOndeOuveAColisao = 2;
	else if(x < pino3.getDx() && dy > pino3.getY() && dx > pino3.getX())
		pinoOndeOuveAColisao = 3;

	if(pinoOndeOuveAColisao == 0){

		cout << "Não houve colisão com nada " << endl;

		x = xCopia;
		y = yCopia;
		dx = dxCopia;
		dy = dyCopia;

		return;

	}
	else if(pinoOndeOuveAColisao == 1){

		if(codPinoOndeSeEncontra == pinoOndeOuveAColisao){
			cout << "Pino da colisão é igual ao pino onde o disco ja estava " << endl;
			x = xCopia;
			y = yCopia;
			dx = dxCopia;
			dy = dyCopia;

			return;
		}
		else{

			int pino1SizeAnt = pino1.pilhaDeDiscos.quantElements();

			bool pilhaFoiAlterada = false;
			int codPinoOndeSeEncontraAnt = codPinoOndeSeEncontra;

			pino1 = processEmpilhamentoDisco(pino1, pilhaFoiAlterada);

			cout << "pilhaFoiAlterada: " << pilhaFoiAlterada << endl;

			if(pilhaFoiAlterada){
				if(codPinoOndeSeEncontraAnt == 2){
					pino2.pilhaDeDiscos.remove(); //remove a primeira posicção
					cout << "pilha foi alterada remover primeira posicao de pino 2";
				}
				else if(codPinoOndeSeEncontraAnt == 3){
					pino3.pilhaDeDiscos.remove(); //remove a primeira posicção
					cout << "pilha foi alterada remover primeira posicao de pino 3";
				}
			}


			if(pino1SizeAnt == pino1.pilhaDeDiscos.quantElements()){

				cout << "Não foi posssível colocar o pino na pilha selecionada " << endl;
				x = xCopia;
				y = yCopia;
				dx = dxCopia;
				dy = dyCopia;

				return;
			}


		}
	}
	else if(pinoOndeOuveAColisao == 2){

		if(codPinoOndeSeEncontra == pinoOndeOuveAColisao){
			cout << "Pino da colisão é igual ao pino onde o disco ja estava " << endl;
			x = xCopia;
			y = yCopia;
			dx = dxCopia;
			dy = dyCopia;

			return;
		}
		else{

			int pino2SizeAnt = pino2.pilhaDeDiscos.quantElements();

			bool pilhaFoiAlterada = false;
			int codPinoOndeSeEncontraAnt = codPinoOndeSeEncontra;

			pino2 = processEmpilhamentoDisco(pino2,pilhaFoiAlterada);

			cout << "pilhaFoiAlterada: " << pilhaFoiAlterada << endl;

			if(pilhaFoiAlterada){
				if(codPinoOndeSeEncontraAnt == 1){
					pino1.pilhaDeDiscos.remove(); //remove a primeira posicção
					cout << "pilha foi alterada remover primeira posicao de pino 1";
				}
				else if(codPinoOndeSeEncontraAnt == 3){
					pino3.pilhaDeDiscos.remove(); //remove a primeira posicção
					cout << "pilha foi alterada remover primeira posicao de pino 3";
				}
			}

			if(pino2SizeAnt == pino2.pilhaDeDiscos.quantElements()){

				cout << "Não foi posssível colocar o pino na pilha selecionada " << endl;
				x = xCopia;
				y = yCopia;
				dx = dxCopia;
				dy = dyCopia;

				return;
			}
		}
	}
	else if(pinoOndeOuveAColisao == 3){

		if(codPinoOndeSeEncontra == pinoOndeOuveAColisao){
			cout << "Pino da colisão é igual ao pino onde o disco ja estava " << endl;
			x = xCopia;
			y = yCopia;
			dx = dxCopia;
			dy = dyCopia;

			return;
		}
		else{

			int pino3SizeAnt = pino3.pilhaDeDiscos.quantElements();

			bool pilhaFoiAlterada = false;
			int codPinoOndeSeEncontraAnt = codPinoOndeSeEncontra;

			pino3 = processEmpilhamentoDisco(pino3,pilhaFoiAlterada);

			cout << "pilhaFoiAlterada: " << pilhaFoiAlterada << endl;

			if(pilhaFoiAlterada){
				if(codPinoOndeSeEncontraAnt == 1){
					pino1.pilhaDeDiscos.remove(); //remove a primeira posicção
					cout << "pilha foi alterada remover primeira posicao de pino 1";
				}
				else if(codPinoOndeSeEncontraAnt == 2){
					pino2.pilhaDeDiscos.remove(); //remove a primeira posicção
					cout << "pilha foi alterada remover primeira posicao de pino 2";
				}
			}

			if(pino3SizeAnt == pino3.pilhaDeDiscos.quantElements()){

				cout << "Não foi posssível colocar o pino na pilha selecionada " << endl;
				x = xCopia;
				y = yCopia;
				dx = dxCopia;
				dy = dyCopia;

				return;
			}
		}
	}

}