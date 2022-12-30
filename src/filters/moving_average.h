#ifndef MOVING_AVERAGE_H_
#define MOVING_AVERAGE_H_

#include "filter.h"

template<int FILTER_LEN>
class MovingAverage : public Filter {
    public:
        MovingAverage() :
            Filter(),
            filled(false),
            oldest(0),
            vals()
        {
        }

        void restart()
        {
            filled = false;
            oldest = 0;
            output = 0;
        }

        double run(double input) override
        {
            if (filled) {
                output -= vals[oldest] / double(FILTER_LEN);
                output += input / double(FILTER_LEN);
            } else {
                output -= output / double(oldest + 1);
                output += input / double(oldest + 1);
            }
            vals[oldest++] = input;
            if (oldest == FILTER_LEN) {
                oldest = 0;
                filled = true;
            }
        }

    private:
        bool filled;
        int oldest;
        double vals[FILTER_LEN];
};

#endif
