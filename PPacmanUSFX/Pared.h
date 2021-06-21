#pragma once
#include "GameObject.h"
#include "TipoTexturaPared.h"
#include "TileGraph.h"

class Pared :
    public GameObject
{
protected:
    Tile* tileActual;
    int frameX;
    int frameY;
    int altoClip;
    int anchoClip;
    int tipoTexturaPared;
    GameObjectType returType() { return PARED; }
public:
    Pared(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);
    Tile* getTile() { return tileActual; }
    void setTile(Tile* _tileNuevo);
    void render() override;
    void setTexture(int tipoTextura);
};

