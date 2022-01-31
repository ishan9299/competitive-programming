/* date = January 26th 2022 5:51 pm */

#ifndef PROB_7_H
#define PROB_7_H

uint64_t
problem_7(uint32_t x) {
    struct primes_prob_3 p;
    generate_primes(&p, x);
    uint64_t num = p.num[10000];
    return num;
}

#endif //PROB_7_H
