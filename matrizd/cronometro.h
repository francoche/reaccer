#ifndef CRONOMETRO_H
#define CRONOMETRO_H
#include<QTimer>

class Cronometro
{
private:
    int seg;
public:
    Cronometro();
    void aumentar();
    void reset ();
    int get_seg();

};

#endif // CRONOMETRO_H
