#include <iostream>
#include <math.h>

using namespace std;

struct Lista
{
	int valor;
	Lista *resto;
};

//---------------------------------Problema #1-------------------------------------------------

Lista *crear(const int *valores, const int cantidad) {//Crea una Lista a partir de un array de ints
	Lista *ls = (Lista*)malloc(sizeof(Lista)*cantidad);
	if (cantidad == 0) {
		return nullptr;
	}
	else {
		for(int i=0; i<cantidad; i++) {                 //Utilizo un for y mi contador i
			ls[i].valor=valores[i];
			if (i<=cantidad-2) {
				ls[i].resto=&ls[i+1];
			}2
			else {
				ls[cantidad-1].resto = nullptr;       //Empleo una condicion donde el resultado sera nullptr
			}
		}
	}
	return ls;                                     //Retorno mi ls
}


//--------------------------------------Problema #2------------------------------------------

void eliminar(Lista* valores) {                         //Void que elimina lista
	 while (valores!=nullptr) {
		 delete &valores->valor; 						//Esto eliminara el puntero con la funcion delete
		 valores=valores->resto;        
	}
	
	delete valores;
	
}


//--------------------------------------Problema #3------------------------------------------------

void unir(Lista* primera, Lista* segunda) {                 //Une listas 

	Lista* x;                         
	
	if (primera == nullptr) {                    // Si la primera es igual a nulo entonces sera igual a la segunda 
		primera = segunda;						 //Entonces si la primera es nullptr entonces la lista unida sera igual a al segunda 
	}
	
	else {
		if (segunda != nullptr) {                //Y si la lista segunda no es igual a nullptr entonces aplica esta condicion 
			x = primera;
			while (x->resto != nullptr) {
				
				x = x->resto;
			}
			
			x->resto = segunda;
		}
	}
}

//-------------------------------------Problema #4--------------------------------------------------------------
int longitud(const Lista* valores) {
	
	int c = 1;
	
	 if (valores->resto==nullptr) {
		    return 0;
	}
	else {
		 while (valores->resto!=nullptr) {
		    	c++;
			    valores=valores->resto;
		}
		 return c;
	}
}
//-----------------------------------Problema #5------------------------------------------------

bool lookup(const Lista* valores, const int indice, int& resultado) {
	
	 int c = largo(valores);
	 int i = indice;


	 if (i >= c) {
		
		 return false;
	 }
	
	 else {
		
	    	while (0 < i) {
		        	i--;
		        	valores = valores->resto;
		}
		resultado = valores->valor;
		
		return true;
	}
}

//------------------------------------------Problema #6-------------------------------------
struct Triangulo { 
	int x[2];         //Se declaran los vertices 
	int x1[2];
	int x2[2];
};
struct ListaTriangulos {
	Triangulo posicion1;
	ListaTriangulos* resto;
};
//------------------------------------------------Problema #7------------------------------------
float segmento(Triangulo triangulo) {  
			float a=pow((triangulo.x[0]-triangulo.x1[0]), 2);
			float b=pow((triangulo.x[1]-triangulo.x1[1]), 2);
			float resultado=sqrt(a+b);

		 return resultado;
}
float segmento1(Triangulo triangulo) {
			float a=pow((triangulo.x[0]-triangulo.x2[0]), 2);
			float b=pow((triangulo.x[1]-triangulo.x2[1]), 2);
			float resultado=sqrt(a+b);

		 return resultado;
}
float segmento2(Triangulo triangulo) {
			float a=pow((triangulo.x1[0]-triangulo.x2[0]), 2);
			float b=pow((triangulo.x1[1]-triangulo.x2[1]), 2);
			float resultado=sqrt(x2+y2);

		 return resultado;
}
float area(const Triangulo& triangulo) {

	float a=(segmento(triangulo)+segmento1(triangulo)+segmento2(triangulo)) / 2;

	float area1=sqrt(a*(a-segmento(triangulo))*(a-segmento1(triangulo))*(a-segmento2(triangulo)));

	return area1;
}

//--------------------------------------------------Problema #8------------------------------------------------------------

int contadorT(const ListaTriangulos* valores) {
	 int contar=1;
	
	 if (valores->resto==nullptr) {
		 return 0;
	 }
	 else {

		 while (valores->resto!=nullptr) {
		    	contar++;
		    	valores=valores->resto;
		 }

		 return contar;
		 
	 }
}

float areaPromedio(const ListaTriangulos* triangulos) {
	int numero=contadorT(triangulos);
	float cat=0;

	for (int i=0; i<numero; i++) {
		cat=cat+area(triangulos->primero);
		triangulos=triangulos->resto;
	}

	float promediar=cat/numero;
	return promediar;
}

int main()
{
	
	Lista lista;
	lista.valor = 1;
	lista.resto = (Lista*)malloc(sizeof(Lista));

	lista.resto->valor = 2;
	lista.resto->resto = nullptr;

	Lista* lista2 = &lista;

}