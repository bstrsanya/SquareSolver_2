#include <stdio.h>

#include "CleanBufer.h"
#include "ScanCoef.h"

void ScanCoef(double* a)
{
    int chek = scanf("%lg", a);

    while (CleanBufer() == 0 || chek != 1)
        {
        printf("Try again\n");
        chek = scanf("%lg", a);
        }
}
