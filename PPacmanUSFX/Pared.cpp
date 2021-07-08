#include "Pared.h"

Pared::Pared(Tile* _tile, Texture* _textura) :
	GameActor(_textura) {
	//tipoTexturaPared = TEXTURA_UNO;
	//setTexture(tipoTexturaPared);
	tileActual = _tile;
	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
	visible = true;

	tiempoVisible = 300;
	tiempoInvisible = 0;
	contadorTiempoVisible = 0;
	contadorTiempoInvisible = 0;
	int numeroFrutaVisible = 0;
};

void Pared::setTileActual(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setPared(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

}
void Pared::update()
{
	if (contadorTiempoVisible >= tiempoVisible) {
			visible = false;
		if (contadorTiempoInvisible >= tiempoInvisible ) {
			int x = 1 + rand() % TileGraph::anchoTileGraph;
			int y = 1 + rand() % TileGraph::altoTileGraph;
			if (tileActual != tileGraph->getTileEn(x, y))
			{
				visible = true;
			}
			else {
				visible = false;
				contadorTiempoVisible = 0;
				contadorTiempoInvisible = 0;
			}
				
		}
		else {
			contadorTiempoInvisible++;
		}
	}
	else{
		contadorTiempoVisible++;
	}
	
}

void Pared::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setPared(nullptr);
}
