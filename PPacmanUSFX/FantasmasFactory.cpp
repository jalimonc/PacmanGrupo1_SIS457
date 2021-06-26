#include "FantasmasFactory.h"

Fantasma* FantasmasFactory::tipoBlinky = nullptr;
Fantasma* FantasmasFactory::tipoClyde = nullptr;
Fantasma* FantasmasFactory::tipoInkey = nullptr;
Fantasma* FantasmasFactory::tipoPinky = nullptr;


Fantasma* FantasmasFactory::getTipoBlinky()
{
	return tipoBlinky->clone();
}

Fantasma* FantasmasFactory::getTipoClyde()
{
	return tipoClyde->clone();
}

Fantasma* FantasmasFactory::getTipoInkey()
{
	return tipoInkey->clone();
}

Fantasma* FantasmasFactory::getTipoPinky()
{
	return tipoPinky->clone();
}