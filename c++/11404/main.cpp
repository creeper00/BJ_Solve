#include <iostream>

using namespace std;

int n,k,turn;
int save[101][101];

void cal()
{
    for(int l=1; l<=n; l++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            if(i!=j && (save[i][l]!=0 && save[l][j]!=0) && (save[i][l]+save[l][j]<save[i][j] || save[i][j]==0)) save[i][j]=save[i][l]+save[l][j];

        }
    }
}
int main()
{
    int a,b,temp;
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i=0; i<k; i++)
    {
        scanf("%d %d %d", &a, &b, &temp);
        if(save[a][b]==0 || save[a][b]>temp) save[a][b]=temp;
    }
    int check=-1;
    cal();

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ", save[i][j]);
        }
        printf("\n");
    }
    return 0;
}
