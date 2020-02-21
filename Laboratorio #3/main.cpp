#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;



//-------------------------------------------------Ejercicio #1----------------------------------------
void imprimirBinario(int i,int fijo=0) {
	
	
          if (fijo<32) {  															//Establezco mi condicion Inicial donde fijo no puede sobrepasar el numero 32 ya que este
		       if (i%2==0) {														//Es el numero maximo que pueden tener los numeros en bits
				    		imprimirBinario((i/2),(fijo+1));					
					    	printf("0");                           								
						    }
		            else {
		                 imprimirBinario(((i-1)/2),(fijo+1));        				//En caso contrario le restare 1 a i y lo dividere entre 2
			           	 printf("1");
			             }
				 	     }
	      else {
	        	printf(" ");
		       }

}

//--------------------------------------------------------Ejercicio #2-----------------------------------------------------
bool existe(char valor, long numero) {


 int fijo=0;                                                              //Ingreso una variable tipo Int cuyo valor sera 0
       
	   
 while (fijo<64) {                                                       //Aplico un While para usar ciclos y optimizar el codigo
		          if ((valor&numero)==valor) {
			      return true;                                          //Si cumple con la condicion entonces es verdadero
		         }
		             else {
			         numero>>=1;
			         fijo++;                                            //Aplico una suma 
		                  }
	             }
	                return false; 			                         	//En tal caso que no lo cumpla entonces es falso (no estan en orden)
}


//-----------------------------------------------------------------------Ejercicio #3----------------------------------------------------
short conteo(long numero,int fijo=0) {
	
	
	                          while (fijo<64) {													   //Utilizo while para los ciclos, 
		                                if (numero%2==0) {                 					   //Si el numero da como dato 0 no se sumara
									    return conteo((numero/2),(fijo+1)); 
											  }
									else {
										return 1+(conteo(((numero-1)/2),(fijo+1)));       //Si cumple con las condiciones entonces se sumara
										}
											  }
}

//---------------------------------------------------------------------Ejercicio #4---------------------------------------------------------
int andOr(int valor1,int valor2) {                                                                 //Ingreso mis variables de tipo Int
					int bit = valor1&0xAAAAAAAA;													//Asi obtengo los bits pares
					int bit1 = valor2&0xAAAAAAAA;
					int bit2 = valor1&0x55555555;
					int bit3 = valor2&0x55555555;													//Asi los impares
					int bit4 = (bit&bit1);														//Opero los bits pares
					int bit5 = (bit2|bit3); 																	   
					   return (bit4|bit5); 														//Retorno bit4 o bit5
}

//-------------------------------------------------------------------Ejercicio #5--------------------------------------------------------------
int codificar(char c1,char c2,char c3,char c4) {
                                                                                                 //cada variable tomara cierto rango de bits el rango es de 8 bits

			int dato=0;
				dato=dato|c4;
				dato=dato<<8;
				dato=dato|c3;
				dato=dato<<8;
				dato=dato|c2;
				dato=dato<<8;
				dato=dato|c1;
					    return dato;
}