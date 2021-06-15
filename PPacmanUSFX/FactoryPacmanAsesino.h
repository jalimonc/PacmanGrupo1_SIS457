#pragma once
#include "Factory.h"
#include "PacmanAsesino.h"
#include "FantasmaAsesino.h"
#include "ParedAsesino.h"
#include "FrutaAsesino.h"
#include "MonedaAsesino.h"
#include "Tile.h"

class FactoryPacmanAsesino :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createFantasmaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, bool _isElectric) override;
    GameObject* createFrutaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) override;
};
