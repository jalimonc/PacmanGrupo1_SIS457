#include "FactoryPacmanAsesino.h"

GameObject* FactoryPacmanAsesino::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
	return new PacmanAsesino(_tile, _textureManager->getTexture("pacman_galactico"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanAsesino::createFantasmaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY, int _velocidad) {
	return new FantasmaAsesino(_tile, _textureManager->getTexture("fantasma_Asesino1"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanAsesino::createParedInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY,bool _isElectric) {
	return new ParedAsesino(_tile, _textureManager->getTexture("pared_clasico"), _posicionX, _posicionY, _isElectric);
}

GameObject* FactoryPacmanAsesino::createFrutaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
	return new FrutaAsesino(_tile, _textureManager->getTexture("fruta_asesino"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanAsesino::createMonedaInstance(Tile* _tile, TextureManager* _textureManager, int _posicionX, int _posicionY) {
	return new MonedaAsesino(_tile, _textureManager->getTexture("moneda_clasico"), _posicionX, _posicionY);
}

