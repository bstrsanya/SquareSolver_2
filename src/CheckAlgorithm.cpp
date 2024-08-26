#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "./../include/CompareDouble.h"
#include "./../include/ScanCoef.h"
#include "./../include/CheckAlgorithm.h"
#include "./../include/const.h"
#include "./../include/TestSolve.h"

void CheckAlgorithm ()
{
    printf ("#To check the algorithm - enter 1, otherwise 0\n");

    double check_algorithm = -1;
    ScanCoef (&check_algorithm);

    while (CompareDouble (check_algorithm, 1) == 0 && CompareDouble (check_algorithm, 0) == 0)
        {
        printf("Try again\n");
        ScanCoef(&check_algorithm);
        }

    if (CompareDouble (check_algorithm, 1))
        {
        //const int n_test = 14;
        //                    #   a    b   c
        //--------------------------------------------------------------------
        Test data[] = {{1,  1,   2,  -3,   two_solve,  -3,  1},   // a = 1,   b = 2,   c = -3,   two_solve 
                             {2,  1.5, 3,  -4.5, two_solve,  -3,  1},   // a = 1.6, b = 3.2, c = -4.8, two_solve
                             {3,  -5,  6,  11,   two_solve,  2.2, -1}, // a = -5,  b = 6,   c = 11,   two_solve
                             {4,  1,   2,  1,    one_solve,  -1,  -1},  // a = 1,   b = 2,   c = 1,    one_solve
                             {5,  4,   8,  9,    no_solve,   0,   0},   // a = 4,   b = 8,   c = 9,    no_solve

                             {6,  0,   0,  0,    more_solve, 0,  0},  // a = 0, b = 0,  c = 0,   more_solve 
                             {7,  0,   5,  -10,  one_solve,  2,  2},  // a = 0, b = 5,  c = -10, one_solve 
                             {8,  4,   0,  -16,  two_solve,  -2, 2},  // a = 4, b = 0,  c = -16, two_solve
                             {9,  3,   27, 0,    two_solve,  -9, 0},  // a = 3, b = 27, c = 0,   two_solve
                             {10, 0,   0,  3,    no_solve,   0,  0},  // a = 0, b = 0,  c = 3,   no_solve
                             {11, 1,   0,  0,    one_solve,  0,  0},  // a = 1, b = 0,  c = 0,   one_solve
                             {12, 0,   7,  0,    one_solve,  0,  0}}; // a = 0, b = 7,  c = 0,   one_solve
        int n_test = sizeof(data) / sizeof(data[0]);
        int counter = 0;                     
        for (int i = 0; i < n_test; i++)
            {
            assert (0 <= i && i < n_test);
            
            if (TestSolve (&data[i]) == 1)
                counter++;
            }
        
        if (counter == n_test)
            printf ("#Check is good!\n");
        }
    else
        printf ("#You refused to check\n");

}
