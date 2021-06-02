#include "Pared.h"

Pared::Pared(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla):
GameObject(_paredTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla){
	
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
	visible = true;

	tiempoVisible = 0;
	tiempoNoVisible = 0;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
};

void Pared::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setPared(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
};
void Pared::update()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			tiempoVisible = 100 + rand() % 1500;
			tiempoNoVisible = 100 + rand() % 1500;
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
			//numeroFrutaVisible = rand() % frutasTextures.size();
		}
		else {
			contadorTiempoNoVisible++;
			//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}
void Pared::render()
{

	if (visible) {
		SDL_Rect* cuadroAnimacion = new SDL_Rect({ 25 * numeroFrame, 0, getAncho(), getAlto() });

		// Renderizar en la pantalla
		textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
	}
}


