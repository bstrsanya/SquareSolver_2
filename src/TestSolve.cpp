#include <stdio.h>

#include "./../include/SolveSquare.h"
#include "./../include/CompareDouble.h"
#include "./../include/const.h"
#include "./../include/TestSolve.h"




int TestSolve(Test* data)
{
    double x1 = 0, x2 = 0;
    int result = SolveSquare(data->a, data->b, data->c, &x1, &x2);

    if (result != data->nRoots || (CompareDouble(x1, data->x1ref) == 0) || (CompareDouble(x2, data->x2ref) == 0))
        {
        printf("Error_Test_%d; a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, result = %d\n"
               "Expected: x1 = %lg, x2 = %lg, result = %d\n",
               data->num_test, data->a, data->b, data->c, x1, x2, result, data->x1ref, data->x2ref, data->nRoots);
        return error;
        }
    return 1;
}
