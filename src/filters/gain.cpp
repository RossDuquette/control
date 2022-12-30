#include "gain.h"

Gain::Gain() :
    Filter(),
    gain()
{
}

void Gain::configure(double gain)
{
    this->gain = gain;
}

double Gain::run(double input)
{
    output = input * gain;
    return output;
}
