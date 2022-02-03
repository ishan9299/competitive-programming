#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "prob_1.h"
#include "prob_2.h"
#include "prob_3.h"
#include "prob_6.h"
#include "prob_7.h"
int
main()
{
#if COMPILE_SOLVED_PROBLEMS
    int32_t test_case_1 = problem_1(10);
    int32_t answer_1 = problem_1(1000);
    uint32_t answer_2 = problem_2();
    uint64_t test_case_3 = problem_3(13195);
    //uint64_t answer_3 = problem_3(600851475143);
    int32_t answer_6 = problem_6(100);
#endif
    uint64_t answer_7 = problem_7(10001);
    printf("%I64u\n", answer_7);
}