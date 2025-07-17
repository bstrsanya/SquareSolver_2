#include <stdio.h>

#include "CleanBuffer.h"

int CleanBuffer ()
{
    int ch = 0, i = 0;

    while ((ch = getchar ()) != '\n' && ch != EOF)
        i++;

    if (i > 0)
        return 0;
    
    return 1;
}
