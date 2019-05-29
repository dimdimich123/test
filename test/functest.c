#include "functest.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BubbleSort(int* A, int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                k = A[j];
                A[j] = A[j - 1];
                A[j - 1] = k;
            }
        }
    }
    return;
}

int games(int** A, int* B, int jk)
{
    int win = 2, s = 1;
    while (1) {
        ComputerTurn(A, B, jk, s);
        win = winner(B, 0, jk);
        if (win == 0)
            break;
        ComputerTurn(A, B, jk, s);
        win = winner(B, 1, jk);
        s++;
        if (win == 1)
            break;
    }
    return 1;
}

int winner(int* B, int w, int jk)
{
    if (w) {
        if (jk == 3) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
                return 1;
            }
        }
        if (jk == 4) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
                return 1;
            }
        }
    }
    if (w == 0) {
        if (jk == 3) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
                return 0;
            }
        }
        if (jk == 4) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
                return 0;
            }
        }
    }
    return 2;
}

int standart(int jk)
{
    int i, j, **A, *B;
    int s = 0;
    A = (int**)malloc(jk * sizeof(int*));
    for (i = 0; i < jk; i++) {
        A[i] = (int*)malloc(10 * sizeof(int));
        for (j = 0; j < 10; j++)
            A[i][j] = j + 1;
    }
    B = (int*)malloc(jk * sizeof(int));
    if (jk == 3) {
        B[0] = rand() % 3 + 1;
        B[1] = rand() % 3 + 4;
        B[2] = rand() % 4 + 7;
        s = 1;
    } else {
        B[0] = 1;
        B[1] = 3;
        B[2] = 5;
        B[3] = 7;
        s = 2;
    }
    for (i = 0; i < jk; i++)
        free(A[i]);
    free(A);
    free(B);
    return s;
}

int ComputerTurn(int** A, int* B, int jk, int s)
{
    int max1, i, min, med, med2, raz = 0, C[jk];
    if (jk == 3) {
        for (i = 0; i < jk; i++)
            C[i] = B[i];
        BubbleSort(C, jk);
        min = C[0];
        med = C[1];
        max1 = C[2];
        if (med == max1 && min == 0)
            med = max1 - 1;
        if (med == max1)
            med = min;
        raz = max1 + min - med;
        if (B[0] == max1) {
            B[0] -= raz;
            return B[0];
        }
        if (B[1] == max1) {
            B[1] -= raz;
            return B[1];
        }
        if (B[2] == max1) {
            B[2] -= raz;
            return B[2];
        }
        return 3;
    }
    if (jk == 4) {
        if (s == 0) {
            int n, m;
            n = 1;
            m = 2;
            B[n] -= m;
            return B[n];
        }
        for (i = 0; i < jk; i++)
            C[i] = B[i];
        BubbleSort(C, jk);
        min = C[0];
        med = C[1];
        med2 = C[2];
        max1 = C[3];
        raz = max1 + med - min - med2;
        if (raz == 0)
            raz = max1;
        if (B[0] == max1) {
            B[0] -= raz;
            return B[0];
        }
        if (B[1] == max1) {
            B[1] -= raz;
            return B[1];
        }
        if (B[2] == max1) {
            B[2] -= raz;
            return B[2];
        }
        if (B[3] == max1) {
            B[3] -= raz;
            return B[3];
        }
    }
    return 555;
}

int PlayerTurn(int* B, int m, int n)
{
    while (1) {
        if (m == 1) {
            if (B[0] == 0)
                return 0;
            if (B[0] >= n) {
                B[0] -= n;
                return B[0];
            }
            if (B[0] < n) {
                B[0] = 0;
                return B[0];
            }
        }
        if (m == 2) {
            if (B[1] == 0)
                return 0;
            if (B[1] >= n) {
                B[1] -= n;
                return B[1];
            }
            if (B[1] < n) {
                B[1] = 0;
                return B[1];
            }
        }
        if (m == 3) {
            if (B[2] == 0)
                return 0;
            if (B[2] >= n) {
                B[2] -= n;
                return B[2];
            }
            if (B[2] < n) {
                B[2] = 0;
                return B[2];
            }
        }
        if (m == 4) {
            if (B[3] == 0)
                return 0;
            if (B[3] >= n) {
                B[3] -= n;
                return B[3];
            }
            if (B[3] < n) {
                B[3] = 0;
                return B[3];
            }
        }
    }
    return 2222;
}
