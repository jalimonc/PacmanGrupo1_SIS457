#include "FactoryPacmanAsesino.h"

GameObject* FactoryPacmanAsesino::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) {
    return new PacmanAsesino(_tile, _textureManager->getTexture("pacman_asesino"), _velocidad);
}

GameObject* FactoryPacmanAsesino::createParedInstance(Tile* _tile, TextureManager* _textureManager, bool _isElectric) {
    return new ParedAsesino(_tile, _textureManager->getTexture("pared_asesino"), false);
}

GameObject* FactoryPacmanAsesino::createMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MonedaAsesino(_tile, _textureManager->getTexture("moneda_asesino"));
}
