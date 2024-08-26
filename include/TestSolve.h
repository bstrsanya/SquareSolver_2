/** \file
Данный файл содержит в себе функцию TestSolve() и struct Test/
*/


#ifndef TESTSOLVE
#define TESTSOLVE


/**
    \brief Структура Test, в которой хранятся данные для проверки алгоритма, который рассчитыват корни квадратного уравнения.

    Необходима для UnitTest. 
*/

struct Test
        {
        int num_test;
        double a, b, c;
        int nRoots;
        double x1ref, x2ref;
        };

        
/**
    \brief Фукнция TestSolve() предназначена для вывода ошибок, которые могут появится в программе при выполнении UnitTest.

    \param[in] data Структура в которой хранятся данные для UnitTest
    \return Результат проверки UnitTest.
*/


int TestSolve (Test* data);

#endif
