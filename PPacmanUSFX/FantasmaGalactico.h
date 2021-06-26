#pragma once
#include "Fantasma.h"

class FantasmaGalactico : public Fantasma
{
public:
    FantasmaGalactico(Tile* _tile, Texture* _fantasmaGalacticoTextura, int _velocidadPatron);
    Fantasma* clone();
};
