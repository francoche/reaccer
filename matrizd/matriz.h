#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
protected:
    bool **matriz;
public:
    Matriz();
    void virtual crearmatriz(int x,int y)=0;
    void virtual borrarmatriz(int x,int y)=0;

};

#endif // MATRIZ_H
