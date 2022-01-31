/* date = January 25th 2022 0:44 pm */

#ifndef PROB_3_H
#define PROB_3_H

struct primes_prob_3 {
    uint64_t *num;
    uint64_t size;
    uint64_t last_index_sq;
};

void
generate_primes(struct primes_prob_3 *numbers, uint32_t x)
{
    uint64_t *array = (uint64_t *)malloc(sizeof(uint64_t) * x);
    array[0] = 2;
    array[1] = 3;
    array[2] = 5;
    array[3] = 7;
    numbers->num = array;
    numbers->size = 4;
    numbers->last_index_sq = 0;
    uint64_t i = 8;
    while(numbers->size < x) {
        if(i % array[0] == 0) {
            i++;
            continue;
        }
        if(i % array[1] == 0) {
            i++;
            continue;
        }
        if(i % array[2] == 0) {
            i++;
            continue;
        }
        if(i % array[3] == 0) {
            i++;
            continue;
        }
        uint64_t flag = 0;
        for (uint64_t j = numbers->last_index_sq; j < numbers->size; j++) {
            if ((array[j] * array[j] == i) || (array[j] * array[j] > i)) {
                flag = 1;
                numbers->last_index_sq = j;
                break;
            }
        }
        if(!flag) {
            array[numbers->size] = i;
            numbers->size++;
            i++;
        }
    }
}


uint64_t
problem_3(uint64_t number)
{
    struct primes_prob_3 numbers;
    generate_primes(&numbers, 10000);
    uint64_t largest_prime = 0;
    for (uint64_t i = 0; i < numbers.size; i++) {
        if (number % numbers.num[i] == 0) {
            number = number / numbers.num[i];
            if (number == 1) {
                largest_prime = numbers.num[i];
                break;
            }
        }
    }
    free(numbers.num);
    return largest_prime;
}

#endif //PROB_3_H
