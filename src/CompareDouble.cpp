#include <math.h>

#include "./../include/CompareDouble.h"
#include "./../include/const.h"

int CompareDouble (double argument_1, double argument_2)
{
    if (fabs(argument_1 - argument_2) < smal)
        return 1;
    
    return 0;
}
