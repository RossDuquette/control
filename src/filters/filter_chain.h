#ifndef FILTER_CHAIN_H_
#define FILTER_CHAIN_H_

#include "filter.h"

template<int MAX_NUM_FILTERS>
class FilterChain : public Filter {
    public:
        FilterChain() :
            Filter(),
            filters(),
            num_filters()
        {
        }

        void add_filter(const Filter& filter)
        {
            if (num_filters < MAX_NUM_FILTERS) {
                filters[num_filters++] = &filter;
            }
        }

        double run(double input) override
        {
            output = input;
            for (int i = 0; i < num_filters; i++) {
                output = filters[i]->run(output);
            }
            return output;
        }

    private:
        Filter* filters[MAX_NUM_FILTERS];
        int num_filters;
};

#endif
