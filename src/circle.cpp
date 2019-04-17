#include <stdio.h>
#include <stdlib.h>
void circle(int f)
{
    float ploshs, perims;
    ploshs = 3.14 * f * f;
    printf("Plosh=%3.3f\n", ploshs);
    perims = 2 * 3.14 * f;
    printf("Perim=%3.3f\n", perims);
    return;
}
