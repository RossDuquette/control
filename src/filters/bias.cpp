#include "bias.h"

Bias::Bias() :
    Filter(),
    bias()
{
}

void Bias::configure(double bias)
{
    this->bias = bias;
}

double Bias::run(double input)
{
    output = input + bias;
    return output;
}
