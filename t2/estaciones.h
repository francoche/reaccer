#ifndef ESTACIONES_H
#define ESTACIONES_H
#include <QMainWindow>
#include<QPushButton>
#include<cstdlib>
#include<ctime>
#include "matriz.h"
#include <iostream>

class Estaciones : public Matriz
{
private:
    int **tipo;
    int filaultimo=0;
    int columnaultimo=0;
public:
    Estaciones();
    void copiarocupado(Matriz a);
    bool esadyacente(int fila,int columna,int filatotal,int coltotal);
    void crearestaciones(int fila,int columna,QPushButton *** botones);
    void setmatrizenteros(int filas,int columnas);
    void borrarmatrienteros(int filas,int columnas);
    bool superpuestas(int fila,int columna);
    void setcamino(QPushButton * clik,QPushButton *** punterobotones,int filas,int columnas);
};

#endif // ESTACIONES_H
