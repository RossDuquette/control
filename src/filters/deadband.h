#ifndef DEADBAND_H_
#define DEADBAND_H_

#include "filter.h"

class Deadband : public Filter {
    public:
        Deadband();

        void configure(double dead_val, double start, double stop, bool step);

        double run(double input) override;

    private:
        double dead_val;
        double start;
        double stop;
        bool step;
};

#endif
