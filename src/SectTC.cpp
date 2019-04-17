#include <math.h>
#include <stdlib.h>
int SectTC(
        int x1,
        int u1,
        int r1,
        int xt1,
        int yt1,
        int xt2,
        int yt2,
        int xt3,
        int yt3)
{
    float OA, OB, OC, rast1, rast2, rast3;
    OA = sqrt(pow(x1 - xt1, 2) + pow(u1 - yt1, 2));
    OB = sqrt(pow(x1 - xt2, 2) + pow(u1 - yt2, 2));
    OC = sqrt(pow(x1 - xt3, 2) + pow(u1 - yt3, 2));
    rast1 = abs(
            ((yt2 - yt1) * x1 + (xt1 - xt2) * u1 + (xt2 * yt1 - xt1 * yt2))
            / sqrt(pow(xt1 - xt2, 2) + pow(yt1 - yt2, 2)));
    rast2 = abs(
            ((yt3 - yt1) * x1 + (xt1 - xt3) * u1 + (xt3 * yt1 - xt1 * yt3))
            / sqrt(pow(xt1 - xt3, 2) + pow(yt1 - yt3, 2)));
    rast3 = abs(
            ((yt3 - yt2) * x1 + (xt2 - xt3) * u1 + (xt3 * yt2 - xt2 * yt3))
            / sqrt(pow(xt2 - xt3, 2) + pow(yt2 - yt3, 2)));
    if (((OC >= r1 && OB >= r1 && rast3 >= r1)
         && (OA >= r1 && OC >= r1 && rast2 >= r1)
         && (OA >= r1 && OB >= r1 && rast1 >= r1))
        == 0) {
        return 1;
    }
    return 0;
}
