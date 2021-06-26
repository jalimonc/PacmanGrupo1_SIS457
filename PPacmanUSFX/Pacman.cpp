#include <stdio.h>
#include "Pacman.h"



Pacman::Pacman(Tile* _tile, Texture* _texturaPacman, int _velocidad) :
	GameObject(_texturaPacman, _tile)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_texturaPacman);
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));

	if (tileActual != nullptr)
		tileActual->setPacman(this);

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;

	velocidad = _velocidad;
	energia = 5;

	framesMovimiento = 2;
}

void Pacman::restarEnergia() {
	if (energia > 0) {
		energia--;
	}
}

Pacman::~Pacman() {
	deleteGameObject();
}


void Pacman::setTile(Tile* _tileNuevo) {

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

void Pacman::handleEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN && event->key.repeat == 0) {
		switch (event->key.keysym.sym)
		{
			// Move up
		case SDLK_UP:
			direccionSiguiente = MOVE_UP; break;

			// Move down
		case SDLK_DOWN:
			direccionSiguiente = MOVE_DOWN; break;

			// Move left
		case SDLK_LEFT:
			direccionSiguiente = MOVE_LEFT; break;

			// Move right
		case SDLK_RIGHT:
			direccionSiguiente = MOVE_RIGHT; break;
		}
	}
}

bool Pacman::tratarDeMover(MoveDirection _direccionNueva)
{
	Tile* tileDestino = nullptr;

	// Retorna el tile destino dependiendo de la direccion de movimiento

	switch (_direccionNueva)
	{
	case MOVE_UP:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - 1);
		break;
	case MOVE_DOWN:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + 1);
		break;
	case MOVE_LEFT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - 1, tileActual->getPosicionY());
		break;
	case MOVE_RIGHT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + 1, tileActual->getPosicionY());
		break;
	}

	// Si el tile destino es nullptr, no se puede avanzar ahi
	if (tileDestino == nullptr) {
		switch (_direccionNueva)
		{
		case MOVE_UP:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + tileGraph->getAltoTile() - 1);
			break;
		case MOVE_DOWN:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - (tileGraph->getAltoTile() - 1));
			break;
		case MOVE_LEFT:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + tileGraph->getAnchoTile() - 1, tileActual->getPosicionY());
			break;
		case MOVE_RIGHT:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - (tileGraph->getAnchoTile() - 1), tileActual->getPosicionY());
			break;
		}
	}
	// Si el tile destino es una pared, no se puede avanzar ahi
	if (tileDestino->getPared() != nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	setTileSiguiente(tileDestino);

	return true;
}

void Pacman::update()
{
	colisionador = new SDL_Rect({ posicionX, posicionY, ancho, alto });
	if (tileActual != nullptr && tileActual->getMoneda() != nullptr) {
		if (revisarColision(colisionador, tileActual->getMoneda()->getColisionador())) {
			tileActual->getMoneda()->deleteGameObject();
		}
	}
	if (tileActual != nullptr && tileActual->getFruta() != nullptr) {
		if (revisarColision(colisionador, tileActual->getFruta()->getColisionador())) {
			tileActual->getFruta()->deleteGameObject();
		}
	}

	if (enMovimiento) {
		GameObject::update();
	}

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
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);
	}
}
void Pacman::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();

	switch (direccionActual) {
	case MOVE_UP:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_DOWN:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_LEFT:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_RIGHT:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("derecha")[numeroFrame];
		break;
	}

	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}

void Pacman::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setPacman(nullptr);
}


