#pragma once

#include "Fantasma.h"

class FantasmaAsesino : public Fantasma
{
public:
    FantasmaAsesino(Tile* _tile, Texture* _fantasmaAsesinoTextura, int _velocidadPatron);
    Fantasma* clone();
};
