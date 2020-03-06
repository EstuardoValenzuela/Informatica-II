#include <iostream>
#include<math.h>
using namespace std;



function int* copiar(int* valores, int cantidad){
		int* arreglo = (int*)malloc(cantidad*sizeof(int));
		for(int i = 0; i < cantidad; i++){
        arreglo[i] = nuevo_arreglo[i];
    }
    
    return arreglo;
	
}



function int*primos(const int maximo){


    int* num = (int*)malloc(maximo *sizeof(int));
    int count = 0;
    int coun2 = 0;
    for(int i = 0; i < maximo; i++){
        int denom =1;
        int denom2 = 0;
        do {
            if(i % denom == 0){
                denom2++;
            } denom++;
        }
           while (denom <= i);
    }
           
           if(denom2 == 2){
               num[denom2] = i;
               coun2++;
               count++;
           }
           
           int*arreglofinal = (int*)malloc(sizeof(int)* count);
           arreglofinal = num;
           return arreglofinal;
            
        
    
    
    
}


int**vectoresCercanos(int**vectores, const int cantidad, const int distancia){
				int* vectoresX = (int*)malloc(sizeof(int) * cantidad);
				int* vectoresY = (int*)malloc(sizeof(int) * cantidad);
				int* deuclidiana = (int*)malloc(sizeof(int) * cantidad);
    
	
    for(int i = 0; i < cantidad; i++){
        for(int x = 0: x < 2; x++){
            if(x%2== 0){
                vectoresX[i] = pow(vectores[i][x], 2);
            } 
			else {
                vectoresY[i] = pow(vectores[i][x], 2);
            }
        }
    }
    for(int i = 0; i < cantidad; i++){
        deuclidania[i] = sqrt(vectoresX[i] + vectoresY[i]);
    }
    
    
    return 0;
    
}



int main()
{
int nuevo_arreglo[] = {2,4,6,8}
copiar(nuevo_arreglo,4);

primos(13);

int count = 0;
int cantidad = 2;

int** vectoresfinal = (int**)malloc(sizeof(int) * cantidad);
for(int i = 0; i < cantidad; i++){
    vectoresfinal[i] = (int*)malloc(sizeof(int)*2);
}

vectoresfinal[0][0] = 2;
vectoresfinal[0][1] = 3;

vectoresCercanos(vectoresfinal, cantidad, 5);


    return 0;
}