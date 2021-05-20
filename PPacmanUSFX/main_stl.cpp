#include <iostream>
#include <string>

#include <set>
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>


#include <algorithm>

using namespace std;


int main() {
	map<string, vector<int>> mapAnimaciones;
	vector<int> vectorAnimacionPacman{ 0, 0, 25, 25 };
	mapAnimaciones.insert({ "arriba", vectorAnimacionPacman });
	vector<int> vectorAnimacionFPacman{ 120, 10, 225, 25 };
	mapAnimaciones.insert({ "abajo", vectorAnimacionPacman });

	for (auto elemento : mapAnimaciones) {
		cout << elemento.first;
		for (auto elementoVector : elemento.second) {
			cout << elementoVector << ", ";
		}
		cout << endl;
	}

	auto a = mapAnimaciones["arriba"];
	for (auto e : a) {
		cout << e << " , ";
	}

	set<int> conjuntoEnteros;
	map<string, int> personasEdades;
	conjuntoEnteros.insert(10);
	conjuntoEnteros.insert(34);
	conjuntoEnteros.insert(5);
	conjuntoEnteros.insert(10);

	for (auto elemento : conjuntoEnteros) {
		cout << elemento << endl;
	}

	cout << endl;

	//personasEdades["Juan"] = 35;
	//personasEdades["Pedro"] = 45;

	/*for (auto par : personasEdades) {
		cout << par.first << "--" << par.second << endl;
	}*/

	pair<string, int> boris2{ "Boris", 14 };

	pair<string, int> jose2;
	jose2.first = "jose maria";
	jose2.second = 44;
	personasEdades.insert(pair<string, int>{"Jose", 18});
	personasEdades.insert(pair<string, int>{"Antonio", 23});
	personasEdades.insert(pair<string, int>{"Antonio", 43});
	personasEdades.insert(pair<string, int>{"Boris", 14});
	personasEdades.insert(boris2);
	personasEdades.insert(jose2);
	personasEdades.insert({ "Carlos", 25 });
	//personasEdades["Pedro"] = 21;

	for (auto par : personasEdades) {
		cout << par.first << "--" << par.second << endl;
	}

	system("pause");
	return 0;
}