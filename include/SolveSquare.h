/** \file
Данный файл содержит в себе функцию SolveSquare()
*/


#ifndef SOLVESQUARE
#define SOLVESQUARE


/**
    \brief Фукнция SolveSquare() вычисляет корни квадратного уравнения.

    \param[in] a Первый коэффициент квадратного уравнения.
    \param[in] b Второй коэффициент квадратного уравнения.
    \param[in] c Третий коэффициент квадратного уравнения.
    \param[out] x1 Первый корень квадратного уравнения.
    \param[out] x2 Второй корень квадратного уравнения.
    \return Количество решений квадратного уравнения.
*/


int SolveSquare (double a, double b, double c, double* x1, double* x2);

#endif
