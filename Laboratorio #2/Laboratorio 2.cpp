
#include <iostream>
#include "conio.h"
#include <stdio.h>													//Llamo a las librerias


//----------------------------------------------------Ejercicio #1---------------------------------------------------
bool esPrimoRec(int valor, int x = 2) {								//Ingreso mis variables y le asigno un valor a X, comenzara en 2
	if (valor <= 2)		
		return (valor == 2) ? true : false; 
	if (valor % x == 0)  
		return false;
	if (x * x > valor) 
		return true;
	return esPrimoRec(valor, x + 1);								 //Aqui es donde entra la recursion 
}
	int main() {													 //declaro mi Main
		int valor = 8;												 //Aqui asigno los parametros
		if (esPrimoRec(valor))										 //llamo a mi funcion esprimoRec
			printf("True");
		else
			printf("False");
		
	} 

//-----------------------------------------------------Ejercicio #2-----------------------------------------------------
	bool esPrimoCiclica(int num, int ctr = 2) {						//Comienzo diciendo que habran 2 variables Num y ctr = 2
		while (ctr < num) {											//Establesco la condicion que ctr sera menor a num
			if (num == 1) {
				return false;
			}
			else if (num == 2) {									//asigno mis "casos bases"
				return true;
			}
			else if (num % ctr == 0) {								//Defino las condiciones matematicas de un numero primo
				return false;
			}
			else if (ctr == num - 1) { 
				return true;
			}
			else {
				ctr++;
			}
		}
	}
//-------------------------------------------------------Ejercicio #3----------------------------------------------------
	int obtenerPrimoRec(int x, int con1 = 0, int con2 = 1) {				//Comiendo diciendo que tendre 3 variables, la primera x que sera el numero a analizar 
																			//con con1 contaré el numero de numeros primos hasta mi x, 
		if (con1 != x){														//por ultimo con2 se encargará de comprobar si es primo o no  
						
																			//Mi condicion if es valida cuando con1 no sea igual a x
			if (esPrimoRec (con2)) {	
																			//Me auxilio de la funcion que declare en el ejercicio 1
				return obtenerPrimoRec(x, (con1 + 1), (con2 + 1));			
			}
			else{
				return obtenerPrimoRec(x, con1, (con2 + 1));
			}
		}
		else{
			return con2 - 1;													//Le ire restando 1 a con2

		}
	}
//---------------------------------------------------------Ejercicio #4---------------------------------------
	int obtenerPrimoCiclico(int x, int con1 = -1, int con2 = 1) {              //Como utilizare ciclos comienzo declarando mis variables, y mis con1 y con2
		
		
		while (con1 <= x){													   //While me ayuda con los ciclos y con mi con1 me auxilio para crear el ciclo
		
			if (con1 < x){
				if (esPrimoRec(con2)){
					con1++&& con2++;						
				}
				else{
					con2++;
				}
			}
			else{
				return con2 - 1;
			}
		}
	}
