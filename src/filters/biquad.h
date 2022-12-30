#ifndef BIQUAD_H_
#define BIQUAD_H_

#include "filter.h"

// For implementation details, go to:
// https://webaudio.github.io/Audio-EQ-Cookbook/audio-eq-cookbook.html

class Biquad : public Filter {
    public:
        Biquad();

        void configure(double b0, double b1, double b2,
                       double a0, double a1, double a2);

        double run(double input) override;

    protected:
        void calc_intermediate_vars(double fs, double fc, double zeta);

        static constexpr double MIN_SAMPLING_FREQ = 1E-7;

        double omega;
        double cos_omega;
        double sin_omega;
        double alpha;

        double coeff[5];
        double prev_input[2];
        double prev_output[2];
};

#endif
