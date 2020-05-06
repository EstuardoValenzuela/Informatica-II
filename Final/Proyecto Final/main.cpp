#include <stdio.h>  // printf
#include <stdlib.h> // malloc y free
#include <string.h> // strcasecmp
#include <conio.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

//Prototipos de funciones
void agregar(struct frecuenciaCompras indice);
void agregarLista(char id[100]);
void imprimir();
void guardar();
bool OrdenarPorIndice(const pair<int, int>& a, const pair<int, int>& b);
void OrdenarPorFrecuencia(int recibo[], int n);
void menu();

struct Nodo *superior = NULL;      //Como estara vacio entonces es Null

//Declaro Una estructura con datos ID y NumeroCompras
struct frecuenciaCompras{
	char id[200];
	int NumeroCompras;
};
//Declaro un nodo que me ayudara a crear mi pila
struct Nodo{                                //Declaro una Estructura la cual es un Nodo y contiene los valores de indice
	struct frecuenciaCompras indice;
	struct Nodo *sigue;                     //Apunta a un nodo siguiente por tratarse de una pila
};



//----------------------------------------------Funcion Main-----------------------------------------------------
int main(){
	cout<<"\tProyecto Final Informatica II"<<endl;
	cout<<"\tAutores: Estuardo Valenzuela y Jose Escalon"<<endl;
	cout<<"\tSupermercado \n\n " <<endl;
	menu();

	getch();


}
//----------Declaracion de las funciones--------------------
void agregar(struct frecuenciaCompras indice){                          //Esta funcion hace un push, es decir, agrega un struct
	  struct Nodo *agregaNodo = (Nodo*)malloc(sizeof(struct Nodo));
	  agregaNodo->indice = indice;
	  agregaNodo->sigue = superior;
	  superior = agregaNodo;
}
void buscarPorFrecuencia(char id[200]){                    //Esta funcion recorre toda la pila y compara cada caracter, si encuentra un caracter repetido la frecuencia aumenta
	struct Nodo *aux = superior;
	while (aux != NULL){
		int buscafrecuencia = strcasecmp(aux->indice.id, id);
		if(buscafrecuencia==0){
			aux->indice.NumeroCompras++; 					//Si se repite entonces se le sumara 1 al numero de compras
			return;
		}
		aux = aux->sigue;
	}
	struct frecuenciaCompras indice;
	strcpy(indice.id, id);
	indice.NumeroCompras = 1;                               //Si solo se repite 1 vez entonces el numero de compras es 1
	agregar(indice);
}

void imprimir(){
  char guiones[] = "---------------------";
  printf("%s%s\n", guiones, guiones);
  printf("|%-20s|%-20s|\n", "ID producto", "Veces Comprado");
  printf("%s%s\n", guiones, guiones);

	struct Nodo *aux = superior;

	while (aux != NULL){
		printf("|%-20s|%-20d|\n", aux -> indice.id, aux->indice.NumeroCompras);
		aux = aux -> sigue;                                                         //Con esto imprimo el que sigue
	}

	printf("%s%s\n", guiones, guiones);

}

void guardar(){
    ofstream archivo;                                      //Se ejecuta la funcion ofstream
	char fecha[15];

	cout<<"Fecha de Guardado: ";                            //Se le pide al usuario que digite la fecha
	cin.ignore();
	cin.getline(fecha,15, '\n');

	archivo.open("BaseDatos.txt",ios::app);                 //Se abre el archivo
	archivo<<"Fecha de guardado: "<<fecha<<"\n";            //se escribe la fecha de guardado del archivo

	struct Nodo *aux = superior;                                   //Creo una variable auxiliar y la iguala a superior

	char guion[] = "--------------------";                  //Apartado unicamente para la interfaz grafica

    archivo<<"+"<<guion<<"+"<<guion<<"+\n";
    archivo<<"   Producto          |     Frecuencia     \n";
    archivo<<"+"<<guion<<"+"<<guion<<"+\n";

	while(aux != NULL){                                     //Se declara un bucle para guardar los datos
		archivo<<aux->indice.id<<"                             "<<aux->indice.NumeroCompras<<"\n";  //accedo a los valores de mi estructura indice y el numero de compras
		aux = aux->sigue;
	}

	archivo<<"+"<<guion<<"+"<<guion<<"+\n";                 //Apartado para graficos
    archivo.close();                                        //Cierro mi archivo
	cout<<"Base de datos actualizada\n\n";
}


