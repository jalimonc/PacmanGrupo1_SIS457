#pragma once
#include "GameActor.h"
class Pantano :
    public GameActor
{
protected:

    int tiempoVisible;
    int tiempoInvisible;

    int contadorTiempoVisible;
    int contadorTiempoInvisible;

public:

    Pantano(Tile* _tile, Texture* _textura);
    void setTileActual(Tile* _tileNuevo);

    void update() ;
    void handleEvent(SDL_Event* event) {};
    void deleteGameObject() {};

};

