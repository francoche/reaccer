#include "estaciones.h"

Estaciones::Estaciones()
{
this->tipo=0;
}

void Estaciones::crearmatriz(int x, int y)
{
    this->matriz = new bool*[x];
    for (int i = 0; i< x; i++) {
        this->matriz[i] = new bool[y];
    }
    for (int i = 0; i< x; i++){
        for (int j = 0; j< y; j++){
            this->matriz[i][j]=false;
        }
    }




}

bool Estaciones::adyacente_estacion(int x, int y)
{
    if (this->matriz[x-1][y]==true) {
            return true;

        }


        if (this->matriz[x+1][y]==true) {
            return true;

        }


        if (this->matriz[x][y-1]==true) {
            return true;

        }


        if (this->matriz[x][y+1]==true) {
            return true;

        }

        return false;
}

void Estaciones::crearestaciones(int x,int y,QPushButton *** botones)
{


        int aux1,aux2,c3,c4;
        srand(time(NULL));
        this->tipo=1+rand()%4;
        std::cout<<this->tipo<<std::endl;
        /*switch (this->tipo) {
        case 1:{aux1=rand()%x;
                aux2=rand()%y;
                break;}
        case 2:{aux1=rand()%x;
                aux2=rand()%y;
                break;}
        case 3:{c3=y-2;
                aux1=rand()%x;
                aux2=1+rand()%c3;
                break;}
        case 4:{c4=x-2;
                aux1=1+rand()%c4;
                aux2=rand()%y;
                break;}
        }
        std::cout<<"aux1 "<<aux1<<"aux2 "<<aux2<<std::endl;*/




}



