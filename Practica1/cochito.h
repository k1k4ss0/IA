//
// Created by k1k4ss0 on 10/8/18.
//

#ifndef IA_COCHITO_H
#define IA_COCHITO_H


class cochito {
private:
    int x;
    int y;
public:
    cochito(int x,int y);
    cochito();
    ~cochito();
    int get_x(void);
    int get_y(void);
    void set_x(int x);
    void set_y(int y);
};


#endif //IA_COCHITO_H
