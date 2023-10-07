#include "estaciones.h"

Estaciones::Estaciones()
{

}

void Estaciones::copiarocupado(Matriz a)
{
    this->ocupado=a.getocupado();
}

bool Estaciones::esadyacente(int fila, int columna,int filatotal,int coltotal)
{
    if ((fila-1)>=0 && this->ocupado[fila - 1][columna]) {
            return true;
        }


        if ((fila+1)<=(filatotal-1) && this->ocupado[fila + 1][columna]) {
            return true;
        }


        if ((columna-1)>=0 && this->ocupado[fila][columna - 1]) {
            return true;
        }


        if ((columna+1)<=(coltotal-1) && this->ocupado[fila][columna + 1]) {
            return true;
        }

        return false;
}

void Estaciones::crearestaciones(int fila, int columna,QPushButton *** botones)
{
    srand(time(NULL));
    int f1,c1,f2,c2,t,t2;
    t=1+rand()%4;
    std::cout<<"tipo "<<t<<std::endl;
    switch (t) {
    case 1:
    case 2:{f1=rand()%fila;
            c1=rand()%columna;
            break;}
    case 3:{f1=rand()%fila;
            c1=1+rand()%(columna-1);
            break;}
    case 4:{f1=1+rand()%(fila-1);
            c1=rand()%columna;
            break;}

    }
    this->ocupado[f1][c1]=true;
    this->matriz[f1][c1]=true;
    botones[f1][c1]->setText("estacion "+QString::number(t));
    botones[f1][c1]->setEnabled(false);
    this->matriz[f1][c1]=true;
    this->tipo[f1][c1]=t;
    //////////////////////////////////////////////////////////////////////////
    t2=1+rand()%4;
    std::cout<<"tipo "<<t2<<std::endl;
    switch (t2) {
    case 1:
    case 2:{f2=rand()%fila;
            c2=rand()%columna;
            break;}
    case 3:{f2=rand()%fila;
            c2=1+rand()%(columna-1);
            break;}
    case 4:{f2=1+rand()%(fila-1);
            c2=rand()%columna;
            break;}

    }
    while (this->ocupado[f2][c2]==true || esadyacente(f2,c2,fila,columna)) {

        switch (t2) {
        case 1:
        case 2:{f2=rand()%fila;
                c2=rand()%columna;
                break;}
        case 3:{f2=rand()%fila;
                c2=1+rand()%(columna-1);
                break;}
        case 4:{f2=1+rand()%(fila-1);
                c2=rand()%columna;
                break;}

        }
    }
    this->ocupado[f2][c2]=true;
    this->matriz[f2][c2]=true;
    botones[f2][c2]->setText("estacion "+QString::number(t2));
    botones[f2][c2]->setEnabled(false);
    this->matriz[f2][c2]=true;
    this->tipo[f2][c2]=t;






}

void Estaciones::setmatrizenteros(int filas, int columnas)
{
    this->tipo=new int *[filas];
    for (int i = 0; i< filas; i++) {
       this->tipo[i]=new int[columnas];
    }

}

void Estaciones::borrarmatrienteros(int filas, int columnas)
{

    for (int i = 0; i< filas; i++) {
       delete [] this->tipo[i];
    }
    delete [] this->tipo;
}

/*void Estaciones::setmatrizbool(int filas, int columnas)
{
    this->matriz=new bool *[filas];
    for (int i = 0; i< filas; i++) {
       this->matriz[i]=new bool[columnas];
    }
}

void Estaciones::borrarmatrizbool(int filas, int columnas)
{
    for (int i = 0; i< filas; i++) {
       delete [] this->matriz[i];
    }
    delete [] this->matriz;
}*/


