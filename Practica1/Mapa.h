//
// Created by k1k4ss0 on 10/6/18.
//

#ifndef IA_MAPA_H
#define IA_MAPA_H

#include <cstring>
#include <string>
#include "cochito.h"
using namespace std;
class Mapa {
private:
    int alto;
    int largo;
    int n_obstaculos;
    string* mapa;
    cochito* rayo_mc_queen;

public:

    Mapa(int i,int j,int o);
    ~Mapa();
    int get_largo(void);
    int get_alto(void);
    string* get_mapa(void);
    void define (void);
    void k1k4ss0(void);
    void set_boiis(void);
    void a_todo_gas();
    int get_pos(int x,int y);
    bool* sensible(cochito car);
    void play(void);
    }
};


#endif //IA_MAPA_H
