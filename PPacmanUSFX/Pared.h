#pragma once
#include "GameActor.h"
#include "TipoTexturaPared.h"
#include "TileGraph.h"

class Pared :
    public GameActor
{
protected:

    int tiempoVisible;
    int tiempoInvisible;

    int contadorTiempoVisible;
    int contadorTiempoInvisible;

    GameObjectType returType() { return PARED; }
public:
    Pared(Tile* _tile, Texture* _textura);
    void setTileActual(Tile* _tileNuevo);

    void update();
    void handleEvent(SDL_Event* event) {};
    void deleteGameObject();
};

