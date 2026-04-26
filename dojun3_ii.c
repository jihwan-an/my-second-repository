#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[100][100]={1};

    for (int count=0; count < (n+1)/2; count++)
    {
        if (count>0)
            arr[count][count]=arr[count][count-1]+1;
        int i=0;

        //위쪽 채우기
        for (i=count; i<n-count-1; i++)
            arr[count][i+1]=arr[count][i]+1;
        //오른쪽 채우기
        for (i=count; i<n-count-1; i++)
            arr[i+1][n-1-count]=arr[i][n-1-count]+1;
        //아래쪽 채우기
        for (i=n-count-1; i>count; i--)
            arr[n-1-count][i-1]=arr[n-1-count][i]+1;
        //왼쪽 채우기
        for (i=n-count-1; i>count+1; i--)
            arr[i-1][count]=arr[i][count]+1;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            printf("%-5d ", arr[i][j]);
        printf("\n\n");
    }

    return 0;
}