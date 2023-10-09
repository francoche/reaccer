#ifndef CAMINO_H
#define CAMINO_H

#include "matriz.h"
#include <QMainWindow>
#include<QPushButton>
#include<cstdlib>
#include<ctime>
#include "matriz.h"
#include <iostream>

class Camino : public Matriz
{
private:
    int filaultimo;
    int columaultimo;
public:
    Camino();
    void copiarocupado(Matriz a);
    void setcamino(QPushButton *** botones);

};

#endif // CAMINO_H
