#include <iostream>

using namespace std;

int tri[501][501];
int save[501][501];

int cal(int t, int n)
{
    if(t==1) return tri[1][1];
    else
    {
        if(save[t][n]>0) return save[t][n];
        else
        {
            if(n-1>0&&cal(t-1,n-1)+tri[t][n]>=save[t][n]) save[t][n]=cal(t-1,n-1)+tri[t][n];
            if(n<t&&cal(t-1,n)+tri[t][n]>=save[t][n]) save[t][n]=cal(t-1,n)+tri[t][n];
            return save[t][n];
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        for(int j=1; j<=i; j++)
        {
            scanf("%d", &tri[i][j]);
        }
    }
    int sum=0;
    for(int l=1; l<=t; l++)
    {
        if(sum<cal(t,l)) sum=cal(t,l);
    }
    printf("%d", sum);
    return 0;
}
