#include <algorithm>
#include <cmath>

#include "pid.h"

Pid::Pid() :
    kp(),
    ki(),
    kd(),
    dt(),
    prev_error(),
    integral(),
    der(),
    p_out(),
    i_out(),
    d_out()
{
}

void Pid::configure(double fs,
                    double kp, double ki, double kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    if (fs <= 0) {
        fs = 1;
    }
    dt = 1.0 / fs;
    prev_error = 0;
    integral = 0;
    der = 0;
    p_out = 0;
    i_out = 0;
    d_out = 0;
}

double Pid::run(double target, double measured)
{
    double error = target - measured;
    p_out = kp * error;

    integral += ((error + prev_error) / 2.0) * dt;
    i_out = ki * integral;

    der = (error - prev_error) / dt;
    d_out = kd * der;

    prev_error = error;
    return p_out + i_out + d_out;
}

double Pid::get_int() const
{
    return integral;
}

double Pid::get_der() const
{
    return der;
}

double Pid::get_p_out() const
{
    return p_out;
}

double Pid::get_i_out() const
{
    return i_out;
}

double Pid::get_d_out() const
{
    return d_out;
}
