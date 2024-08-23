#include <stdio.h>

#include "CompareDouble.h"
#include "ScanCoef.h"
#include "AllProverka.h"
#include "const.h"
#include "TestSolve.h"

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
        int kol;
        kol = TestSolve (1,  1,   2,  -3,   two_solve,  -3, 1)  +
              TestSolve (2,  0,   0,  0,    more_solve, 0,  0)  +
              TestSolve (3,  0,   5,  -10,  one_solve,  2,  2)  +
              TestSolve (4,  4,   0,  -16,  two_solve,  -2, 2)  +
              TestSolve (5,  3,   27, 0,    two_solve,  -9, 0)  +
              TestSolve (6,  0,   0,  3,    no_solve,   0,  0)  +
              TestSolve (7,  1,   0,  0,    one_solve,  0,  0)  +
              TestSolve (8,  0,   7,  0,    one_solve,  0,  0)  +
              TestSolve (9,  1.5, 3,  -4.5, two_solve,  -3, 1)  +
              TestSolve (10, 1,   2,  1,    one_solve,  -1, -1);
        if (kol == 10)
            printf("#Check is good!\n");
        }
    else
        printf("#You refused to check\n");

}
