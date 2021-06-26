#pragma once
#include <SDL.h>
#include "GameObject.h"


using namespace std;

enum TIPO_FRUTA {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_FRUTILLA,
	TIPO_FRUTA_MAXIMO
};

enum GameFrutaType {
	FRUTA_CLASICO,
	FRUTA_GALACTICO,
	FRUTA_ASESINO
};

class Fruta : public GameObject {
protected:

	TIPO_FRUTA tipoFruta;
	GameFrutaType GameFrutaTipo;

	int tiempoVisible;
	int tiempoInvisible;

	int contadorTiempoVisible;
	int contadorTiempoInvisible;
	int numeroFrutaVisible;

	Tile* tileActual;
	
public:

	
	Fruta(Tile* _tile, Texture* _frutaTexture);
	~Fruta();
	void reconfigurar(Tile* _tileNuevo, TIPO_FRUTA tipoFruta);
	
	
	
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoInvisible() { return tiempoInvisible; }
	Tile* getTileActual() { return tileActual; }

	void setTipoFruta(TIPO_FRUTA _tipoFruta) { tipoFruta = _tipoFruta; }
	void setTiempoVisible(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoInvisible(int _tiempoInvisible) { tiempoInvisible = _tiempoInvisible; }
	void setTileActual(Tile* _tileNuevo);
	TIPO_FRUTA getTipoFruta() { return tipoFruta; }
	GameFrutaType getTipo() { return GameFrutaTipo; }

	void setTile(Tile* _tileNuevo);

	void update();
	void render() override;

	void deleteGameObject() override;
};


