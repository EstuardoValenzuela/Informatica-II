#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


//----------------------------------------Tarea #1----------------------------------------------- 
float parseFloat(const string& numreal) {              	    //Enviare parametros por referencia y retornare un float
	float resultado = strtof(numreal.c_str(), nullptr);		//La funcion strfot me ayuda a convertir un string a un float
	return resultado;										//Retorno resultado
}


//---------------------------------------Tarea #2------------------------------------------------
vector<string> coma(string str, char nuevo = ',') {          //Debo definir una funcion auxiliar para separar el string

	int inicio = 0;
	int iterador = 0;										//Esta variable la utilizare para el bucle While
	string divisor;
	vector<string> total;
	
	while (iterador >= 0) {
		iterador = str.find(nuevo, inicio);
		divisor = str.substr(inicio, iterador - inicio);
		inicio = iterador+1;
		total.push_back(divisor);
	}
	return total;
}

class Vector3d {

public:

	Vector3d(string coordenadas) {
		vector<string> punto=coma(coordenadas);
		corx = parseFloat(punto[0]);
		cory = parseFloat(punto[1]);
		corz = parseFloat(punto[2]);
	}

//----------------------------------------Tarea #3--------------------------------------------------------
	float distancia(Vector3d aux) {
		float distanciax = pow((corx - aux.corx), 2);
		float distanciay = pow((cory - aux.cory), 2);
		float distanciaz = pow((corz - aux.corz), 2);

		return sqrt(distanciax + distanciay + distanciaz);
	}
//---------------------------Este apartado me ayudara a realizar las pruebas------------------------------
	float getX() {
		return corx;
	}
	float getY() {
		return cory;
	}
	float getZ() {
		return corz;
	}
//-----------------------------------------------------------------------------------------------------
private:

	float corx;
	float cory;
	float corz;
}; 

int main(){
//-----------------------------------------------Tarea #4-----------------------------------------------
	vector<Vector3d> vectorn;
	string xnum;
	float total = 0;
	int iterador = 0;

	cout << "Introduzca los vectores: \n";

	while (xnum != "\n") {
		getline(cin, xnum);         
		if (!xnum.empty()) {
			vectorn.push_back(Vector3d(xnum));
			iterador++;
		}
		else {
			break;
		}
	}
	if (vectorn.empty()) {
		total = 0;
	}
	else {
		for (int i=0; i<iterador-1; i++) {
			total +=vectorn[i].distancia(vectorn[i+1]);
		}
	}
	
	cout << "La distancia es: " <<total;

	char corx;
	std::cin >> corx;

	return 0;
}
