#include <math.h>
#include <stdlib.h>
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
