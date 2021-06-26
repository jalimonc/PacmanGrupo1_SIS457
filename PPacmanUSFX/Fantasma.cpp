#include "Fantasma.h"

Fantasma::Fantasma(Tile* _tile, Texture* _fantasmaTexture, int _velocidad) :
	GameObject(_fantasmaTexture, _tile)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_fantasmaTexture);
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));

	if (tileActual != nullptr)
		tileActual->setFantasma(this);

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;

	velocidad = _velocidad;

	framesMovimiento = 4;
}

Fantasma::~Fantasma() {
	deleteGameObject();
}

void Fantasma::reconfigurar(Tile* _tile, int _velocidad)
{
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		tileSiguiente = tileActual;

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

	}
	colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
	velocidad = _velocidad;
}

void Fantasma::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setFantasma(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}

void Fantasma::update()
{
	Pacman* pacman = tileGraph->getPacman();

	if (pacman != nullptr) {

		if (tileActual == tileSiguiente) {
			PathFinder astar(tileGraph);
			astar.SetAvoidFunction(Fantasma::avoidInPathFinder);
			camino = astar.CalculateRoute(tileActual, pacman->getTile());

			if (camino.size() > 1) {
				tileSiguiente = camino[1];
			}

			if (posicionX < tileSiguiente->getPosicionX() * Tile::anchoTile)
				direccionActual = MOVE_RIGHT;

			else if (posicionX > tileSiguiente->getPosicionX() * Tile::anchoTile)
				direccionActual = MOVE_LEFT;

			else if (posicionY > tileSiguiente->getPosicionY() * Tile::anchoTile)
				direccionActual = MOVE_UP;

			else if (posicionY < tileSiguiente->getPosicionY() * Tile::anchoTile)
				direccionActual = MOVE_DOWN;

			if (revisarColision(pacman->getColisionador())) {
				pacman->restarEnergia();
				if (pacman->getEnergia() <= 0) {
					tileActual->setPacman(nullptr);
					pacman->deleteGameObject();
				}
			}
		}

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

void Fantasma::render()
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

bool Fantasma::avoidInPathFinder(Tile* _tile)
{
	if (_tile->getPared() != nullptr)
		return true;
	return false;
}

void Fantasma::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setFantasma(nullptr);
}

