#include "Header.h"
int N;
int G[MAX][MAX];
// Ma Tran ke Dinh-Dinh 
int S[MAX][MAX];
// Ma Tran danh dau Cung da su dung

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

//Phat trien ham o day

void ReadData()
{
    int i, j;
    FILE* f = fopen("DoAnOSS/MT1.txt", "rt");
    if (f == NULL)
    {
        printf("\nError Loading File!\n");
        return;
    }
    fscanf(f, "%d", &N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            S[i][j] = FALSE;
            fscanf(f, "%d", &G[i][j]);
        }
    }
    fclose(f);
    for (i = 1; i <= N; i++)

        for (j = 1; j <= N; j++)

            if (G[i][j] > 0)
            {
                S[i][j] = TRUE;
            }
}