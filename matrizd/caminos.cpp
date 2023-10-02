#include "caminos.h"

Caminos::Caminos()
{

}

void Caminos::crearmatriz(int x, int y)
{
    this->matriz = new bool*[x];
    for (int i = 0; i< x; i++) {
        this->matriz[i] = new bool[y];
    }
    for (int i = 0; i< x; i++){
        for (int i = 0; i< y; i++){
            this->matriz[x][y]=false;
        }
    }
}
