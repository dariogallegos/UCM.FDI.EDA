
//Ejericicio 5 del tema 8 -TADS Lineales



#include<iostream>
#include "pila.h"

using namespace std;

/**
Procedimiento que almacena los valores leidos por consola en la pila.
@param pila, objeto de tipo Pila<T> donde alamcenamos los valores.
*/
template<class T>
void cargarPila(Pila<T> & pila) { //Lleva un & pues necesitamos modificar la pila para almacenar los datos.
	T elemento;
	for (int i = 0; i < 10; i++) {
		cin >> elemento;
		pila.apila(elemento);
	}
}

/**
Procedimiento que muestra los valores almacenados en pila desde la base hasta la cima.
@param pila,objeto de clase Pila<T> que contiene los elementos.
*/
template<class T>
void mostrarPila(Pila<T> pila) {
	
	Pila <T> aux;

	while (!pila.esVacia()) {
		aux.apila(pila.cima());
		pila.desapila();
	}

	while (!aux.esVacia()) {
		cout << aux.cima() << " ";
		aux.desapila();
	}
}

/**
Procedimiento recursivo que muestra los valores de la pila desde la base a la cima.
@param pila,objeto de clase Pila<T> que contiene los elementos.
*/
template <class T>
void mostrarPilaRecursiva(Pila<T>pila) {
	if (pila.esVacia()) {}		//Caso base -- cuando la pila esta vacia.
	else {
		int elemento = pila.cima();// almacenamos la la cima para mostrar el valor en la respectiva vuelta de la llamada recursiva
		pila.desapila();		// eliminamos el elemento para pasar una pila mas paqueña en la ll.recursiva, asi hasta el caso base.
		pilaRecursiva(pila);	// llamada recursiva
		cout << elemento << " ";
	}
}



int main() {

	Pila<int> pila = Pila<int>();
	cargarPila(pila);
	mostrarPila(pila);
	mostrarPilaRecursiva(pila);
	return 0;
}