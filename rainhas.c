#include <stdio.h>
#define N 8
void backtrack(int* col, int* a, int* b, int* rainha, int);
int main(void)
{
    int col[N];
    int a[2 * N];
    int b[2 * N];
    int rainha[N] = {0};
    int i;

    for(i = 1; i <= N; i++)
    {
        col[i] = 1;
    }

    for(i = 1; i <= 2 * N; i++)
    {
        a[i] = b[i] = 1;
    }

    backtrack(col, a, b, rainha, 1);
    return 0;
}

void printRainha(int* rainha)
{
    int x, y, resp;

    for(y = 1; y <= N; y++)
    {
        for(x = 1; x <= N; x++)
        {
            if (rainha[y] == x)
            {
                resp = x - 1;
                printf("%d ", resp);
            }
        }
    }

    printf("\n");
}

void backtrack(int* col, int* a, int* b, int* rainha, int i)
{
    if(i > N)
    {
        printRainha(rainha);
    }
    else
    {
        int j;

        for(j = 1; j <= N; j++)
        {
            if(col[j] == 1 && a[i + j] == 1 && b[i - j + N] == 1)
            {
                rainha[i] = j;
                col[j] = a[i + j] = b[i - j + N] = 0;
                backtrack(col, a, b, rainha, i + 1);
                col[j] = a[i + j] = b[i - j + N] = 1;
            }
        }
    }
}