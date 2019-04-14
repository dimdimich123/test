#include <math.h>
#include <stdlib.h>
int SectPC(
        int x1,
        int u1,
        int r1,
        int px1,
        int py1,
        int px2,
        int py2,
        int px3,
        int py3,
        int px4,
        int py4)
{
    float OA, OB, OC, OD, rast1, rast2, rast3, rast4;
    OA = sqrt(pow(x1 - px1, 2) + pow(u1 - py1, 2));
    OB = sqrt(pow(x1 - px2, 2) + pow(u1 - py2, 2));
    OC = sqrt(pow(x1 - px3, 2) + pow(u1 - py3, 2));
    OD = sqrt(pow(x1 - px4, 2) + pow(u1 - py4, 2));
    rast1 = abs(
            ((py2 - py1) * x1 + (px1 - px2) * u1 + (px2 * py1 - px1 * py2))
            / sqrt(pow(px1 - px2, 2) + pow(py1 - py2, 2)));
    rast2 = abs(
            ((py4 - py1) * x1 + (px1 - px4) * u1 + (px4 * py1 - px1 * py4))
            / sqrt(pow(px1 - px4, 2) + pow(py1 - py4, 2)));
    rast3 = abs(
            ((py2 - py3) * x1 + (px3 - px2) * u1 + (px2 * py3 - px3 * py2))
            / sqrt(pow(px3 - px2, 2) + pow(py3 - py2, 2)));
    rast4 = abs(
            ((py4 - py3) * x1 + (px3 - px4) * u1 + (px4 * py3 - px3 * py4))
            / sqrt(pow(px3 - px4, 2) + pow(py3 - py4, 2)));
    if (OA < r1 && OB < r1 && OC < r1 && OD < r1)
        return 0;
    if (((OC >= r1 && OB >= r1 && rast3 >= r1)
         && (OC >= r1 && OD >= r1 && rast4 >= r1)
         && (OA >= r1 && OD >= r1 && rast2 >= r1)
         && (OA >= r1 && OB >= r1 && rast1 >= r1))
        == 0) {
        return 1;
    }
    return 0;
}
