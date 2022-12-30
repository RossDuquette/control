#ifndef SATURATOR_H_
#define SATURATOR_H_

#include "filter.h"

class Saturator : public Filter {
    public:
        Saturator();

        void configure(double min, double max);

        double run(double input) override;

        // Returns a number from -1 to 1.
        // -1 -> saturating at minimum
        // 1  -> saturating at maximum
        // 0  -> directly in between min and max
        double get_percent_saturated() const;
        bool was_saturated() const;

    private:
        double min;
        double max;
        bool saturated;
};

#endif
