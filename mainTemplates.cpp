#include <iostream>
#include "pila.h"

using namespace std;

template <class T>
void ImprimirArreglo(T* arreglo, int numeroElementos) {
	for (int i = 0; i < numeroElementos; i++) {
		cout << arreglo[i] << " ";
	}
}


void ImprimirArregloEntero(int _a[], int ne) {
	for (int i = 0; i < ne; i++) {
		cout << _a[i] << " ";
	}
}

void ImprimirArregloDouble(double _a[], int ne) {
	for (int i = 0; i < ne; i++) {
		cout << _a[i] << " ";
	}
}


int main() {
	/*Pila<double> PilaDouble(3);

	PilaDouble.Insertar(8.0);
	PilaDouble.Insertar(4.9);
	PilaDouble.Insertar(7.0);

	Pila<string> PilaString(2);

	PilaString.Insertar("Hola como estas");
	PilaString.Insertar("Bien no mas");


	cout << PilaString.Sacar() << endl;
	cout << PilaString.Sacar() << endl;*/


	//PilaDouble.Insertar(4.0);

	const int numeroElementosA = 3;
	const int numeroElementosB = 8;
	const int numeroElementosC = 4;
	int a[numeroElementosA] = { 1, 2, 3 };
	double b[numeroElementosB] = { 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0 };
	char c[numeroElementosC] = { 'H', 'o', 'l', 'a' };
	string v[10] = { "hola", "como", "estan", "estimados", "estudiantes" };
	cout << "Estos son los elmentos del arreglo A" << endl;
	//ImprimirArregloEntero(a, numeroElementosA);
	ImprimirArreglo(a, numeroElementosA);

	cout << endl << "Estos son los elmentos del arreglo B" << endl;
	//ImprimirArregloDouble(b, numeroElementosB);
	//cout << endl;
	ImprimirArreglo(b, numeroElementosB);

	cout << endl << "Estos son los elmentos del arreglo C" << endl;
	ImprimirArreglo(c, numeroElementosC);


	system("pause");
	return 0;
}
