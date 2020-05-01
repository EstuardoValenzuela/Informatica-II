/*
Universidad del Istmo
Facultad de Ingenieria
Informatica II
Prof. Ernesto Rodriguez <erodriguez@unis.edu>
Laboratorio #10
*/

/*
Instrucciones: En esta taria usted tendra que utilizar herencia para definir clases
que modelan el comportamiento de 3 aviones: Concorde, A320 y EMB-120. Todos los
modelos de avion deben heredar de una clase general llamada avion.
*/

/*
Tarea #1 (50%): Defina la clase avion que debe tener lo siguietne:
* Un metodo llamado "acelerar" el cual acepta un numero y aumeta
  o reduce la velocidad por dicho numero si es possible. Retorna
  true si la velocidad fue cambiada y false de lo contrario.
* Una variable protegida llamada "eficiencia", esta variable cambia
  cuando el avion cambia su altura segun los detalles especificos
  de cada modelo.
* Un metodo llamado "ascender" que debe aceptar una altitud en pies
  y retornar true si el ascenco es possible o false de lo contrario.
* Un metodo llamado "getConsumoActual" el cual debe retornar el consumo
  de gasolina del avion. Este consumo es la "eficiencia" multiplicado
  por la velocidad del avion.
*/

#include <iostream>
#include <vector>

using namespace std;

struct maximos{
	int altitudMaxima;
	int altitudMinima;
	float x;
};


class avion{
	public:
	avion(){
		velocidad = 0;
		altitud = 0;
	}
	
	
	//Como se nos pide que nuestro metodo retorne true o false, sera de tipo bool
	bool acelerar (int x){
	int vel = velocidad + x;
	if(vel <=  velocidadMaxima){
		velocidad = vel;
		return true;
	}
	else {
		return false;
	}
}


	bool ascender (int y){
	if(altitud < alturaMaxima){
		altitud = y;
		for(int i=0; i<modelo.size(); i++){
			if(altitud <=modelo[i].altitudMaxima && altitud>=modelo[i].altitudMinima){
                cm = modelo[i].x;
                break;
                }
            }
		return true;
	}
	else{
		return false;
	}
	
}


	float getConsumoActual(){
        float consumo = cm*velocidad;
        return consumo;
}
	
	protected:
	vector<maximos> modelo;
	int velocidadMaxima;
	int alturaMaxima;
	float cm;
	
	private:
	
	int velocidad;
	int altitud;
};


/*
Tarea #2 (50%): Defina clases especificas para cada uno de los 3 modelos
de avion. A continuacion se muestra una tabla con los detalles
tecnicos de los aviones:
Concorde
    Altura maxima: 60,000 pies
    Velocidad maxima: 2350 km/h
    Eficiencia:
        50,000 - 60,000: 1.0
        40,000 - 49,999: 1.5
        30,000 - 39,999: 2
        0      - 29,999: 4
A320
    Altura maxima: 40,000 pies
    Velocidad maxima: 950 km/h
    Eficiencia:
        30,000 - 40,000: 1.0
        20,000 - 29,999: 1.3
        0      - 19,999: 2
EMB-130:
    Altura maxima: 30,000 pies
    Velocidad maxima: 500 km/h
    Eficiencia:
        15,000 - 30,000: 1.0
        5,000  - 14,999: 1.2
        0      -  4,999: 1.7
*/
class Concorde : public avion{
	public:
	Concorde():avion(){
		velocidadMaxima = 2350;
		alturaMaxima = 60000;
		cm = 4;
		
		maximos x0;
		x0.altitudMinima  = 0;    
		x0.altitudMaxima=29999; 
		x0.x=4;
		
        maximos x1; 
		x1.altitudMinima=30000; 
		x1.altitudMaxima=39999; 
		x1.x=2;
		
        maximos x2; 
		x2.altitudMinima=40000; 
		x2.altitudMaxima=49999; 
		x2.x=1.5;
		
        maximos x3; 
		x3.altitudMinima=50000; 
		x3.altitudMaxima=60000; 
		x3.x=1.0;
        
        modelo.push_back(x0);
        modelo.push_back(x1);
        modelo.push_back(x2);
        modelo.push_back(x3);
	}
};

class A320 : public avion{
	public:
	A320():avion(){
		velocidadMaxima = 950;
		alturaMaxima = 40000;
		cm = 2;
		
		maximos x0;
		x0.altitudMinima  = 0;    
		x0.altitudMaxima=19999; 
		x0.x=2;
		
        maximos x1; 
		x1.altitudMinima=20000; 
		x1.altitudMaxima=29999; 
		x1.x=1.3;
		
        maximos x2; 
		x2.altitudMinima=30000; 
		x2.altitudMaxima=39999; 
		x2.x=1.0;
        
        modelo.push_back(x0);
        modelo.push_back(x1);
        modelo.push_back(x2);

	}
};

class EMB120 : public avion{
	public:
	EMB120():avion(){
		velocidadMaxima =500;
		alturaMaxima = 30000;
		cm = 1.7;
		
		maximos x0; 
		x0.altitudMinima  = 0;    
		x0.altitudMaxima=4999; 
		x0.x=1.7;
        
		maximos x1; 
		x1.altitudMinima=5000; 
		x1.altitudMaxima=14999; 
		x1.x=1.2;
		
        maximos x2; 
		x2.altitudMinima=15000; 
		x2.altitudMaxima=30000; 
		x2.x=1.0;
        
        modelo.push_back(x0);
        modelo.push_back(x1);
        modelo.push_back(x2);

	}
};
