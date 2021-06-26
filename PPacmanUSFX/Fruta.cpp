#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Tile* _tile, Texture* _frutaTexture) :
	GameObject(_frutaTexture, _tile)
{
	tileActual = _tile;

	if (tileActual != nullptr)
		tileActual->setFruta(this);

	tipoFruta = TIPO_FRUTA_FRUTILLA;

	visible = false;

	tipoFruta = TIPO_FRUTA_FRUTILLA;
	
	visible = false;
	
	tiempoVisible = 100;
	tiempoInvisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoInvisible = 0;
	int numeroFrutaVisible = 0;
}

