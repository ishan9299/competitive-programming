/* date = January 25th 2022 0:10 pm */

#ifndef PROB_2_H
#define PROB_2_H

uint32_t
problem_2()
{
    uint32_t last_fib = 1;
    uint32_t current_fib = 2;
    uint32_t even_fib_sum = 2;
    while(current_fib < 4000000) {
        uint32_t new_fib = current_fib + last_fib;
        last_fib = current_fib;
        current_fib = new_fib;
        if (current_fib % 2 == 0) {
            even_fib_sum += current_fib;
        }
    }
    return even_fib_sum;
}

#endif //PROB_2_H
