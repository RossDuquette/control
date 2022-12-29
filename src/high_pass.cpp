#include "high_pass.h"

HighPass::HighPass() :
    Biquad()
{
}

void HighPass::configure(double fs, double fc, double zeta,
                         double init_condition)
{
    calc_intermediate_vars(fs, fc, zeta);
    Biquad::configure((1 + cos_omega) / 2.0,
                      -(1 + cos_omega),
                      (1 + cos_omega) / 2.0,
                      1 + alpha,
                      -2 * cos_omega,
                      1 - alpha);
    for (int i = 0; i < 2; i++) {
        prev_output[i] = 0;
        prev_input[i] = init_condition;
    }
}
