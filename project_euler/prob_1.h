/* date = January 25th 2022 11:57 am */

#ifndef PROB_1_H
#define PROB_1_H

int32_t
problem_1(int32_t limit)
{
    int32_t sum = 0;
    for (int32_t i = 0; i < limit ; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

#endif //PROB_1_H
