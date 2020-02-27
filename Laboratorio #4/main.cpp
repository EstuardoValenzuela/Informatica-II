#include <stdio.h>
#include <iostream>
#include <conio.h>


//-----------------------------------------------Ejercicio #1--------------------------------------------------------
bool divisionSegura(int numerador, int denominador, int* respuesta) {             //Ingreso mis variables de tipo int
													
	if (denominador!=0) {														  //Utilizo un If para que toda division que no tenga como denominador 0 se pueda llevar acabo
		int igual_a=(numerador / denominador);								  
		*respuesta=igual_a;													  //guardo mi variable igual_a en mi puntero respuesta
																				  //Solo se aplica si el denominador no es igual a 0
		return true;
	}
	else {

		return false;
	}
}

//---------------------------------------------------Ejercicio #2-------------------------------------------------------------------
int* num(int valores[], int cantidad) {									         //Esto me ayudara a encontrar la posicion del primer arreglo (el mayor)

	int* num1=&valores[0];													 //ingreso mi variable num1

	 for (int i=0; i<cantidad; i++) {										 //hago el uso de un fold para mi variable i 
		 if (valores[i]>*num1) {
		   	num1=&valores[i];
		}
	}
	return num1;                                                                  //Retorno como resultado mi puntero num1
}

int* num2(int valores[], int cantidad) {										  //Mi funcion num2 me ayudara a encontrar la posicion de mi segundo arreglo

	int* numero=&valores[0];

		for (int i=0; i<cantidad; i++) { 										 //Vuelvo a emplear el uso de un for para una variable int i
			if ((valores[i]>*numero)&&(&valores[i]!=num(valores, cantidad))) {  
				numero = &valores[i];
		}
	}

	return numero;
}

bool sumaMayor(int valores[], int cantidad, int** respuesta) {						//Comienzo ingresando mis variables
	
	if (cantidad>1) {																//Empleo un if que sera valido unicamente si cantidad > 1
		 
		respuesta[0]=num(valores, cantidad);									    //En el indice 0 se guardara la primera posicion del arreglo 
		respuesta[1]=num2(valores, cantidad);										//Ahora la segunda posicion del arreglo se guardará en el indice 1
		
		
		return true;
		
	}
	
	else {
		
		return false;
	}
}


//---------------------------------------------------------------Ejercicio #3------------------------------------------------------------------------------
int funcionN(int n) {																//Esta es una funcion auxiliar para encontrar el n numero de fibonacci

	if (n==0) {
		
		return 0;
	}
		
	else if (n==1) {
																						//Establezco mis casos bases cuando n = 1 y cuando n = 0
		return 1;
	}
	
	else {
		
		return ((funcionN(n-1))+(funcionN(n-2))); 								
	}
}

void fibonacciN(const int n, int* valores) {

	for (int i=0; i<n; i++) {
		valores[i] = funcionN(i);
	}

}


//-------------------------------------------------------------------Ejercicio #4------------------------------------------------------------------------
int fibonnacciNopt(int x) {																//creo mi funcion fibonnaci para optimizar aplicando una funcion auxiliar

	int x1=0;																			//Declaro mis variables
	int x2=1;
	int x3;


	for (int i=0; i<x; i++) {														//Aplico un for para mi variable i
	
		x3=x1+x2;
		x1=x2;
		x2=x3;
		
	}
	
	return x1;																			
}

void fibonacciNopt(const int x, int* numeros) { 										


	for (int i=0; i<x; i++) {
		
		numeros[i] = fibonnacciNopt(i);
		
	}

}

