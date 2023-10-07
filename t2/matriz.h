#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
protected:
    bool **matriz;
    bool **ocupado;
    int filas;
    int columnas;
public:
    Matriz();
    void  setmatrizbool(int filas,int columnas);
    void  borrarmatrizbool(int filas,int columnas);
    void  setmatrizocupado(int filas,int columnas);
    void  borrarmatrizocupado(int filas,int columnas);
    bool **getocupado();
};

#endif // MATRIZ_H
