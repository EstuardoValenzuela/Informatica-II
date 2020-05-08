  
#include <iostream>
#include <vector>

using namespace std;

//Laboratorio 11
//Jeremy Cáceres y Adalí Garrán

//Ejercicio #1
class Coleccion {
    public:
    
    Coleccion(){};
    
    virtual int numEl() = 0;
    
    virtual void agregar(int num) = 0;
    
    virtual int& operator[](const int i) = 0;
    
};


//Ejercicio #2
class ColeccionVector : public Coleccion {
    
    public:
    ColeccionVector() : Coleccion(){};
    
    virtual int numEl() override{
        return v.size();        
    }
    
    virtual void agregar(int num) override{
        v.push_back(num);
    } 
    
    virtual int& operator[](const int i) override{
            return v[i];
    }
    
    private:
    vector<int> v;
};



//Ejercicio #3
class ColeccionLinkedList : public Coleccion {
    
    public:
    ColeccionLinkedList() : Coleccion (){
        value = 0;
        rest = nullptr;
    }
    
    virtual int numEl() override{
        ColeccionLinkedList* lista = (ColeccionLinkedList*)malloc(sizeof(ColeccionLinkedList));
        lista->value = value;
        lista->rest = rest;
	    int contador = 1;
	    if (lista->value == 0 && lista->rest == nullptr) {
		    return 0;
	    }
    	else {
		    while (lista->rest != nullptr) {
			    contador++;
			    lista = lista->rest;
		    }
		    return contador;
	    }
    }
    
    virtual void agregar(int valor) override{
        if(value == 0){
            value = valor;
        }
        else{
        ColeccionLinkedList *newRest = new ColeccionLinkedList;//Se reserva espacio para añadir el valor como una nueva linkedlist
        newRest->value = valor;//El value de la nueva lista será el valor deseado
        newRest->rest = nullptr;//El resto será nullptr, porque será el final de la lista
        
        ColeccionLinkedList* lista = this;
        
        while(lista->rest != nullptr){//Se repite el ciclo hasta que se llegue al final de la lista actual
            lista = lista->rest;
        }
        
        lista->rest = newRest;//Se agrega el valor al final de la lista
        
        }
    }
    
    
    virtual int& operator[](const int indice) override{
        
        ColeccionLinkedList* lista = this;//Se define una lista temporal con los valores de la actual
        
        for(int i = 0; i<indice; i++){//Se recorre la lista hasta llegar al índice deseado
            lista = lista->rest;
        }
        
        return lista->value;//Se retorna el value que se encuentra en el índice
    }
    
    
    private:
    int value;
    ColeccionLinkedList* rest;
    
    
};


//Ejercicio #4
//Método burbuja
void ordenar(Coleccion& valores){
    
    int aux;
    
    for (int i=0; i<valores.numEl() - 1; i++){
        for (int j = i + 1; j<valores.numEl(); j++){
            if(valores[i]>valores[j]){
                aux = valores[i];
                valores[i] = valores[j];
                valores[j] = aux;
            }
        }
    }
    
};




int main()
{
    
    //Pruebas
    
    //Ejercicio #2
    ColeccionVector v;
    cout<<"El vector tiene "<<v.numEl()<<" elementos"<<endl;
    v.agregar(2);
    v.agregar(3);
    v.agregar(1);
    cout<<"El valor en el índice 1 es: "<<v[1]<<endl;
    v[1]=4;
    cout<<"El valor en el índice 1, luego de modificarse es: "<<v[1]<<endl;
    cout<<"El vector ahora tiene "<<v.numEl()<<" elementos"<<endl;
    cout<<endl;
    
    
    //Ejercicio #3
    ColeccionLinkedList l;
    cout<<"La lista tiene "<<l.numEl()<<" elementos"<<endl;
    l.agregar(6);
    l.agregar(7);
    l.agregar(5);
    cout<<"El valor de la lista en el índice 1 es: "<<l[1]<<endl;
    l[1]=8;
    cout<<"El valor en el índice 1, luego de modificarse es: "<<l[1]<<endl;
    cout<<"La lista ahora tiene "<<l.numEl()<<" elementos"<<endl;
    cout<<endl;
    
    

    //Ejercicio #4
    cout<<"Antes de ordenarse, el primer valor del vector es "<<v[0]<<endl;
    ordenar(v);  
    cout<<"Luego de ordenarse, el primer valor del vector es "<<v[0]<<endl;
    cout<<endl;
    
    cout<<"Antes de ordenarse, el primer valor de la lista es "<<l[0]<<endl;
    ordenar(l);
    cout<<"Luego de ordenarse, el primer valor de la lista es "<<l[0]<<endl;

    return 0;
}
//----------------------------------------
/*
Ejercicio #1 (25%)
A continuacion se le presenta la clase coleccion. La intencion
de esta clase es representar objetos que pueden almacenar varios
valores numeriocs sin adherirse a un metodo particular para
reservar la memoria.
Su tarea es definir los siguientes metodos virutales puros para
la coleccion:
* Un metodo para obtener el numero de elementos en la coleccion.
* Un metodo que permita agregar un numero al *final* de la coleccion,
  como consecuencia, el tamaño de la coleccion aumenta una unidad.
* Uno (o mas) metodos para aceder y modificar los elementos de la
  coleccion por medio de su *indice* en ella.
*/
class Coleccion {
    public: 
    Coleccion(){};
    virtual int numerosV() = 0;
    virtual void meter(int numero) = 0;
    virtual int& operator[](const int i) = 0;   
};