//------------------------------Esta funcion me ordena mi cadena de enteros dependiendo de la frecuencia-----------------------------------------
//Si tengo una lista de enteros: 4,5,5,6,6,6 me la ordena de la siguiente forma: 6 6 6 5 5 4
unordered_map<int, int> valor;                                              //unordered_map almacena elementos formados por la combinacion de un valor clave y un valor mapeado

bool OrdenarPorIndice(const pair<int, int>& a, const pair<int, int>& b){

    if (a.second == b.second)
        return valor[a.first] < valor[b.first];

    return a.second > b.second;
}

void OrdenarPorFrecuencia(int recibo[], int n){                   //Funcion que me ordena, recibe una lista de enteros, el int n solo sirve para los bucles for{
    unordered_map<int, int> mapaa;
    vector<pair<int, int> > vec;                                //El pair consta de 2 elementos, el primero elemento se hace referencia como primero(first) y el segundo(second)

    for (int i = 0; i < n; ++i) {
        mapaa[recibo[i]]++;

        if (valor[recibo[i]] == 0)						// Actualiza el valor del mapa solo una vez
            valor[recibo[i]] = i + 1;
    }


    copy(mapaa.begin(), mapaa.end(), back_inserter(vec));      //copio mapa al vector mediante la funcion copy

    sort(vec.begin(), vec.end(), OrdenarPorIndice);		//sort me  sirve para ordenar el vector en orden ascendente (por indice)
    int elj;											//declaro una variable int la cual convertire a char
    string je;
    for (int i = 0; i < vec.size(); ++i) {				//Declaro una sentencia for anidada el primer for es para recorrer el vector y el sgundo para ir guardando los datos en mi variable elj
        for (int j = 0; j < vec[i].second; ++j){
            elj = vec[i].first;
//----------------------Convierto el int a string ------------------
            stringstream ss;
            ss<<elj;
            string s;
            string space(" ");                              //Dejo un espacio por cada valor
            ss>>s;
            s.append(space);                               //Concateno los string
            je.append(s);

		}
	}
//-------------------------Convierto de string a char---------------
	char c[je.size()+1];
	strcpy(c, je.c_str());
    cout<<"La lista ordenda por frecuencia es: "<<c<<endl;
	//strrev(c);   //se invierte el orden de la cadena
	                char delimitador[] = ", ";                     //Esto me indica que al presentarse una coma o espacio se dividara la cadena
					char *token = strtok(c, delimitador);           //tokenizo mi char con la funcion strtok
						while (token != NULL){                      //Establesco un While para ingresar token por token a mi pila
						buscarPorFrecuencia(token);
						token = strtok(NULL, delimitador);
						}

						cout << "Lista agregada correctamente\n\n";

}

//------------------------Menu interactivo------------------------------------------
void menu(){
	int opcion;
	do{
		cout<<"\t Proyecto Supermercado\n";
		cout<<"(1) Insertar lista\n";
		cout<<"(2) Ver Tabla\n";
		cout<<"(3) Guardar Datos\n";
		cout<<"Ingrese una opcion: ";
		cin>>opcion;

		switch(opcion){
			case 1:{    int lista[] = { 30,10,20,90, 30,30,40,40,40, 55,55,75,75,100,55,55 };       //Se ingresan las listas
						int bucle = sizeof(lista) / sizeof(lista[0]);                    // sizeof (lista) devuelve el número de bytes que ocupa la matriz. Como cada elemento puede ocupar más de 1 byte de espacio,
                                                                                            //se divide el resultado con el tamaño de un elemento (sizeof (lista [0])). Esto le da un número de elementos en la matriz.
						OrdenarPorFrecuencia(lista, bucle);                                 //Llamo a mi funcion y envio mi lista y mi n

					}break;

			case 2:{ cout <<"Mostrando Datos \n";
					imprimir();                                               //Llamo a mi funcion imprimir
					}break;
			case 3:{guardar();                                                //Llamo a mi funcion guardar
					}break;
		}
	}while(opcion!=4);



}

