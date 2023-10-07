#ifndef CRONOMETRO_H
#define CRONOMETRO_H


class Cronometro
{
private:
    int seg=0;
public:
    Cronometro();
    void setaumentar();
    void setreset();
    int get_tiempo();
};

#endif // CRONOMETRO_H
