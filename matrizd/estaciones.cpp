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

void Estaciones::borrarmatriz(int x, int y)
{
    for (int i = 0; i< x; i++) {
        delete []this->matriz[i];
    }
    delete [] this->matriz;
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


        int aux1=0,aux2=0,aux3=0,aux4=0,c3,c4;
        srand(time(NULL));
        this->tipo=1+rand()%4;
        std::cout<<this->tipo<<std::endl;

        if(this->tipo==1){
            aux1=rand()%x;
           aux2=rand()%y;
        }
        if(this->tipo==2){
            aux1=rand()%x;
           aux2=rand()%y;
        }
        if(this->tipo==3){
           aux1=rand()%x;
           while (aux2==0||aux2==(y-1)||aux2==(y)) {
               aux2=1+rand()%y;
           }

        }
        if(this->tipo==4){

            while (aux1==0||aux1==x-1||aux1==x) {
                aux1=1+rand()%x;
            }
           aux2=rand()%y;
        }
        this->tipo=1+rand()%4;
        if(this->tipo==1){
            aux3=rand()%x;
           aux4=rand()%y;
        }
        if(this->tipo==2){
            aux3=rand()%x;
           aux4=rand()%y;
        }
        if(this->tipo==3){
           aux3=rand()%x;
           while (aux4==0||aux4==(y-1)||aux4==(y)) {
               aux4=1+rand()%y;
           }

        }
        if(this->tipo==4){

            while (aux3==0||aux3==x-1||aux3==x) {
                aux3=1+rand()%x;
            }
           aux4=rand()%y;
        }
        botones[aux1][aux2]->setText("estacion");
        botones[aux3][aux4]->setText("estacion");
        botones[aux1][aux2]->setEnabled(false);

        std::cout<<"aux1 "<<aux1<<"aux2 "<<aux2<<std::endl;




}



