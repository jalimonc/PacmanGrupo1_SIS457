#include "MapGenerator.h"

//MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla, Factory* _factory)
MapGenerator::MapGenerator(TileGraph* _tileGraph, /*TextureManager* _textureManager,*/ int _anchoPantalla, int _altoPantalla)
{
	//factory = _factory;
	tileGraph = _tileGraph;
	//textureManager = _textureManager;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		//FantasmasFactory::initialize();

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Fantasma* objetoFantasmaClonado = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				objetoNuevo = new Pared(tileNuevo, TextureManager::getInstancia()->getTextura("pared_clasico"));
				
				((GameActor*)objetoNuevo)->setFramesDireccion(1);

				/*objetoNuevo = factory->createParedInstance(tileNuevo, textureManager, x * Tile::altoTile, y * Tile::altoTile, false);
				objetoNuevo->setFramesDireccion(1);*/
				break;
			case '.':
				objetoNuevo = new Moneda(tileNuevo, TextureManager::getInstancia()->getTextura("moneda_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(4);

				/*objetoNuevo = factory->createMonedaInstance(tileNuevo, textureManager, x * 25, y * 25);
				objetoNuevo->setFramesDireccion(4);*/
				break;
			case 'p':
				objetoNuevo = new Pacman(tileNuevo, TextureManager::getInstancia()->getTextura("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(TextureManager::getInstancia()->getFramesAnimacion("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);

				/*objetoNuevo = factory->createPacmanInstance(tileNuevo, textureManager, x * 25, y * 25, 5);
				objetoNuevo->setFramesDireccion(2);*/
				break;
			case 'm':
				objetoNuevo = new MsPacman(tileNuevo, TextureManager::getInstancia()->getTextura("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(TextureManager::getInstancia()->getFramesAnimacion("pacman_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				break;

			case 'n':
				objetoNuevo = new Pantano(tileNuevo, TextureManager::getInstancia()->getTextura("pantano_clasico"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(TextureManager::getInstancia()->getFramesAnimacion("pantano_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(1);
				break;

			case 'a':
				objetoNuevo = new Fantasma(tileNuevo, TextureManager::getInstancia()->getTextura("fantasma_clasico1"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(TextureManager::getInstancia()->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(2);
				((GameActor*)objetoNuevo)->setVelocidad(3);

				/*
				objetoNuevo = FantasmasFactory::getTipoClasicoBlinky();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, x * 25, y * 25, 5);
				objetoNuevo->setFramesDireccion(4);
				*/

				/*objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 1);
				objetoNuevo->setFramesDireccion(4);
				objetoFantasmaClonado = ((Fantasma*)objetoNuevo)->clone();
				if (objetoFantasmaClonado != nullptr) {
					objetoFantasmaClonado->setVelocidadPatron(4);
					cout << "Se ha clonado satisfactoriamente el fantasma 1" << endl;
					vectorObjetosJuego.push_back(objetoFantasmaClonado);
				}
				objetoFantasmaClonado = ((Fantasma*)objetoNuevo)->clone();
				if (objetoFantasmaClonado != nullptr) {
					objetoFantasmaClonado->setVelocidadPatron(5);
					cout << "Se ha clonado satisfactoriamente el fantasma 1" << endl;
					vectorObjetosJuego.push_back(objetoFantasmaClonado);
				}*/
				break;
			case 'b':
				objetoNuevo = new Fantasma(tileNuevo, TextureManager::getInstancia()->getTextura("fantasma_clasico2"));
				((GameActor*)objetoNuevo)->setFramesAnimacion(TextureManager::getInstancia()->getFramesAnimacion("fantasma_clasico"));
				((GameActor*)objetoNuevo)->setFramesDireccion(3);
				((GameActor*)objetoNuevo)->setVelocidad(2);

				/*objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 2);
				objetoNuevo->setFramesDireccion(4);*/
				break;
			case 'c':
				/*objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 2);
				objetoNuevo->setFramesDireccion(4);*/
				break;
			case 'd':
				/*objetoNuevo = factory->createFantasmaInstance(tileNuevo, textureManager, x * 25, y * 25, 3);
				objetoNuevo->setFramesDireccion(4);*/
				break;
			}

			// If the object was created, add it to the vector
			if (objetoNuevo != nullptr) {
				vectorObjetosJuego.push_back(objetoNuevo);
			}
		}

		y++;
	}

	// Close the file
	file.close();

	GameObject* contenedorPaneles = new GUIComposite(TextureManager::getInstancia()->getRenderer(), "Root");
	GameObject* objetoPanel1 = new Panel(TextureManager::getInstancia()->getRenderer(), 620, 50, 150, 300, "PANEL A");
	((Panel*)objetoPanel1)->setPanelColorRGBA(250, 180, 35, 250);
	GameObject* objetoPanel2 = new Panel(TextureManager::getInstancia()->getRenderer(), 550, 500, 100, 50, "PANEL B");
	((Panel*)objetoPanel1)->setPanelColorRGBA(10, 255, 24, 255);
	((GUIComposite*)contenedorPaneles)->add((Component*)objetoPanel1);
	((GUIComposite*)contenedorPaneles)->add((Component*)objetoPanel2);

	/*((GUIComposite*)contenedorPaneles)->add(550, 500, 100, 50, "PANEL B", 10, 255, 24, 255, true);
	((GUIComposite*)contenedorPaneles)->add(570, 75, 50, 50, "BUTTON A", 0, 5, 65, 255, true);
	vectorObjetosJuego.push_back(contenedorPaneles);
	GameObject* objetoPanel = new Panel(TextureManager::getInstancia()->getRenderer(), 620, 50, 150, 300, "BUTTON A");
	((Panel*)objetoPanel)->setPanelColorRGBA(250, 180, 35, 250);*/
	vectorObjetosJuego.push_back(contenedorPaneles);


	/*GameObject* objetoPanel = new GamePanel(new Texture(), 20, 450);
	vectorObjetosJuego.push_back(objetoPanel);*/

	return true;
}

void MapGenerator::populate(std::vector<GameObject*> &_vectorObjetosJuegoGM)
{
	/*for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}*/

	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}

}