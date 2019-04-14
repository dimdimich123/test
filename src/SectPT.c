#include <math.h>
#include <stdlib.h>
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
