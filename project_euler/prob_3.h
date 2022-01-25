/* date = January 25th 2022 0:44 pm */

#ifndef PROB_3_H
#define PROB_3_H

struct primes_prob_3 {
    uint64_t *num;
    uint64_t size;
    uint64_t last_index_sq;
};

uint64_t
problem_3(uint64_t number)
{
    struct primes_prob_3 numbers;
    uint64_t array[10000];
    array[0] = 2;
    array[1] = 3;
    array[2] = 5;
    array[3] = 7;
    numbers.num = array;
    numbers.size = 4;
    numbers.last_index_sq = 0;
    for (uint64_t i = 8; i < 10000; i++) {
        if(i % array[0] == 0) {
            continue;
        }
        if(i % array[1] == 0) {
            continue;
        }
        if(i % array[2] == 0) {
            continue;
        }
        if(i % array[3] == 0) {
            continue;
        }
        uint64_t flag = 0;
        for (uint64_t j = numbers.last_index_sq; j < numbers.size; j++) {
            if (array[j] * array[j] == i) {
                numbers.last_index_sq = j;
                flag = 1;
                break;
            }
        }
        if(!flag) {
            array[numbers.size] = i;
            numbers.size++;
        }
    }
    
    uint64_t largest_prime = 0;
    for (uint64_t i = 0; i < numbers.size; i++) {
        if (number % array[i] == 0) {
            number = number / array[i];
            if (number == 1) {
                largest_prime = array[i];
                break;
            }
        }
    }
    return largest_prime;
}

#endif //PROB_3_H
