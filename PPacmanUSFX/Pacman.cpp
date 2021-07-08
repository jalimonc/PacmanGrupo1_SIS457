#include <stdio.h>
#include "Pacman.h"

Pacman::Pacman(Tile* _tile, Texture* _textura) :GamePawn(_textura)
{
	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	colisionador->w = ancho;
	colisionador->h = alto;

	velocidad = 5;
	movil = true;
	enMovimiento = false;
	direccionActual = MOVE_STILL;
	direccionSiguiente = MOVE_STILL;

	gamePawnController = new GamePawnControllerKey1();
}

void Pacman::setTileActual(Tile* _tileNuevo) {


	if (tileActual != nullptr) {
		tileActual->setPacman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}

void Pacman::update()
{
	// Revisar colisiones con monedas
	// NOTE: Should this be nextTile?
	if (tileActual != nullptr && tileActual->getMoneda() != nullptr) {
		SDL_Rect* eatingHole = new SDL_Rect({
			posicionX /*+ Point::Margin*/,
			posicionY /*+ Point::Margin*/,
			ancho,
			alto,
			});

		if (revisarColision(eatingHole, tileSiguiente->getMoneda()->getColisionador())) {
			tileSiguiente->getMoneda()->deleteGameObject();
		}
	}

	// Animacion de pacman
	if (enMovimiento) {
		
		GamePawn::update();
	}

	// Cambiar de tile/direccion
	if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			tratarDeMover(direccionActual);

		if (tileSiguiente == nullptr)
			enMovimiento = false;
		else
			enMovimiento = true;
	}
	else {
		switch (direccionActual)
		{
		case MOVE_UP:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_DOWN:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_LEFT:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_RIGHT:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}


		colisionador->x = posicionX;
		colisionador->y = posicionY;

		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTileActual(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTileActual(tileSiguiente);
	}
	//reposicionar pacman si sale del mapa 

	if (tileSiguiente == nullptr) {
		switch (direccionSiguiente)
		{
		case MOVE_UP:
			tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + tileGraph->altoTileGraph - 1);
			break;
		case MOVE_DOWN:
			tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - tileGraph->altoTileGraph + 1);
			break;
		case MOVE_LEFT:
			tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX() + tileGraph->anchoTileGraph - 1, tileActual->getPosicionY());
			break;
		case MOVE_RIGHT:
			tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX() - tileGraph->anchoTileGraph + 1, tileActual->getPosicionY());
			break;
		}
	}
	/*if (tileActual->getPantano() != nullptr )
	{
		if (posicionX == 10 && posicionY == 4) 
		{
			posicionX = 9;
			posicionY = 12;
		}
		tileActual = tileGraph->getTileEn(posicionX,posicionY);
	}

	if (tileActual->getPantano() != nullptr) {
		if(posicionX == 10 && posicionY == 4){
			tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX()+1, tileActual->getPosicionY() + 8);
		}
		else {
			tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX() + 1, tileActual->getPosicionY() + 8);
		}
	}*/
}

void Pacman::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();

	switch (direccionActual) {
	case MOVE_UP:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_DOWN:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_LEFT:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_RIGHT:
		cuadroAnimacion = framesAnimacion->getCuadrosAnimacion("derecha")[numeroFrame];
		break;
	}

	textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}

void Pacman::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setPacman(nullptr);
}