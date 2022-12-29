#ifndef FILTER_H_
#define FILTER_H_

class Filter {
    public:
        Filter();

        virtual double run(double input) = 0;

        double get_prev_output() const;

    private:
        double output;
};

#endif
