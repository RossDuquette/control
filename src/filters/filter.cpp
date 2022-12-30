#include "filter.h"

Filter::Filter() :
    output()
{
}

double Filter::get_prev_output() const
{
    return output;
}
