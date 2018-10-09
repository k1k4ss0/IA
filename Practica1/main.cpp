#include <iostream>
#include <cstdio>
#include "Mapa.h"
#include <vector>
#include <zconf.h>

using namespace std;



int main() {
    int largo=0,alto=0;                                     // variables de size del mapa
    cout <<"Introduzca el largo del mapa"<<endl;
    cin >> largo;

    cout << "Introduzca el alto del mapa"<<endl;
    cin >>alto;
    int o=(largo*alto)*0.1;             // se establece por defecto el numero de obstaculos dentro del mapa( igual al 10% del espacio total)
    Mapa map(largo,alto,o);             // creamos el objeto del mapa
    cout<< "Mostrando mapa:";
    map.k1k4ss0();                      // printeamos el mapa con los elementos dentro de el
    cout<<endl<<endl;
    map.a_todo_gas();                   // funcion que introduce los coches


}

