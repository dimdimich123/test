#include "intersect.h"
#include "Str.h"
#include "figures.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char B[] = "circle", T[] = "triangle", P[] = "polygon";
    char FI1[100], FI2[100], FI3[245];
    int bb = 0;
    int x1, u1, x2, u2, x3, u3, r1, r2, r3, xt1, xt2, xt3, yt1, yt2, yt3, xt4,
            xt5, xt6, yt4, yt5, yt6, xt7, xt8, xt9, yt7, yt8, yt9, px1, py1,
            px2, py2, px3, py3, px4, py4, px5, py5, px6, py6, px7, py7, px8,
            py8, px9, py9, px10, py10, px11, py11, px12, py12;
    int flag = 0, flag1 = 0, flag2 = 0, flag3 = 0, ps2 = 0, ps3 = 0, ps4 = 0;
    bb = 1;
    while (1) {
        flag
                = Str(x1,
                      u1,
                      r1,
                      xt1,
                      yt1,
                      xt2,
                      yt2,
                      xt3,
                      yt3,
                      px1,
                      py1,
                      px2,
                      py2,
                      px3,
                      py3,
                      px4,
                      py4,
                      bb,
                      FI1,
                      FI2,
                      FI3);
        if (flag)
            break;
        if (flag == 3)
            return 0;
    }
    bb = 2;
    while (1) {
        flag
                = Str(x2,
                      u2,
                      r2,
                      xt4,
                      yt4,
                      xt5,
                      yt5,
                      xt6,
                      yt6,
                      px5,
                      py5,
                      px6,
                      py6,
                      px7,
                      py7,
                      px8,
                      py8,
                      bb,
                      FI1,
                      FI2,
                      FI3);
        if (flag)
            break;
        if (flag == 3)
            return 0;
    }
    bb = 3;
    while (1) {
        flag
                = Str(x3,
                      u3,
                      r3,
                      xt7,
                      yt7,
                      xt8,
                      yt8,
                      xt9,
                      yt9,
                      px9,
                      py9,
                      px10,
                      py10,
                      px11,
                      py11,
                      px12,
                      py12,
                      bb,
                      FI1,
                      FI2,
                      FI3);
        if (flag)
            break;
        if (flag == 3)
            return 0;
    }
    puts("\n");
    // 1-triangle
    if (strncmp(T, FI1, 6) == 0) {
        puts(FI1);
        triangle(xt1, yt1, xt2, yt2, xt3, yt3);
        printf("Intersects:\n");
        if (strncmp(B, FI2, 6) == 0)
            flag1 = SectTC(x2, u2, r2, xt1, yt1, xt2, yt2, xt3, yt3);
        if (strncmp(T, FI2, 6) == 0)
            flag2 = SectTT(
                    xt1, yt1, xt2, yt2, xt3, yt3, xt4, yt4, xt5, yt5, xt6, yt6);
        if (strncmp(P, FI2, 6) == 0)
            flag3 = SectPT(
                    xt1,
                    yt1,
                    xt2,
                    yt2,
                    xt3,
                    yt3,
                    px5,
                    py5,
                    px6,
                    py6,
                    px7,
                    py7,
                    px8,
                    py8);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps2 = 2;
            printf("2.");
            puts(FI2);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
        if (strncmp(B, FI3, 6) == 0)
            flag1 = SectTC(x3, u3, r3, xt1, yt1, xt2, yt2, xt3, yt3);
        if (strncmp(T, FI3, 6) == 0)
            flag2 = SectTT(
                    xt1, yt1, xt2, yt2, xt3, yt3, xt7, yt7, xt8, yt8, xt9, yt9);
        if (strncmp(P, FI3, 6) == 0)
            flag3 = SectPT(
                    xt1,
                    yt1,
                    xt2,
                    yt2,
                    xt3,
                    yt3,
                    px9,
                    py9,
                    px10,
                    py10,
                    px11,
                    py11,
                    px12,
                    py12);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps3 = 3;
            printf("3.");
            puts(FI3);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
    }
    // 1-circle
    if (strncmp(B, FI1, 6) == 0) {
        puts(FI1);
        circle(r1);
        printf("Intersects:\n");
        if (strncmp(T, FI2, 6) == 0)
            flag1 = SectTC(x1, u1, r1, xt4, yt4, xt5, yt5, xt6, yt6);
        if (strncmp(B, FI2, 6) == 0)
            flag2 = SectCC(x1, u1, r1, x2, u2, r2);
        if (strncmp(P, FI2, 6) == 0)
            flag3 = SectPC(x1, u1, r1, px5, py5, px6, py6, px7, py7, px8, py8);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps2 = 2;
            printf("2.");
            puts(FI2);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
        if (strncmp(B, FI3, 6) == 0)
            flag1 = SectCC(x1, u1, r1, x3, u3, r3);
        if (strncmp(T, FI3, 6) == 0)
            flag2 = SectTC(x1, u1, r1, xt7, yt7, xt8, yt8, xt9, yt9);
        if (strncmp(P, FI3, 6) == 0)
            flag3 = SectPC(
                    x1, u1, r1, px9, py9, px10, py10, px11, py11, px12, py12);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps3 = 3;
            printf("3.");
            puts(FI3);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
    }
    // 1-polygon
    if (strncmp(P, FI1, 7) == 0) {
        puts(FI1);
        polygon(px1, py1, px2, py2, px3, py3, px4, py4);
        printf("Intersects:\n");
        if (strncmp(T, FI2, 6) == 0)
            flag1 = SectPT(
                    xt4,
                    yt4,
                    xt5,
                    yt5,
                    xt6,
                    yt6,
                    px1,
                    py1,
                    px2,
                    py2,
                    px3,
                    py3,
                    px4,
                    py4);
        if (strncmp(B, FI2, 6) == 0)
            flag2 = SectPC(x2, u2, r2, px1, py1, px2, py2, px3, py3, px4, py4);
        if (strncmp(P, FI2, 6) == 0)
            flag3 = SectPP(
                    px1,
                    py1,
                    px2,
                    py2,
                    px3,
                    py3,
                    px4,
                    py4,
                    px5,
                    py5,
                    px6,
                    py6,
                    px7,
                    py7,
                    px8,
                    py8);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps2 = 2;
            printf("2.");
            puts(FI2);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
        if (strncmp(T, FI3, 6) == 0)
            flag1 = SectPT(
                    xt7,
                    yt7,
                    xt8,
                    yt8,
                    xt9,
                    yt9,
                    px1,
                    py1,
                    px2,
                    py2,
                    px3,
                    py3,
                    px4,
                    py4);
        if (strncmp(B, FI3, 6) == 0)
            flag2 = SectPC(x3, u3, r3, px1, py1, px2, py2, px3, py3, px4, py4);
        if (strncmp(P, FI3, 6) == 0)
            flag3 = SectPP(
                    px1,
                    py1,
                    px2,
                    py2,
                    px3,
                    py3,
                    px4,
                    py4,
                    px9,
                    py9,
                    px10,
                    py10,
                    px11,
                    py11,
                    px12,
                    py12);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps3 = 3;
            printf("3.");
            puts(FI3);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
    }

    puts("\n");
    // 2-triangle
    if (strncmp(T, FI2, 6) == 0) {
        puts(FI2);
        triangle(xt4, yt4, xt5, yt5, xt6, yt6);
        printf("Intersects:\n");
        if (ps2 == 2) {
            printf("1.");
            puts(FI1);
        }
        if (strncmp(B, FI3, 6) == 0)
            flag1 = SectTC(x3, u3, r3, xt4, yt4, xt5, yt5, xt6, yt6);
        if (strncmp(T, FI3, 6) == 0)
            flag2 = SectTT(
                    xt4, yt4, xt5, yt5, xt6, yt6, xt7, yt7, xt8, yt8, xt9, yt9);
        if (strncmp(P, FI3, 6) == 0)
            flag3 = SectPT(
                    xt4,
                    yt4,
                    xt5,
                    yt5,
                    xt6,
                    yt6,
                    px9,
                    py9,
                    px10,
                    py10,
                    px11,
                    py11,
                    px12,
                    py12);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps4 = 3;
            printf("3.");
            puts(FI3);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
    }
    // 2-circle
    if (strncmp(B, FI2, 6) == 0) {
        puts(FI2);
        circle(r2);
        printf("Intersects:\n");
        if (ps2 == 2) {
            printf("1.");
            puts(FI1);
        }
        if (strncmp(B, FI3, 6) == 0)
            flag1 = SectCC(x2, u2, r2, x3, u3, r3);
        if (strncmp(T, FI3, 6) == 0)
            flag2 = SectTC(x2, u2, r2, xt7, yt7, xt8, yt8, xt9, yt9);
        if (strncmp(P, FI3, 6) == 0)
            flag3 = SectPC(
                    x2, u2, r2, px9, py9, px10, py10, px11, py11, px12, py12);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps4 = 3;
            printf("3.");
            puts(FI3);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
    }
    // 2-polygon
    if (strncmp(P, FI2, 7) == 0) {
        puts(FI2);
        polygon(px5, py5, px6, py6, px7, py7, px8, py8);
        printf("Intersects:\n");
        if (ps2 == 2) {
            printf("1.");
            puts(FI1);
        }
        if (strncmp(T, FI3, 6) == 0)
            flag1 = SectPT(
                    xt7,
                    yt7,
                    xt8,
                    yt8,
                    xt9,
                    yt9,
                    px5,
                    py5,
                    px6,
                    py6,
                    px7,
                    py7,
                    px8,
                    py8);
        if (strncmp(B, FI3, 6) == 0)
            flag2 = SectPC(x3, u3, r3, px5, py5, px6, py6, px7, py7, px8, py8);
        if (strncmp(P, FI3, 6) == 0)
            flag3 = SectPP(
                    px5,
                    py5,
                    px6,
                    py6,
                    px7,
                    py7,
                    px8,
                    py8,
                    px9,
                    py9,
                    px10,
                    py10,
                    px11,
                    py11,
                    px12,
                    py12);
        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            ps4 = 3;
            printf("3.");
            puts(FI3);
        }
        flag1 = 0, flag2 = 0, flag3 = 0;
    }

    puts("\n");
    // 3-triangle
    if (strncmp(T, FI3, 6) == 0) {
        puts(FI3);
        triangle(xt7, yt7, xt8, yt8, xt9, yt9);
        printf("Intersects:\n");
        if (ps3 == 3) {
            printf("1.");
            puts(FI1);
        }
        if (ps4 == 3) {
            printf("2.");
            puts(FI2);
        }
    }
    // 3-circle
    if (strncmp(B, FI3, 6) == 0) {
        puts(FI3);
        circle(r3);
        printf("Intersects:\n");
        if (ps3 == 3) {
            printf("1.");
            puts(FI1);
        }
        if (ps4 == 3) {
            printf("2.");
            puts(FI2);
        }
    }
    // 3-polygon
    if (strncmp(P, FI3, 7) == 0) {
        puts(FI3);
        polygon(px9, py9, px10, py10, px11, py11, px12, py12);
        printf("Intersects:\n");
        if (ps3 == 3) {
            printf("1.");
            puts(FI1);
        }
        if (ps4 == 3) {
            printf("2.");
            puts(FI2);
        }
    }
    return 0;
}
