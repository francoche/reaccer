#ifndef BOTON_H
#define BOTON_H


class Boton
{
private:
    int x;
    int y;
public:
    Boton();
    void setx(int a);
    void sety(int a);
    void getx();
    void gety();
    void virtual abstracto()=0;
};

#endif // BOTON_H
