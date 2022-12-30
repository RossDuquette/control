#ifndef PID_H_
#define PID_H_

class Pid {
    public:
        Pid();

        void configure(double fs,
                       double kp, double ki, double kd);

        double run(double target, double measured);

        double get_int() const;
        double get_der() const;
        double get_p_out() const;
        double get_i_out() const;
        double get_d_out() const;

    private:
        double kp;
        double ki;
        double kd;
        double dt;
        double prev_error;
        double integral;
        double der;
        double p_out;
        double i_out;
        double d_out;
};

#endif
