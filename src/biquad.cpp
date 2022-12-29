#include <cmath>

#include "biquad.h"

Biquad::Biquad() :
    Filter(),
    omega(),
    cos_omega(),
    sin_omega(),
    alpha(),
    coeff(),
    prev_input(),
    prev_output()
{
}

double Biquad::run(double input)
{
    if (!std::isfinite(input)) {
        return 0;
    }
    output = coeff[0] * input
           + coeff[1] * prev_input[0]
           + coeff[2] * prev_input[1]
           - coeff[3] * prev_output[0]
           - coeff[4] * prev_output[1];
    prev_output[1] = prev_output[0];
    prev_output[0] = output;
    prev_input[1] = prev_input[0];
    prev_input[0] = input;
    return output;
}

void Biquad::configure(double b0, double b1, double b2,
                       double a0, double a1, double a2)
{
    if (a0 != 0) {
        coeff[0] = b0 / a0;
        coeff[1] = b1 / a0;
        coeff[2] = b2 / a0;
        coeff[3] = a1 / a0;
        coeff[4] = a2 / a0;
    }
}

void Biquad::calc_intermediate_vars(double fs, double fc, double zeta)
{
    if (fs < MIN_SAMPLING_FREQ) {
        fs = MIN_SAMPLING_FREQ;
    }
    if (fc < 0) {
        fc = 0;
    } else if (fc > (fs / 2.0)) {
        fc = fs / 2.0;
    }
    if (zeta < 0) {
        zeta = 0;
    } else if (zeta > 2) {
        zeta = 2;
    }
    omega = 2 * M_PI * fc / fs;
    cos_omega = cos(omega);
    sin_omega = sin(omega);
    alpha = sin_omega * zeta;
}
