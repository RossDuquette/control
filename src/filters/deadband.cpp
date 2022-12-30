#include "deadband.h"

Deadband::Deadband() :
    Filter(),
    dead_val(),
    start(),
    stop(),
    step()
{
}

void Deadband::configure(double dead_val, double start, double stop, bool step)
{
    if (stop < start) {
        double temp = start;
        start = stop;
        stop = temp;
    }
    if (dead_val < start) {
        dead_val = start;
    } else if (dead_val > stop) {
        dead_val = stop;
    }
    this->dead_val = dead_val;
    this->start = start;
    this->stop = stop;
    this->step = step;
}

double Deadband::process(double input)
{
    if ((input < start) || (input > stop)) {
        if (step) {
            return input;
        } else if (input < start) {
            return input - start + dead_val;
        } else {
            return input - stop + dead_val;
        }
    }
    return dead_val;
}
