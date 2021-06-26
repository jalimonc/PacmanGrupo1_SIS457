#pragma once
#include "Factory.h"
#include "PacmanClasico.h"
#include "ParedClasico.h"
#include "ParedClasicoAdapter.h"
#include "MonedaClasico.h"

class FactoryPacmanClasico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager, bool _isElectric) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager) override;
};

