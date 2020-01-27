
#include <iostream>
#include "mensaje.hh"
#include "Mensaje1.hh"
#include "Valor1.hh"
#include "Valor2.hh"
#include "Valor3.hh"


int main(){

    /*
    Se utiliza el prefijo std para aceder a los
    metodos incluidos en el lenguaje
    */
    std::printf(MENSAJE);
    std::printf("%s, %i", Mensaje1, Valor3);
    char c;
    std:: cin >> c;
    //Sleep(5000); //Tiempo para cerrar el programa
    /*
    Retornams el valor 0 para indicar que
    el programa se ejecuto sin errores.
    */
    return 42;
}