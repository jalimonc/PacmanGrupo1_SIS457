#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <algorithm>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"

#include "TextureAnimation.h"
#include "PathFinder.h"
#include "Pacman.h"
#include "GameObjectType.h"

using namespace std;

enum GameFantasmaType {
	FANTASMA_CLASICO,
	FANTASMA_GALACTICO
};


class Fantasma : public GameObject {
protected:
	//Velocidad en eje X y Y
	
	//Velocidad a la que mueve el fantasma en cualquier eje
	GameFantasmaType tipoFantasma;


	int velocidad;

	int incrementoPosicionX;
	int incrementoPosicionY;

	vector<Tile*> camino;
	SDL_Point lastPacmanPos;

	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	TextureAnimation* texturaAnimacion;

	bool tratarDeMover(MoveDirection _direccionNueva);
	
public:
	virtual Fantasma* clone() = 0;

	GameFantasmaType returnGameFantasmaType() { return tipoFantasma; }
public:
	//Constructores y destructores
	Fantasma(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _velocidad);
	//~Fantasma();

	//Metodos accesores
	void reconfigurar(Tile* _tile, int _posicionX, int _posicionY, int _velocidad);
	
	int getVelocidadPatron() { return velocidad; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }
	
	void setVelocidadPatron(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileNuevoSiguiente) { tileSiguiente = _tileNuevoSiguiente; }

	// Metodos varios
	
	// Actualizar datos fantasma
	virtual void update() override ;
	void render() override;
	static bool avoidInPathFinder(Tile* _tile);
	bool hasPositionChanged(SDL_Point firstPos, SDL_Point secondPoint);
	void deleteGameObject() override;
};