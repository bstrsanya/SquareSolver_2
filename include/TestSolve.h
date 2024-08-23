#ifndef TESTSOLVE
#define TESTSOLVE

struct Test
        {
        int num_test;
        double a, b, c;
        int nRoots;
        double x1ref, x2ref;
        };

        
int TestSolve(Test* data);

#endif
