#pragma once
#include "GameObject.h"
#include "TileGraph.h"
#include "Tile.h"

class Pared :
    public GameObject
{
private:
    Tile* tileActual;
    int tiempoVisible;
    int tiempoNoVisible;

    int contadorTiempoVisible;
    int contadorTiempoNoVisible;

public:
    Pared(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
    Tile* getTile() { return tileActual; }
    void setTile(Tile* _tileNuevo);
    void update();
    void render() override;
};

