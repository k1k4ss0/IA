//
// Created by k1k4ss0 on 10/8/18.
//

#include "cochito.h"


cochito::cochito(int x, int y) {
    this->x=x;
    this->y=y;
}

cochito::~cochito() {
    x=0;
    y=0;
}
cochito::cochito() {
    x=0;y=0;
}
int cochito::get_x() {return x;}
int cochito::get_y() {return y;}
void cochito::set_x(int x) {this->x=x;}
void cochito::set_y(int y) {this->y=y;}