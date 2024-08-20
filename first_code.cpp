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

//-----------------------------------------------------------------------------

int SolveSquare (double a, double b, double c, double* x1, double* x2);

int Nol (double argument);

void CleanBufer();

//-----------------------------------------------------------------------------

int main()
{
    printf ("#Решение квадратных уравнений\n");
    printf ("#Введите коэффициенты\n");

    double a = 0, b = 0, c = 0;
    int num = scanf ("%lf %lf %lf %с", &a, &b, &c);
    while (num != 3)
        {
        printf ("Еще раз\n");
        CleanBufer();
        num = scanf ("%lf %lf %lf", &a, &b, &c);
        }

    double x1 = 0, x2 = 0;
    int result = SolveSquare (a, b, c, &x1, &x2);

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

//-----------------------------------------------------------------------------

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (Nol(a) == 0)
        {
        double D = b * b - 4 * a * c;

        if (D > 0)
            {
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return two_solve;
            }

        if (Nol(D))
            {
            *x1 = *x2 = -b / (2 * a);
            return one_solve;
            }

        if (D < 0)
            {
            return no_solve;
            }
        }

    else if (Nol(a) && Nol(b) && Nol(c))
        {
        return more_solve;
        }

    else if (Nol(a) && Nol(b))
        {
        return no_solve;
        }

    else if (Nol(a))
        {
        *x1 = *x2 = -c / b;

        return one_solve;
        }

    return error;
}

//-----------------------------------------------------------------------------

int Nol(double argument)
{
    if (fabs(argument) < smal)
        {
        return 1;
        }
    return 0;
}

//-----------------------------------------------------------------------------

void CleanBufer()
{

    char ch;
    while ((ch = getchar()) != '\n')
        ;
}

//-----------------------------------------------------------------------------


