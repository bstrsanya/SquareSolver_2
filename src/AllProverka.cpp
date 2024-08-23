#include <stdio.h>
#include <math.h>

#include "./../include/CompareDouble.h"
#include "./../include/ScanCoef.h"
#include "./../include/AllProverka.h"
#include "./../include/const.h"
#include "./../include/TestSolve.h"



void AllProverka()
{
    printf ("#To check the algorithm - enter 1, otherwise 0\n");

    double check_algorithm = -1;
    ScanCoef(&check_algorithm);

    while (CompareDouble(check_algorithm, 1) == 0 && CompareDouble(check_algorithm, 0) == 0)
        {
        printf("Try again\n");
        ScanCoef(&check_algorithm);
        }

    if (CompareDouble(check_algorithm, 1))
        {
        const int n_test = 10;
        int counter = 0;
        Test data[n_test] = {{1,  1,   2,  -3,   two_solve,  -3, 1},
                         {2,  0,   0,  0,    more_solve, 0,  0},
                         {3,  0,   5,  -10,  one_solve,  2,  2},
                         {4,  4,   0,  -16,  two_solve,  -2, 2},
                         {5,  3,   27, 0,    two_solve,  -9, 0},
                         {6,  0,   0,  3,    no_solve,   0,  0},
                         {7,  1,   0,  0,    one_solve,  0,  0},
                         {8,  0,   7,  0,    one_solve,  0,  0},
                         {9,  1.5, 3,  -4.5, two_solve,  -3, 1},
                         {10, 1,   2,  1,    one_solve,  -1, -1}};
        for (int i = 0; i < n_test; i++)
            {
            TestSolve(data[i]);
            counter++;
            }
        if (counter == n_test)
            printf("#Check is good!\n");
        }
    else
        printf("#You refused to check\n");

}
