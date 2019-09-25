#include <iostream>

using namespace std;
char sum[100][100];
int n,m;
int temp1, temp2;

char dpmove(int dp, int a, int b, int cc)
{
    if(dp==1 && cc==1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(sum[a][b]==sum[i][j])
                {
                    if(j>=b && i>=a) temp1=i; temp2=j;
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%s", sum[i]);
    }
    int dp=1;
    int cc=-1;
    int a=0,b=0;
    int h=6;
    while(h>0)
    {

    }
    return 0;
}
