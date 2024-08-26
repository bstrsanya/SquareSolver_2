#include <stdio.h>

#include "./../include/CleanBufer.h"

int CleanBufer ()
{
    int ch = 0, i = 0;

    while ((ch = getchar ()) != '\n' && ch != EOF)
        i++;

    if (i > 0)
        return 0;
    
    return 1;
}
