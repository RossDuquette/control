#ifndef LOW_PASS_H_
#define LOW_PASS_H_

#include "biquad.h"

class LowPass : public Biquad {
    public:
        LowPass();

        void configure(double fs, double fc, double zeta,
                       double init_condition = 0);
};

#endif
