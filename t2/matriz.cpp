#include "matriz.h"

Matriz::Matriz()
{

}

void Matriz::setmatrizbool(int filas, int columnas)
{
    this->matriz=new bool *[filas];
    for (int i = 0; i< filas; i++) {
       this->matriz[i]=new bool[columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->matriz[i][j]=false;
    }
    }
}

void Matriz::borrarmatrizbool(int filas, int columnas)
{
    for (int i = 0; i< filas; i++) {
       delete [] this->matriz[i];
    }
    delete [] this->matriz;
}

void Matriz::setmatrizocupado(int filas, int columnas)
{
    this->ocupado=new bool *[filas];
    for (int i = 0; i< filas; i++) {
       this->ocupado[i]=new bool[columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->ocupado[i][j]=false;
    }
    }

}

void Matriz::borrarmatrizocupado(int filas, int columnas)
{
    for (int i = 0; i< filas; i++) {
       delete [] this->ocupado[i];
    }
    delete [] this->ocupado;
}

bool **Matriz::getocupado()
{
    return this->ocupado;
}
