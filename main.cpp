#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>

#include "SolveSquare.h"
#include "const.h"
#include "CompareDouble.h"
#include "AllProverka.h"
#include "CleanBufer.h"
#include "ScanCoef.h"
#include "TestSolve.h"
#include "OutResult.h"

int main()
{
    printf ("#Solving quadratic equations\n");
    AllProverka();
    printf ("#Enter the coefficients\n");

    double a = 0, b = 0, c = 0;

    printf ("#coefficients a\n");
    ScanCoef (&a);
    printf ("#coefficients b\n");
    ScanCoef (&b);
    printf ("#coefficients c\n");
    ScanCoef (&c);

    double x1 = 0, x2 = 0;
    int result = SolveSquare (a, b, c, &x1, &x2);

    OutResult(result, x1, x2);
}













