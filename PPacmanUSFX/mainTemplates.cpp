#include <iostream>
#include <array>
#include "pila.h"

using namespace std;

//template <class T>
//void ImprimirArreglo(T* arreglo, int numeroElementos) {
//	for (int i = 0; i < numeroElementos; i++) {
//		cout << arreglo[i] << " ";
//	}
//}


//void ImprimirArregloEntero(int _a[], int ne) {
//	for (int i = 0; i < ne; i++) {
//		cout << _a[i] << " ";
//	}
//}
//
//void ImprimirArregloDouble(double _a[], int ne) {
//	for (int i = 0; i < ne; i++) {
//		cout << _a[i] << " ";
//	}
//}
//
//void ImprimirArregloFloat(array<float, 6> _a, int ne) {
//	for (int i = 0; i < ne; i++) {
//		cout << _a[i] << " ";
//	}
//}


int main() {
	Pila<double> PilaDouble(3);

	PilaDouble.Insertar(8.0);
	PilaDouble.Insertar(4.9);
	PilaDouble.Insertar(7.0);

	Pila<string> PilaString(2);

	PilaString.Insertar("Hola como estas");
	PilaString.Insertar("Bien no mas");


	cout << PilaString.Sacar() << endl;
	cout << PilaString.Sacar() << endl;


	cout << PilaDouble.Sacar() << endl;
	cout << PilaDouble.Sacar() << endl;
	cout << PilaDouble.Sacar() << endl;

	PilaDouble.Insertar(4.0);
	cout << PilaDouble.Sacar() << endl;

	//const int numeroElementosA = 3;
	//const int numeroElementosB = 8;
	//const int numeroElementosC = 4;
	//const int numeroElementosD = 5;
	//const int numeroElementosE = 6;
	//int a[numeroElementosA] = { 1, 2, 3 };
	//double b[numeroElementosB] = { 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0 };
	//char c[numeroElementosC] = { 'H', 'o', 'l', 'a' };
	//string d[10] = { "hola", "como", "estan", "estimados", "estudiantes" };
	//float e[numeroElementosE] = { 3.5f, 4.7f, 7.9f, 1.5f, 456.9f, -4565.9f };
	//cout << "Estos son los elmentos del arreglo A" << endl;
	////ImprimirArregloEntero(a, numeroElementosA);
	//ImprimirArreglo(a, numeroElementosA);

	//cout << endl << "Estos son los elmentos del arreglo B" << endl;
	////ImprimirArregloDouble(b, numeroElementosB);
	//ImprimirArreglo(b, numeroElementosB);

	//cout << endl << "Estos son los elmentos del arreglo C" << endl;
	////ImprimirArregloFloat(e, numeroElementosE);
	//ImprimirArreglo(c, numeroElementosC);

	//cout << endl << "Estos son los elmentos del arreglo D" << endl;
	////ImprimirArregloFloat(e, numeroElementosE);
	//ImprimirArreglo(d, numeroElementosD);

	//cout << endl << "Estos son los elmentos del arreglo E" << endl;
	////ImprimirArregloFloat(e, numeroElementosE);
	//ImprimirArreglo(e, numeroElementosE);

	//cout << endl;

	/*ImprimirArreglo(b, numeroElementosB);

	cout << endl << "Estos son los elmentos del arreglo C" << endl;
	ImprimirArreglo(c, numeroElementosC);


	cout << endl << "Estos son los elmentos del arreglo D" << endl;
	ImprimirArreglo(d, numeroElementosD);*/

	cout << endl;
	system("pause");
	return 0;
}
