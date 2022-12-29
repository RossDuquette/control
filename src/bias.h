#ifndef BIAS_H_
#define BIAS_H_

#include "filter.h"

class Bias : public Filter {
    public:
        Bias();

        void configure(double bias);
        double run(double input) override;

    private:
        double bias;
};

#endif