/*
Ejercicio #2 (25%)
Implemente los metodos puros virtuales de la clase coleccion en
la clase hija llamada "ColeccionVector". Esta clase debe utilizar
un std::vector<int> para almacenar los numeros. Todas las operaciones
de la coleccion deben ser implementadas alrededor de este vector. En
otras palabras, esta clase debe tener una variable privada de tipo
std::vector<int> para almacenar los numeros.
*/
class ColeccionVector : public Coleccion {
    public:
    ColeccionVector() : Coleccion(){};
    virtual int numerosV() override{
        return listaNum.size();        
    }
    virtual void meter(int numero) override{
        listaNum.push_back(numero);
    } 
    virtual int& operator[](const int i) override{
            return listaNum[i];
    }
     private:
    vector<int> listaNum;
};

/*
Ejercicio #3 (25%)
Implemente los metodos puros virtuales de la clase coleccion en
la clase hija llamada "ColeccionLinkedList". Esta clase debe utilizar
listas encadenadas (como las creadas en el laboratorio #9) para almacenar
sus elementos. Todas las operaciones de la clase "Coleccion" deben ser
implementadas alrededor de una instancia de "LinkedList".
*/
class ColeccionLinkedList : public Coleccion {
    public:
    ColeccionLinkedList() : Coleccion (){
        valor = 0;
        rest = nullptr;
    }
	
    virtual int numerosV() override{
        ColeccionLinkedList* lista = (ColeccionLinkedList*)malloc(sizeof(ColeccionLinkedList));
        lista->valor = valor;
        lista->rest = rest;
	    int contador = 1;
	    if (lista->valor == 0 && lista->rest == nullptr) {
		    return 0;
	    }
    	else {
		    while (lista->rest != nullptr) {
			    contador++;
			    lista = lista->rest;
		    }
		    return contador;
	    }
    }
    
    virtual void meter(int value) override{
        if(valor == 0){
            valor = value;
        }
        else{
        ColeccionLinkedList *newRest = new ColeccionLinkedList;
        newRest->valor = value;
        newRest->rest = nullptr;
        
        ColeccionLinkedList* lista = this;
        
        while(lista->rest != nullptr){
            lista = lista->rest;
        }
        
        lista->rest = newRest;
        
        }
    }
    
    
    virtual int& operator[](const int lugar) override{
        
        ColeccionLinkedList* lista = this;
        
        for(int i = 0; i<lugar; i++){
            lista = lista->rest;
        }
        
        return lista->valor;
    }      
    private:
    int valor;
    ColeccionLinkedList* rest; 
};

/*
Ejercicio #4 (25%)
Implemente la funcion "ordenar" definida abajo. Esta funcion
debe aceptar una coleccin y modificarla de tal forma que sus
elementos esten ordenados.
*/
void ordenar(Coleccion& valores){
  
    int aux;
    
    for (int i=0; i<valores.numerosV() - 1; i++){
        for (int j = i + 1; j<valores.numerosV(); j++){		//Se ordenara por el metodo burbuja
            if(valores[i]>valores[j]){
                aux = valores[i];							//Se realiza el cambio de variable
                valores[i] = valores[j];
                valores[j] = aux;
            }
        }
    }
    
};




