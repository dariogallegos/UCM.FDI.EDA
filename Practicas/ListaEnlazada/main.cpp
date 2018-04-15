#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include"pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS


void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	Lista<char>::ConstIterator iterador = mensaje.cbegin();
	Lista<char>::Iterator consonantePrimer = mensaje.begin();
	Pila<char> pila = Pila<char>();

	if (!mensaje.esVacia()){
		int consonantes = 0;
		while (iterador != mensaje.cend()){
			char caracter = iterador.elem();

			if (caracter != 'a' && caracter != 'e' && caracter != 'i' &&  caracter != 'o' && caracter != 'u'
				&& caracter != 'A' && caracter != 'E' && caracter != 'I' &&  caracter != 'O' && caracter != 'U'){
				pila.apila(caracter);
				consonantes++;
			}
			else {// desapilo de la pila e inserto elemento
				
				while (!pila.esVacia()) {
					consonantePrimer.set(pila.cima());
					pila.desapila();
					consonantePrimer.next();
				}
				consonantes = 0;
			}
			
			iterador.next();
			if (consonantes < 1)
				consonantePrimer.next();
		}

		while (!pila.esVacia()) {
			consonantePrimer.set(pila.cima());
			pila.desapila();
			consonantePrimer.next();
		}
	}
}

 
// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
