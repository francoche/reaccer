#include "cronometro.h"

Cronometro::Cronometro()
{
    this->seg=0;
}

void Cronometro::aumentar()
{
    this->seg++;
}

void Cronometro::reset()
{
    this->seg=0;
}

int Cronometro::get_seg()
{
   return this->seg;
}
