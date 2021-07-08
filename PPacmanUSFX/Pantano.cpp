#include "Pantano.h"
Pantano::Pantano(Tile* _tile, Texture* _textura) :
	GameActor(_textura) {
	tileActual = _tile;
	if (tileActual != nullptr) {
		tileActual->setPantano(this);

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
};
void Pantano::setTileActual(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setPared(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPantano(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

}
void Pantano::update()
{
	/*if (contadorTiempoVisible >= tiempoVisible) {
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
	*/
}