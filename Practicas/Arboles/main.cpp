#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numeroTramosNavegablesAux(const Arbin<int>& cuenca, int & cuentaTres){
	
	if (cuenca.esVacio()) // CB: si esta vacia devuelve un cero
		return 0;
	else if (cuenca.hijoIz().esVacio() && cuenca.hijoDer().esVacio()){
		return 1; // CB: si no es vacia pero no tiene hijos es que soy hoja y vuelvo 1.
	}
	else{ //CR: soy raiz
		int sumaHijoIz = 0;
		int sumaHijoDer = 0;
		int total = 0;

		/*if (!cuenca.hijoIz().esVacio()){
			 sumaHijoIz = numeroTramosNavegablesAux(cuenca.hijoIz(),cuentaTres);
		}

		if (!cuenca.hijoDer().esVacio()){
			sumaHijoDer = numeroTramosNavegablesAux(cuenca.hijoDer(), cuentaTres);
		}*/
		sumaHijoIz = numeroTramosNavegablesAux(cuenca.hijoIz(), cuentaTres);
		sumaHijoDer = numeroTramosNavegablesAux(cuenca.hijoDer(), cuentaTres);

		if (sumaHijoDer >= 3)
			cuentaTres++;
		if (sumaHijoIz >= 3)
			cuentaTres++;

		total = sumaHijoDer + sumaHijoIz + cuenca.raiz();

		if (total < 0)
			total = 0;
		return total;
	}
	
}


int numeroTramosNavegables(const Arbin<int>& cuenca) {
	int suma = 0;
	int cuentaTres = 0;
	numeroTramosNavegablesAux(cuenca,cuentaTres);
	return cuentaTres;
}


Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}