#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void triangle(int xt1, int yt1, int xt2, int yt2, int xt3, int yt3)
{
    float p, plosh, perim, str1, str2, str3;
    str1 = sqrt(pow(xt2 - xt1, 2) + pow(yt2 - yt1, 2));
    str2 = sqrt(pow(xt3 - xt1, 2) + pow(yt3 - yt1, 2));
    str3 = sqrt(pow(xt3 - xt2, 2) + pow(yt3 - yt2, 2));
    p = (str1 + str2 + str3) / 2;
    perim = str1 + str2 + str3;
    plosh = sqrt(p * (p - str1) * (p - str2) * (p - str3));
    printf("Plosh=%f\n", plosh);
    printf("Perim=%f\n", perim);
    return;
}
