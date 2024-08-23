#include <stdio.h>

#include "SolveSquare.h"
#include "CompareDouble.h"
#include "const.h"
#include "TestSolve.h"

int TestSolve(int n_test, double a, double b, double c, int result_right,
              double x1_right, double x2_right)
{
    double x1 = 0, x2 = 0;
    int result = SolveSquare(a, b, c, &x1, &x2);

    if (result != result_right || (CompareDouble(x1, x1_right) == 0) || (CompareDouble(x2, x2_right) == 0))
        {
        printf("Error_Test_%d; a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, result = %d\n"
               "Expected: x1 = %lg, x2 = %lg, result = %d\n",
               n_test, a, b, c, x1, x2, result, x1_right, x2_right, result_right);
        return error;
        }
    return 1;
}
