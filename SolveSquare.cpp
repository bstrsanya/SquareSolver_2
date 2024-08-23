#include <math.h>
#include <assert.h>
#include <stdio.h>

#include "SolveSquare.h"
#include "const.h"
#include "CompareDouble.h"

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (CompareDouble(a, 0) == 0)
        {
        double D = b * b - 4 * a * c;

        if (D > 0)
            {
            *x1 = (-b - sqrt(D)) / (2 * a);
            *x2 = (-b + sqrt(D)) / (2 * a);
            return two_solve;
            }

        if (CompareDouble(D, 0))
            {
            *x1 = *x2 = -b / (2 * a);
            return one_solve;
            }

        if (D < 0)
            {
            return no_solve;
            }
        }

    else if (CompareDouble(a, 0) && CompareDouble(b, 0) && CompareDouble(c, 0))
        {
        return more_solve;
        }

    else if (CompareDouble(a, 0) && CompareDouble(b, 0))
        {
        return no_solve;
        }

    else if (CompareDouble(a, 0))
        {
        *x1 = *x2 = -c / b;

        return one_solve;
        }

    return error;
}
