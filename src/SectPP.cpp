#include <math.h>
#include <stdlib.h>
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
