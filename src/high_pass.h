#ifndef HIGH_PASS_H_
#define HIGH_PASS_H_

#include "biquad.h"

class HighPass : public Biquad {
    public:
        HighPass();

        void configure(double fs, double fc, double zeta,
                       double init_condition = 0);
};

#endif
