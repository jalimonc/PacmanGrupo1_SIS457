#include "ParedAsesino.h"

ParedAsesino::ParedAsesino(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, bool _isElectrica)
	:Pared(_tile, _paredTextura, _posicionX, _posicionY)
{
	tipoTexturaPared = 14;
	setTexture(tipoTexturaPared);
	isElectrica = _isElectrica;
	tileActual = _tile;
	isAsesino = true;
	state = 0;
}

void ParedAsesino::update() {
	if (isElectrica) {
		velocidadPacman = 5;
		if (cont2 <= notElectricTime) {
			cont2++;
			if (cont2 >= notElectricTime) {
				cont1 = 0;
				setTexture(11);
				state = 1;
			}
		}
		else {
			if (cont1 <= electricTime) {
				cont1++;
				if (cont1 >= electricTime) {
					cont2 = 0;
					setTexture(10);
					state = 0;
					for (auto tile : tileGraph->get4Vecinos(tileActual)) {
						if (tile != nullptr && tile->getPacman() != nullptr && tile->getPacman()->getState() == 2) {
							tile->getPacman()->setVelocidad(velocidadPacman);
							tile->getPacman()->setState(0);
						}
					}
				}
			}
		}
	}
	if (state == 1) {
		for (auto tile : tileGraph->get4Vecinos(tileActual)) {
			if (tile != nullptr && tile->getPacman() != nullptr) {
				tile->getPacman()->setState(2);
				tile->getPacman()->setVelocidad(0);
			}
		}
	}
}