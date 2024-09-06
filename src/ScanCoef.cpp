#include <stdio.h>

#include "./../include/CleanBufer.h"
#include "./../include/ScanCoef.h"

void ScanCoef (double* coef)
{
    int nReadParam = scanf ("%lg", coef);

    while (CleanBufer () == 0 || nReadParam != 1)
        {
        printf ("Try again\n");
        nReadParam = scanf ("%lg", coef);
        }
}
