#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>

//-----------------------------------------------------------------------------

const int no_solve   = 0;
const int one_solve  = 1;
const int two_solve  = 2;
const int more_solve = 3;
const double smal    = 10e-8;
const int error      = -1;
const double big     = 10e8;

//-----------------------------------------------------------------------------

int SolveSquare (double a, double b, double c, double* x1, double* x2);

int CompareDouble (double argument_1, double argument_2);

int CleanBufer();

int TestSolve(int n_test, double a, double b, double c, int result_right,
              double x1_right, double x2_right);

void AllProverka();

void ScanCoef(double* coef);

void OutResult(int result, double x1, double x2);

//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------

int CompareDouble(double argument_1, double argument_2)
{
    if (fabs(argument_1 - argument_2) < smal)
        {
        return 1;
        }
    return 0;
}

//-----------------------------------------------------------------------------

int CleanBufer()
{
    int ch, i;
    i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        i++;
    if (i > 0)
        return 0;
    return 1;
}

//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------

void ScanCoef(double* a)
{
    int chek = scanf("%lg", a);
    while (CleanBufer() == 0 || chek != 1)
        {
        printf("Try again\n");
        chek = scanf("%lg", a);
        }
}

//-----------------------------------------------------------------------------

void OutResult(int result, double x1, double x2)
{
    switch (result)
        {
        case no_solve:
            printf("Уравнение не имеет корней\n");
            break;

        case one_solve:
            printf("Уравнение имеет один корень: x = %lf\n", x1);
            break;

        case two_solve:
            printf("Уравнение имеет два корня: x1 = %lf; x2 = %lf\n", x1, x2);
            break;

        case more_solve:
            printf("Уравнение имеет бесконечно много корней\n");
            break;

        default:
            printf("Ошибка в исполнении\n");
            break;
        }
}












