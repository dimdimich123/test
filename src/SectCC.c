#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int SectCC(int x1, int u1, int r1, int x2, int u2, int r2)
{
    float nm;
    nm = sqrt(pow(x2 - x1, 2) + pow(u2 - u1, 2));
    if (nm <= r1 + r2)
        return 1;
    return 0;
}
