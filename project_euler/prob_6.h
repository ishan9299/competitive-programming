#ifndef PROB_6_H
#define PROB_6_H

int32_t sum_of_n_nums(int32_t n)
{
    int32_t ans = ((n) * (n+1)/2);
    return ans;
}

int32_t sum_of_sqn_nums(int32_t n)
{
    int32_t ans = (((n) * (n + 1) * ((2 * n) + 1))/6);
    return ans;
}

int32_t
problem_6(int32_t n)
{
    return ((sum_of_n_nums(n) * sum_of_n_nums(n)) - sum_of_sqn_nums(n));
}

#endif // PROB_6_H