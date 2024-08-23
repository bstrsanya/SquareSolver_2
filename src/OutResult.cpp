#include <stdio.h>

#include "./../include/OutResult.h"
#include "./../include/const.h"

void OutResult(int result, double x1, double x2)
{
    switch (result)
        {
        case no_solve:
            printf("No roots\n");
            break;

        case one_solve:
            printf("One root: x = %lf\n", x1);
            break;

        case two_solve:
            printf("Two roots: x1 = %lf; x2 = %lf\n", x1, x2);
            break;

        case more_solve:
            printf("Infinitely many roots\n");
            break;

        default:
            printf("Error((((((\n");
            break;
        }
}
