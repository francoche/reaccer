#ifndef ESTACIONES_H
#define ESTACIONES_H
#include <QMainWindow>
#include <qpushbutton.h>
#include<string>
#include "matriz.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Estaciones : public Matriz
{
private:
    int cont=0;
    int tipo;
public:
    Estaciones();
    void crearmatriz(int x,int y);
    bool adyacente_estacion(int x,int y);
    void crearestaciones(int x,int y,QPushButton *** botones);


};

#endif // ESTACIONES_H
