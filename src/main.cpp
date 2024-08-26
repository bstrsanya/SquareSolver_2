/*! \mainpage
    \brief 
    Данная программа способна решать уравнений вида \n
    ax^2 + bx + c = 0 \n
    Для решения уравнений необходимо ввести коэффициенты: a, b, c \n
    Итогом работы программы станет ответ на квадратное уравнение. \n
    Перед вводом коэффициентов есть возможность протестировать алгоритм \n
    решения квадратных уравнений, запустив встроенные UnitTest. \n
    В течение всей программы Вас будут сопровождать комментарими от автора, \n
    для Вашего удобства. Комментарии начинаются c "#". \n
    Успешных решений! \n

*/



#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "./../include/SolveSquare.h"
#include "./../include/const.h"
#include "./../include/CompareDouble.h"
#include "./../include/AllProverka.h"
#include "./../include/CleanBufer.h"
#include "./../include/ScanCoef.h"
#include "./../include/TestSolve.h"
#include "./../include/OutResult.h"




int main ()
{
    printf ("#Solving quadratic equations\n");
    AllProverka ();
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

    OutResult (result, x1, x2);
}
