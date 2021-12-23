#include "Header.h"
int N, l = 0;
int G[MAX][MAX];
// Ma Tran ke Dinh-Dinh 
int S[MAX][MAX];
// Ma Tran danh dau Cung da su dung
int path[MAX];
// Mang duong di cua chu trinh

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
    FILE* f = fopen("./MT1.txt", "rt");
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

void PrintData2()
{
    int i, j;
    printf("\nMa Tran Ke S[%d*%d]:\n", N, N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            printf("%4d", S[i][j]);
        printf("\n");
    }
}
void Euler()
{
    int n, k, ok;
    printf("\nNhap diem bat dau: ");
    scanf("%d", &n);
    if (n > N)
        cout << "Nhap sai ";
    else
    {
        for (k = 1; k <= N; k++)
        {
            if ((S[n][k] != 0))
                // co duong noi diem n voi diem k
            {
                S[n][k] = FALSE;
                ok = Check(k);
                if (ok == FALSE)
                {
                    S[n][k] = TRUE;
                }
                else // ok==TRUE
                {
                    printf("Duong di la: ");
                    printf("%d %d ", n, k);
                    for (int r = l - 1; r >= 0; r--)
                        cout << path[r] << " ";
                    cout << endl;
                    return;
                }
            }
        }
    }
}
int Check(int k)
{
    int i, j, ok;
    for (i = 1; i <= N; i++)
    {
        if (S[k][i] == TRUE)  //co duong tu k den cac diem con lai ?
        {
            S[k][i] = FALSE;
	        PrintData2();	
            ok = Check(i);
            // xet tiep diem i den cac diem khac
            if (ok == FALSE)
            {
                S[k][i] = TRUE;
            }
            else
            {
                path[l] = i;
                l++;
                return TRUE;
            }
        }
    }
    for (i = 1; i <= N; i++)
        // khi khong con duong di tu tp k nua
        for (j = 1; j <= N; j++) // quet duyet do thi G xem da het duong chua?
            if (S[i][j] == TRUE)
                return FALSE;
    return TRUE;

}