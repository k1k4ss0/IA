//
// Created by k1k4ss0 on 10/6/18.
//

#include "Mapa.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
void Mapa::define(void){

    for(int i=0;i<largo*alto;i++){                              // bucle en el que

        if(i<largo || i>=(largo*alto)-largo ){                  // se establecen los bordes superiores e inferiores
            mapa[i]="-";
        }
        else{                                                   // y la de los laterales

            if(i%largo==0 || (i+1)%largo==0){
                mapa[i]="|";
            }
            else{  mapa[i]=" ";}                                // lo demas sera espacio en blanco que estara disponible

        }

    }

}

bool* Mapa::sensible(cochito car) {
    bool* n=new bool[4];
    n[0]=false,n[1]=false,n[2]=false,n[3]=false;
    if(mapa[get_pos(car.get_x(),car.get_y()+1)]==" "){
        n[0]=true;
    }
    if(mapa[get_pos(car.get_x()-1,car.get_y())]==" "){
        n[1]=true;
    }
    if(mapa[get_pos(car.get_x(),car.get_y()-1)]==" "){
        n[2]=true;
    }
    if(mapa[get_pos(car.get_x()+1,car.get_y())]==" "){
        n[3]=true;
    }

    return n;

}

void Mapa::play() {





}


void Mapa::set_boiis() {

    cout<<"1. Para manual"<<endl<<"2. Para automatico"<<endl;           // preguntamos si el usuario quiere establecer los obstaculos en posiciones indicadas por el , o de forma aleatoria
    int dont_let_em_know=0;                                             // guardamos la respuesta del usuario
    cin>>dont_let_em_know;
    if(dont_let_em_know==1){                                // en el caso de que el usuario especifique que lo quiere de forma manual
        int s=0;
        cout<<"introduzca el numero de obstaculos a introducir:"<<endl;         // pedimos el numero de obstaculos a introducir
        cin>>s;


        for(int i=0;i<s;i++){                                           // bucle hasta que se llegue al numero de obstaculos especificados por el usuario
            int y=0,x=0;
            cout<<"introduzca la posicion en el eje X: ";                   //introducimos las coordenadas x e y
            cin>>x;
            cout<<endl<<"Introduzca la posicion en el eje Y: ";
            cin>>y;
            int pos=get_pos(x,y);                                   // llamamos a la funcion get_pos que nos da la posicion real dentro del array
            if(mapa[pos]==" "){                                     // en el caso de que el campo que se especifico este vacio
                mapa[pos]="o";                                      // se introduce una 'o' que es lo que representa a un obstaculo
            }
            else{                                                   // en caso de que no este libre, volvera a pedir otra coordenada
                cout<<"la posicion indicada ya esta ocupada, intente de nuevo"<<endl;
                i--;
            }

        }

    }
    else{                                                       // en caso de que el usuario pida que se generen de forma aleatoria
        srand(time(0));                                         // establecemos la semilla para crear los numeros aleatorios
        int o;
        for(int i=0;i<n_obstaculos;i++){                        // bucle

            o=rand()%(largo*alto);                              // guarda el numero aleatorio generado en un rango que este dentro del tamano del mapa
            if(mapa[o]=="-" || mapa [o]=="|" || mapa[o]=="o"){     // si esta ocupado vuelve a intentar
                i--;
            }
            else{                                               // en caso contrario se pone el obstaculo en dicha posicion
                mapa[o]="o";
            }

        }
    }

}

Mapa::Mapa(int i, int j,int o) {
n_obstaculos=o;                 // guardamos las variabes dentro del objeto
largo=i+2;                      // y aumentamos en 2 para los bordes
alto=j+2;
mapa=new string [largo*alto];      // definimos el vector del mapa
define();                       // llamamos a la funcion para poder establecer los bordes
set_boiis();                    // funcion que establece los obstaculos
}
Mapa::~Mapa() {
    alto=0;
    largo=0;
    mapa=NULL;
}

void Mapa::a_todo_gas() {

    cout<<"Cuantos coches quiere introducir ?: ";           // preguntamos cuantos coches se quieren poner en el mapa
    int s=0;
    cin>>s;
    rayo_mc_queen=new cochito[s]();                           // guardamos la respuesta y creamos tantos objetos coche como se hayan especificado
    int x=0,y=0;
    for(int i=0;i<s;i++){                                   // bucle hasta que se haya introducido todas las posiciones de los coches
        cout<<"Introduzca la posicion x del coche: ";
        cin>>x;
        cout<<endl<<"Introduzca la posicion y del coche: ";
        cin>>y;
        int pos=get_pos(x,y);                               // guarda las posiciones especificadas por el usuario
        if(mapa[pos]==" "){                                 // en el caso de que el espacio este libre
            mapa[pos]="M";                                  // posiciona en el mapa el coche
            rayo_mc_queen[i].set_y(y);                      // guarda dentro del objeto coche su posicion propia
            rayo_mc_queen[i].set_x(x);
        }
        else{                           // en caso de que el espacio este ya ocupado, pregunta por otras coordenadas
            cout<<"Error, la posicion esta ocupada, pruebe de nuevo"<<endl;
            i--;
        }
    }
    k1k4ss0();          // una vez se ha terminado muestra el mapa
}

int Mapa::get_pos(int x, int y) {

    return (largo*((alto-y)-1))+x;
}
void Mapa::k1k4ss0() {

    for(int i=0;i<largo*alto;i++){
        if(i%largo==0){
            cout<<endl;
        }
        cout<<mapa[i];

    }
}


int Mapa::get_largo() {return largo;}
int Mapa::get_alto() {return alto;}
string* Mapa::get_mapa() {return mapa;}

