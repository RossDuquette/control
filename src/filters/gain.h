#ifndef GAIN_H_
#define GAIN_H_

#include "filter.h"

class Gain : public Filter {
    public:
        Gain();

        void configure(double gain);
        double run(double input) override;

    private:
        double gain;
};

#endif
