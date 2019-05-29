#include "game.h"
#include "../library/lib.h"
#include "menu.h"

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

int PlayerTurn(int* B, int jk, int s)
{
    return pole(B, 1, jk, s);
}

void ComputerTurn(int* B, int jk, int s)
{
    pole(B, 0, jk, s);
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
            return;
        }
        if (B[1] == max1) {
            B[1] -= raz;
            return;
        }
        if (B[2] == max1) {
            B[2] -= raz;
            return;
        }
        return;
    }
    if (jk == 4) {
        if (s == 0) {
            int n, m;
            n = rand() % jk;
            m = rand() % (B[n] / 2 + 1) + 1;
            B[n] -= m;
            return;
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
            return;
        }
        if (B[1] == max1) {
            B[1] -= raz;
            return;
        }
        if (B[2] == max1) {
            B[2] -= raz;
            return;
        }
        if (B[3] == max1) {
            B[3] -= raz;
            return;
        }
        return;
    }

    return;
}

void games(int* B, int jk)
{
    int win = 2, s = 0;
    while (1) {
        ComputerTurn(B, jk, s);
        win = winner(B, 0, jk);
        if (win == 0)
            break;
        if (PlayerTurn(B, jk, s))
            return;
        win = winner(B, 1, jk);
        s++;
        if (win == 1)
            break;
    }
    if (win)
        record(s);
    if (win == 0)
        lose();
    return;
}

void standart(int jk)
{
    int* B;
    B = (int*)malloc(jk * sizeof(int));
    if (jk == 3) {
        B[0] = rand() % 3 + 1;
        B[1] = rand() % 3 + 4;
        B[2] = rand() % 4 + 7;
    } else {
        B[0] = 1;
        B[1] = 3;
        B[2] = 5;
        B[3] = 7;
    }
    games(B, jk);
    free(B);
    return;
}
