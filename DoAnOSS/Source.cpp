#include "Header.h"
int N;
int G[MAX][MAX];
// Ma Tran ke Dinh-Dinh 

//Phat trien ham o day
void PrintData() {
    int i, j;
    printf("\nMa Tran Ke G[%d*%d]:\n", N, N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            printf("%4d", G[i][j]);
        printf("\n");
    }
}