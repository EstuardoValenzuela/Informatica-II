#include <iostream>


using namespace std;

struct mapa {
	bool** posiciones;
	int ancho;
	int largo;
};

struct vector {
	int x;
	int y;
};

// Inicia cambio jejej putas 
//----------------------------------Problema #1------------------------

class vehiculo {
	public: vehiculo(mapa _mapa, vector _posicion) {
	    	espacio = _mapa;
		    posicion = _posicion;
            velocidad.x = 0;                 //velocidad en eje x
		    velocidad.y = 0;				 //velocidad en eje y
	        }

//--------------------------------Problema #2-----------------------------
	void estado() {
		printf("Posicion actual:(%i, %i)\n", posicion.x, posicion.y);                      //Imprime la posicion actual que tiene el vehiculo, mostrando la posicion en el eje X y Y
		printf("Velocidad actual:(%i, %i)\n\n",velocidad.x,velocidad.y);				   //Imprime la velocidad actual que tiene el vehiculo, mostrando la velocidad en el eje X y Y
	}

//--------------------------------Problema #3-------------------------
	void acelerar(vector a) {
		velocidad.x = velocidad.x + a.x;
		velocidad.y = velocidad.y + a.y;
	}
//--------------------------------Problema #4---------------------------
	bool avancevehiculo() {
		
		 int coorx = posicion.x + velocidad.x;      //Declaro variables y asigno valores
		 int coory = posicion.y + velocidad.y;
		 int n = posicion.x;
		 bool v; 									

		 int i = (cory-posicion.y)/(coorx-posicion.x);

		 while (v==true) {
			 
			 int fin = (i*(n - posicion.x))+posicion.y;
			 
			 if (espacio.posiciones[n][fin]==true && n<=coorx) {
			    	v = true; 
			    	n++;
		    	}
		    	else {
			    	v = false;
			    }
		}
		return v;
	}


	//--------------------------------------------Problema #5--------------------------------
	void avanzar(int t) {

		for (int i=0; i<t; i++) { 
			posicion.x = posicion.x+velocidad.x;
			posicion.y = posicion.y+velocidad.y;

			if (posicion.x>espacio.ancho) {
				posicion.x=0+velocidad.x;
			}
			if (posicion.y>espacio.largo) {
				posicion.y=0+velocidad.y;
			}
//Si las velocidades llegaran a ser negativas
			if (posicion.x<0) {
				posicion.x=espacio.ancho+velocidad.x;
			}
			if (posicion.y<0) {
				posicion.y=espacio.largo+velocidad.y;
			}
    	}
	}

private:
	mapa espacio;
	vector posicion;
	vector velocidad;

};
