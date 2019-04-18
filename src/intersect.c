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

int SectPP(
        int px1,
        int py1,
        int px2,
        int py2,
        int px3,
        int py3,
        int px4,
        int py4,
        int px5,
        int py5,
        int px6,
        int py6,
        int px7,
        int py7,
        int px8,
        int py8)
{
    float ua, ub;
    ua = (float)((px5 - px8) * (py1 - py8) - (py5 - py8) * (px1 - px8))
            / ((py5 - py8) * (px2 - px1) - (px5 - px8) * (py2 - py1)); // 1-1
    ub = (float)((px2 - px1) * (py1 - py8) - (py2 - py1) * (px1 - px8))
            / ((py5 - py8) * (px2 - px1) - (px5 - px8) * (py2 - py1));
    if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
        return 1;
    else {
        ua = (float)((px6 - px8) * (py1 - py8) - (py6 - py8) * (px1 - px8))
                / ((py6 - py8) * (px2 - px1)
                   - (px6 - px8) * (py2 - py1)); // 1-2
        ub = (float)((px2 - px1) * (py1 - py8) - (py2 - py1) * (px1 - px8))
                / ((py6 - py8) * (px2 - px1) - (px6 - px8) * (py2 - py1));
        if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
            return 1;
        else {
            ua = (float)((px6 - px7) * (py1 - py7) - (py6 - py7) * (px1 - px7))
                    / ((py6 - py7) * (px2 - px1)
                       - (px6 - px7) * (py2 - py1)); // 1-3
            ub = (float)((px2 - px1) * (py1 - py7) - (py2 - py1) * (px1 - px7))
                    / ((py6 - py7) * (px2 - px1) - (px6 - px7) * (py2 - py1));
            if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                return 1;
            else {
                ua = (float)((px5 - px8) * (py1 - py8)
                             - (py5 - py8) * (px1 - px8))
                        / ((py5 - py8) * (px4 - px1)
                           - (px5 - px8) * (py4 - py1)); // 2-1
                ub = (float)((px4 - px1) * (py1 - py8)
                             - (py4 - py1) * (px1 - px8))
                        / ((py5 - py8) * (px4 - px1)
                           - (px5 - px8) * (py4 - py1));
                if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                    return 1;
                else {
                    ua = (float)((px6 - px8) * (py1 - py8)
                                 - (py6 - py8) * (px1 - px8))
                            / ((py6 - py8) * (px4 - px1)
                               - (px6 - px8) * (py4 - py1)); // 2-2
                    ub = (float)((px4 - px1) * (py1 - py8)
                                 - (py4 - py1) * (px1 - px8))
                            / ((py6 - py8) * (px4 - px1)
                               - (px6 - px8) * (py4 - py1));
                    if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                        return 1;
                    else {
                        ua = (float)((px6 - px7) * (py1 - py7)
                                     - (py6 - py7) * (px1 - px7))
                                / ((py6 - py7) * (px4 - px1)
                                   - (px6 - px7) * (py4 - py1)); // 2-3
                        ub = (float)((px4 - px1) * (py1 - py7)
                                     - (py4 - py1) * (px1 - px7))
                                / ((py6 - py7) * (px4 - px1)
                                   - (px6 - px7) * (py4 - py1));
                        if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                            return 1;
                        else {
                            ua = (float)((px5 - px8) * (py3 - py8)
                                         - (py5 - py8) * (px3 - px8))
                                    / ((py5 - py8) * (px2 - px3)
                                       - (px5 - px8) * (py2 - py3)); // 3-1
                            ub = (float)((px2 - px3) * (py3 - py8)
                                         - (py2 - py3) * (px3 - px8))
                                    / ((py5 - py8) * (px2 - px3)
                                       - (px5 - px8) * (py2 - py3));
                            if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                                return 1;
                            else {
                                ua = (float)((px6 - px8) * (py3 - py8)
                                             - (py6 - py8) * (px3 - px8))
                                        / ((py6 - py8) * (px2 - px3)
                                           - (px6 - px8) * (py2 - py3)); // 3-2
                                ub = (float)((px2 - px3) * (py3 - py8)
                                             - (py2 - py3) * (px3 - px8))
                                        / ((py6 - py8) * (px2 - px3)
                                           - (px6 - px8) * (py2 - py3));
                                if ((0 <= ua && ua <= 1)
                                    && (0 <= ub && ub <= 1))
                                    return 1;
                                else {
                                    ua = (float)((px6 - px7) * (py3 - py7)
                                                 - (py6 - py7) * (px3 - px7))
                                            / ((py6 - py7) * (px2 - px3)
                                               - (px6 - px7)
                                                       * (py2 - py3)); // 3-3
                                    ub = (float)((px2 - px3) * (py3 - py7)
                                                 - (py2 - py3) * (px3 - px7))
                                            / ((py6 - py7) * (px2 - px3)
                                               - (px6 - px7) * (py2 - py3));
                                    if ((0 <= ua && ua <= 1)
                                        && (0 <= ub && ub <= 1))
                                        return 1;
                                    else {
                                        ua = (float)((px5 - px7) * (py1 - py7)
                                                     - (py5 - py7)
                                                             * (px1 - px7))
                                                / ((py5 - py7) * (px2 - px1)
                                                   - (px5 - px7)
                                                           * (py2
                                                              - py1)); // 1-4
                                        ub = (float)((px2 - px1) * (py1 - py7)
                                                     - (py2 - py1)
                                                             * (px1 - px7))
                                                / ((py5 - py7) * (px2 - px1)
                                                   - (px5 - px7) * (py2 - py1));
                                        if ((0 <= ua && ua <= 1)
                                            && (0 <= ub && ub <= 1))
                                            return 1;
                                        else {
                                            ua = (float)((px5 - px7)
                                                                 * (py1 - py7)
                                                         - (py5 - py7)
                                                                 * (px1 - px7))
                                                    / ((py5 - py7) * (px4 - px1)
                                                       - (px5 - px7)
                                                               * (py4
                                                                  - py1)); // 2-4
                                            ub = (float)((px4 - px1)
                                                                 * (py1 - py7)
                                                         - (py4 - py1)
                                                                 * (px1 - px7))
                                                    / ((py5 - py7) * (px4 - px1)
                                                       - (px5 - px7)
                                                               * (py4 - py1));
                                            if ((0 <= ua && ua <= 1)
                                                && (0 <= ub && ub <= 1))
                                                return 1;
                                            else {
                                                ua = (float)((px5 - px7)
                                                                     * (py3
                                                                        - py7)
                                                             - (py5 - py7)
                                                                     * (px3
                                                                        - px7))
                                                        / ((py5 - py7)
                                                                   * (px2 - px3)
                                                           - (px5 - px7)
                                                                   * (py2
                                                                      - py3)); // 3-4
                                                ub = (float)((px2 - px3)
                                                                     * (py3
                                                                        - py7)
                                                             - (py2 - py3)
                                                                     * (px3
                                                                        - px7))
                                                        / ((py5 - py7)
                                                                   * (px2 - px3)
                                                           - (px5 - px7)
                                                                   * (py2
                                                                      - py3));
                                                if ((0 <= ua && ua <= 1)
                                                    && (0 <= ub && ub <= 1))
                                                    return 1;
                                                else {
                                                    ua = (float)((px5 - px8)
                                                                         * (py3
                                                                            - py8)
                                                                 - (py5 - py8)
                                                                         * (px3
                                                                            - px8))
                                                            / ((py5 - py8)
                                                                       * (px4
                                                                          - px3)
                                                               - (px5 - px8)
                                                                       * (py4
                                                                          - py3)); // 4-1
                                                    ub = (float)((px4 - px3)
                                                                         * (py3
                                                                            - py8)
                                                                 - (py4 - py3)
                                                                         * (px3
                                                                            - px8))
                                                            / ((py5 - py8)
                                                                       * (px4
                                                                          - px3)
                                                               - (px5 - px8)
                                                                       * (py4
                                                                          - py3));
                                                    if ((0 <= ua && ua <= 1)
                                                        && (0 <= ub && ub <= 1))
                                                        return 1;
                                                    else {
                                                        ua = (float)((px6 - px8)
                                                                             * (py3
                                                                                - py8)
                                                                     - (py6
                                                                        - py8)
                                                                             * (px3
                                                                                - px8))
                                                                / ((py6 - py8)
                                                                           * (px4
                                                                              - px3)
                                                                   - (px6 - px8)
                                                                           * (py4
                                                                              - py3)); // 4-2
                                                        ub = (float)((px4 - px3)
                                                                             * (py3
                                                                                - py8)
                                                                     - (py4
                                                                        - py3)
                                                                             * (px3
                                                                                - px8))
                                                                / ((py6 - py8)
                                                                           * (px4
                                                                              - px3)
                                                                   - (px6 - px8)
                                                                           * (py4
                                                                              - py3));
                                                        if ((0 <= ua && ua <= 1)
                                                            && (0 <= ub
                                                                && ub <= 1))
                                                            return 1;
                                                        else {
                                                            ua = (float)((px6
                                                                          - px7)
                                                                                 * (py3
                                                                                    - py7)
                                                                         - (py6
                                                                            - py7)
                                                                                 * (px3
                                                                                    - px7))
                                                                    / ((py6
                                                                        - py7)
                                                                               * (px4
                                                                                  - px3)
                                                                       - (px6
                                                                          - px7)
                                                                               * (py4
                                                                                  - py3)); // 4-3
                                                            ub = (float)((px4
                                                                          - px3)
                                                                                 * (py3
                                                                                    - py7)
                                                                         - (py4
                                                                            - py3)
                                                                                 * (px3
                                                                                    - px7))
                                                                    / ((py6
                                                                        - py7)
                                                                               * (px4
                                                                                  - px3)
                                                                       - (px6
                                                                          - px7)
                                                                               * (py4
                                                                                  - py3));
                                                            if ((0 <= ua
                                                                 && ua <= 1)
                                                                && (0 <= ub
                                                                    && ub <= 1))
                                                                return 1;
                                                            else {
                                                                ua = (float)((px5
                                                                              - px7)
                                                                                     * (py3
                                                                                        - py7)
                                                                             - (py5
                                                                                - py7)
                                                                                     * (px3
                                                                                        - px7))
                                                                        / ((py5
                                                                            - py7)
                                                                                   * (px4
                                                                                      - px3)
                                                                           - (px5
                                                                              - px7)
                                                                                   * (py4
                                                                                      - py3)); // 4-4
                                                                ub = (float)((px4
                                                                              - px3)
                                                                                     * (py3
                                                                                        - py7)
                                                                             - (py4
                                                                                - py3)
                                                                                     * (px3
                                                                                        - px7))
                                                                        / ((py5
                                                                            - py7)
                                                                                   * (px4
                                                                                      - px3)
                                                                           - (px5
                                                                              - px7)
                                                                                   * (py4
                                                                                      - py3));
                                                                if ((0 <= ua
                                                                     && ua <= 1)
                                                                    && (0 <= ub
                                                                        && ub <= 1))
                                                                    return 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int SectPT(
        int xt1,
        int yt1,
        int xt2,
        int yt2,
        int xt3,
        int yt3,
        int px4,
        int py4,
        int px5,
        int py5,
        int px6,
        int py6,
        int px7,
        int py7)
{
    float ua, ub;
    ua = (float)((px5 - px4) * (yt1 - py4) - (py5 - py4) * (xt1 - px4))
            / ((py5 - py4) * (xt2 - xt1) - (px5 - px4) * (yt2 - yt1)); // 1-1
    ub = (float)((xt2 - xt1) * (yt1 - py4) - (yt2 - yt1) * (xt1 - px4))
            / ((py5 - py4) * (xt2 - xt1) - (px5 - px4) * (yt2 - yt1));
    if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
        return 1;
    else {
        ua = (float)((px6 - px4) * (yt1 - py4) - (py6 - py4) * (xt1 - px4))
                / ((py6 - py4) * (xt2 - xt1)
                   - (px6 - px4) * (yt2 - yt1)); // 1-2
        ub = (float)((xt2 - xt1) * (yt1 - py4) - (yt2 - yt1) * (xt1 - px4))
                / ((py6 - py4) * (xt2 - xt1) - (px6 - px4) * (yt2 - yt1));
        if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
            return 1;
        else {
            ua = (float)((px6 - px7) * (yt1 - py7) - (py6 - py7) * (xt1 - px7))
                    / ((py6 - py7) * (xt2 - xt1)
                       - (px6 - px7) * (yt2 - yt1)); // 1-3
            ub = (float)((xt2 - xt1) * (yt1 - py7) - (yt2 - yt1) * (xt1 - px7))
                    / ((py6 - py7) * (xt2 - xt1) - (px6 - px7) * (yt2 - yt1));
            if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                return 1;
            else {
                ua = (float)((px5 - px4) * (yt1 - py4)
                             - (py5 - py4) * (xt1 - px4))
                        / ((py5 - py4) * (xt3 - xt1)
                           - (px5 - px4) * (yt3 - yt1)); // 2-1
                ub = (float)((xt3 - xt1) * (yt1 - py4)
                             - (yt3 - yt1) * (xt1 - px4))
                        / ((py5 - py4) * (xt3 - xt1)
                           - (px5 - px4) * (yt3 - yt1));
                if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                    return 1;
                else {
                    ua = (float)((px6 - px4) * (yt1 - py4)
                                 - (py6 - py4) * (xt1 - px4))
                            / ((py6 - py4) * (xt3 - xt1)
                               - (px6 - px4) * (yt3 - yt1)); // 2-2
                    ub = (float)((xt3 - xt1) * (yt1 - py4)
                                 - (yt3 - yt1) * (xt1 - px4))
                            / ((py6 - py4) * (xt3 - xt1)
                               - (px6 - px4) * (yt3 - yt1));
                    if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                        return 1;
                    else {
                        ua = (float)((px6 - px7) * (yt1 - py7)
                                     - (py6 - py7) * (xt1 - px7))
                                / ((py6 - py7) * (xt3 - xt1)
                                   - (px6 - px7) * (yt3 - yt1)); // 2-3
                        ub = (float)((xt3 - xt1) * (yt1 - py7)
                                     - (yt3 - yt1) * (xt1 - px7))
                                / ((py6 - py7) * (xt3 - xt1)
                                   - (px6 - px7) * (yt3 - yt1));
                        if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                            return 1;
                        else {
                            ua = (float)((px5 - px4) * (yt3 - py4)
                                         - (py5 - py4) * (xt3 - px4))
                                    / ((py5 - py4) * (xt2 - xt3)
                                       - (px5 - px4) * (yt2 - yt3)); // 3-1
                            ub = (float)((xt2 - xt3) * (yt3 - py4)
                                         - (yt2 - yt3) * (xt3 - px4))
                                    / ((py5 - py4) * (xt2 - xt3)
                                       - (px5 - px4) * (yt2 - yt3));
                            if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                                return 1;
                            else {
                                ua = (float)((px6 - px4) * (yt3 - py4)
                                             - (py6 - py4) * (xt3 - px4))
                                        / ((py6 - py4) * (xt2 - xt3)
                                           - (px6 - px4) * (yt2 - yt3)); // 3-2
                                ub = (float)((xt2 - xt3) * (yt3 - py4)
                                             - (yt2 - yt3) * (xt3 - px4))
                                        / ((py6 - py4) * (xt2 - xt3)
                                           - (px6 - px4) * (yt2 - yt3));
                                if ((0 <= ua && ua <= 1)
                                    && (0 <= ub && ub <= 1))
                                    return 1;
                                else {
                                    ua = (float)((px6 - px7) * (yt3 - py7)
                                                 - (py6 - py7) * (xt3 - px7))
                                            / ((py6 - py7) * (xt2 - xt3)
                                               - (px6 - px7)
                                                       * (yt2 - yt3)); // 3-3
                                    ub = (float)((xt2 - xt3) * (yt3 - py7)
                                                 - (yt2 - yt3) * (xt3 - px7))
                                            / ((py6 - py7) * (xt2 - xt3)
                                               - (px6 - px7) * (yt2 - yt3));
                                    if ((0 <= ua && ua <= 1)
                                        && (0 <= ub && ub <= 1))
                                        return 1;
                                    else {
                                        ua = (float)((px5 - px7) * (yt1 - py7)
                                                     - (py5 - py7)
                                                             * (xt1 - px7))
                                                / ((py5 - py7) * (xt2 - xt1)
                                                   - (px5 - px7)
                                                           * (yt2
                                                              - yt1)); // 1-4
                                        ub = (float)((xt2 - xt1) * (yt1 - py7)
                                                     - (yt2 - yt1)
                                                             * (xt1 - px7))
                                                / ((py5 - py7) * (xt2 - xt1)
                                                   - (px5 - px7) * (yt2 - yt1));
                                        if ((0 <= ua && ua <= 1)
                                            && (0 <= ub && ub <= 1))
                                            return 1;
                                        else {
                                            ua = (float)((px5 - px7)
                                                                 * (yt1 - py7)
                                                         - (py5 - py7)
                                                                 * (xt1 - px7))
                                                    / ((py5 - py7) * (xt3 - xt1)
                                                       - (px5 - px7)
                                                               * (yt3
                                                                  - yt1)); // 2-4
                                            ub = (float)((xt3 - xt1)
                                                                 * (yt1 - py7)
                                                         - (yt3 - yt1)
                                                                 * (xt1 - px7))
                                                    / ((py5 - py7) * (xt3 - xt1)
                                                       - (px5 - px7)
                                                               * (yt3 - yt1));
                                            if ((0 <= ua && ua <= 1)
                                                && (0 <= ub && ub <= 1))
                                                return 1;
                                            else {
                                                ua = (float)((px5 - px7)
                                                                     * (yt3
                                                                        - py7)
                                                             - (py5 - py7)
                                                                     * (xt3
                                                                        - px7))
                                                        / ((py5 - py7)
                                                                   * (xt2 - xt3)
                                                           - (px5 - px7)
                                                                   * (yt2
                                                                      - yt3)); // 3-4
                                                ub = (float)((xt2 - xt3)
                                                                     * (yt3
                                                                        - py7)
                                                             - (yt2 - yt3)
                                                                     * (xt3
                                                                        - px7))
                                                        / ((py5 - py7)
                                                                   * (xt2 - xt3)
                                                           - (px5 - px7)
                                                                   * (yt2
                                                                      - yt3));
                                                if ((0 <= ua && ua <= 1)
                                                    && (0 <= ub && ub <= 1))
                                                    return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

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

int SectTT(
        int xt1,
        int yt1,
        int xt2,
        int yt2,
        int xt3,
        int yt3,
        int xt4,
        int yt4,
        int xt5,
        int yt5,
        int xt6,
        int yt6)
{
    float ua, ub;
    ua = (float)((xt5 - xt4) * (yt1 - yt4) - (yt5 - yt4) * (xt1 - xt4))
            / ((yt5 - yt4) * (xt2 - xt1) - (xt5 - xt4) * (yt2 - yt1)); // 1-1
    ub = (float)((xt2 - xt1) * (yt1 - yt4) - (yt2 - yt1) * (xt1 - xt4))
            / ((yt5 - yt4) * (xt2 - xt1) - (xt5 - xt4) * (yt2 - yt1));
    if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
        return 1;
    else {
        ua = (float)((xt6 - xt4) * (yt1 - yt4) - (yt6 - yt4) * (xt1 - xt4))
                / ((yt6 - yt4) * (xt2 - xt1)
                   - (xt6 - xt4) * (yt2 - yt1)); // 1-2
        ub = (float)((xt2 - xt1) * (yt1 - yt4) - (yt2 - yt1) * (xt1 - xt4))
                / ((yt6 - yt4) * (xt2 - xt1) - (xt6 - xt4) * (yt2 - yt1));
        if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
            return 1;
        else {
            ua = (float)((xt6 - xt5) * (yt1 - yt5) - (yt6 - yt5) * (xt1 - xt5))
                    / ((yt6 - yt5) * (xt2 - xt1)
                       - (xt6 - xt5) * (yt2 - yt1)); // 1-3
            ub = (float)((xt2 - xt1) * (yt1 - yt5) - (yt2 - yt1) * (xt1 - xt5))
                    / ((yt6 - yt5) * (xt2 - xt1) - (xt6 - xt5) * (yt2 - yt1));
            if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                return 1;
            else {
                ua = (float)((xt5 - xt4) * (yt1 - yt4)
                             - (yt5 - yt4) * (xt1 - xt4))
                        / ((yt5 - yt4) * (xt3 - xt1)
                           - (xt5 - xt4) * (yt3 - yt1)); // 2-1
                ub = (float)((xt3 - xt1) * (yt1 - yt4)
                             - (yt3 - yt1) * (xt1 - xt4))
                        / ((yt5 - yt4) * (xt3 - xt1)
                           - (xt5 - xt4) * (yt3 - yt1));
                if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                    return 1;
                else {
                    ua = (float)((xt6 - xt4) * (yt1 - yt4)
                                 - (yt6 - yt4) * (xt1 - xt4))
                            / ((yt6 - yt4) * (xt3 - xt1)
                               - (xt6 - xt4) * (yt3 - yt1)); // 2-2
                    ub = (float)((xt3 - xt1) * (yt1 - yt4)
                                 - (yt3 - yt1) * (xt1 - xt4))
                            / ((yt6 - yt4) * (xt3 - xt1)
                               - (xt6 - xt4) * (yt3 - yt1));
                    if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                        return 1;
                    else {
                        ua = (float)((xt6 - xt5) * (yt1 - yt5)
                                     - (yt6 - yt5) * (xt1 - xt5))
                                / ((yt6 - yt5) * (xt3 - xt1)
                                   - (xt6 - xt5) * (yt3 - yt1)); // 2-3
                        ub = (float)((xt3 - xt1) * (yt1 - yt5)
                                     - (yt3 - yt1) * (xt1 - xt5))
                                / ((yt6 - yt5) * (xt3 - xt1)
                                   - (xt6 - xt5) * (yt3 - yt1));
                        if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                            return 1;
                        else {
                            ua = (float)((xt5 - xt4) * (yt3 - yt4)
                                         - (yt5 - yt4) * (xt3 - xt4))
                                    / ((yt5 - yt4) * (xt2 - xt3)
                                       - (xt5 - xt4) * (yt2 - yt3)); // 3-1
                            ub = (float)((xt2 - xt3) * (yt3 - yt4)
                                         - (yt2 - yt3) * (xt3 - xt4))
                                    / ((yt5 - yt4) * (xt2 - xt3)
                                       - (xt5 - xt4) * (yt2 - yt3));
                            if ((0 <= ua && ua <= 1) && (0 <= ub && ub <= 1))
                                return 1;
                            else {
                                ua = (float)((xt6 - xt4) * (yt3 - yt4)
                                             - (yt6 - yt4) * (xt3 - xt4))
                                        / ((yt6 - yt4) * (xt2 - xt3)
                                           - (xt6 - xt4) * (yt2 - yt3)); // 3-2
                                ub = (float)((xt2 - xt3) * (yt3 - yt4)
                                             - (yt2 - yt3) * (xt3 - xt4))
                                        / ((yt6 - yt4) * (xt2 - xt3)
                                           - (xt6 - xt4) * (yt2 - yt3));
                                if ((0 <= ua && ua <= 1)
                                    && (0 <= ub && ub <= 1))
                                    return 1;
                                else {
                                    ua = (float)((xt6 - xt5) * (yt3 - yt5)
                                                 - (yt6 - yt5) * (xt3 - xt5))
                                            / ((yt6 - yt5) * (xt2 - xt3)
                                               - (xt6 - xt5)
                                                       * (yt2 - yt3)); // 3-3
                                    ub = (float)((xt2 - xt3) * (yt3 - yt5)
                                                 - (yt2 - yt3) * (xt3 - xt5))
                                            / ((yt6 - yt5) * (xt2 - xt3)
                                               - (xt6 - xt5) * (yt2 - yt3));
                                    if ((0 <= ua && ua <= 1)
                                        && (0 <= ub && ub <= 1))
                                        return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
