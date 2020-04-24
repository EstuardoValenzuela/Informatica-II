#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>

/*
Laboratorio #9
Informatica II
Fecha de entrega: 23 de Abril, 2020 @ 11:59pm
*/

class LinkedList {

    public:
	
	LinkedList(){
    }
	
    int getvalor() {
		return valor;
	}
	
	LinkedList* getList() {
		return fin;
	}
    
    int listalargo() {//cuenta la cantidad de elementos en una lista
        LinkedList* encadenada = (LinkedList*)malloc(sizeof(LinkedList));
        encadenada->x = x;
        encadenada->fin = fin;
	    int i= 1;
	    if (encadenada->x==0 && encadenada->fin==nullptr) {
		    return 0;
	    }
    	else {
		    while (encadenada->fin != nullptr) {
			    i++;
			encadenada = encadenada->fin;
		    }
		    return i;
	    }
    }
    /*
    Problema #1 (20%): Definir el metodo push que agrega un elemento al final de la lista encadenada.
    */
       void push(int valor){
		   
        LinkedList *reserva = new LinkedList;

        reserva->x=valor;
        reserva->fin=nullptr;
        
        LinkedList* encadenada=this;
        
        while(encadenada->fin != nullptr){
              encadenada = encadenada->fin;
        }
		
        
        encadenada->fin = reserva;
    }
    
    /*
    Problema #2 (20%): Definir el metodo "toVector" el cual debe retornar un vector
    con los mismos elementos que esta lista encadenada.
    */
    vector<int> toVector(){
		
        vector<int> vector;
        int valor = x;
		
        LinkedList* arr = fin;

		while (resto != nullptr) {
				vector.push_back(valor);
				valor = arr->x;
				arr = arr->fin;
		}
		
		vector.push_back(valor);

		return vector;
    }

    /*
    Problema #3 (20%): Definir el "operador []" para la lista encadenada. Este operador debe retornar
    una referencia al indice dado como parametro. Puede asumir que los indices siempre son
    validos.
    https://en.cppreference.com/w/cpp/language/operators#Array_subscript_operator
    */

    int& operator[](const int indice){
        LinkedList* encadenada=this;
        for(int i=0;i<indice;i++){
            encadenada = encadenada->fin;
        }
        return encadenada-x;
    }

    /*
    Problema #4: Definir el destructor para esta lista encadenada. Asegurese que
    todos los valores de la lista sean correctamente eliminados siguiendo
    los punteros que sean necesarios.
    https://en.cppreference.com/w/cpp/language/destructor
    */
    ~LinkedList(){
		x = 0;
		delete fin;

    /*
    Problema #5: Definir el "operador =" tal que copie todos los valores de la lista
    actual a la nueva lista. Asegurese que:
     * Se crea una nueva copia de cada uno de los elementos de la lista con este operador.
     * Se libera la memoria ocupada por los valores anteriores
    https://en.cppreference.com/w/cpp/language/copy_assignment
    */
    LinkedList& operator=(const LinkedList& otra)
        x=0;
        delete fin;
        fin = nullptr;
        int ex = aux.listalargo();
        x = aux.x;//El value, será el valor de la otra lista
        
        for(int i = 1; i<ex; i++){
            push(aux[i]);
        }
        return *this;
    }

   
	 private:
    int x;
    LinkedList* fin;


};