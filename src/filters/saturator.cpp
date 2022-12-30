#include "saturator.h"

Saturator::Saturator() :
    Filter(),
    min(),
    max(),
    saturated(false)
{
}

void Saturator::configure(double min, double max)
{
    if (min > max) {
        this->min = max;
        this->max = min;
    } else {
        this->min = min;
        this->max = max;
    }
}

double Saturator::run(double input)
{
    if (input < min) {
        saturated = true;
        output = min;
    } else if (input > max) {
        saturated = true;
        output = max;
    } else {
        saturated = false;
        output = input;
    }
    return output;
}

double Saturator::get_percent_saturated() const
{
    if (max == min) {
        // Prevent divide by zero
        return 0;
    } else {
        return ((output - min) / (max - min)) * 2 - 1;
    }
}

bool Saturator::was_saturated() const
{
    return saturated;
}
