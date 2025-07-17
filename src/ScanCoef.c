#include <stdio.h>

#include "CleanBuffer.h"
#include "ScanCoef.h"

void ScanCoef (double* coef)
{
    int nReadParam = scanf ("%lg", coef);

    while (CleanBuffer () == 0 || nReadParam != 1)
    {
        printf ("Try again\n");
        nReadParam = scanf ("%lg", coef);
    }
}
