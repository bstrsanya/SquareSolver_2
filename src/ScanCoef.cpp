#include <stdio.h>

#include "./../include/CleanBufer.h"
#include "./../include/ScanCoef.h"

void ScanCoef (double* a)
{
    int nReadParam = scanf ("%lg", a);

    while (CleanBufer () == 0 || nReadParam != 1)
        {
        printf ("Try again\n");
        nReadParam = scanf ("%lg", a);
        }
}
