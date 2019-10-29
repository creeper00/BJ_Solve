#include <iostream>

using namespace std;
int save[301][301];
int dp[301][301];
int n,m;
int cal(int x, int y)
{
        if(dp[x][y]>0) return dp[x][y];
        else
        {
            dp[x][y]=save[x][y]+cal(x-1,y)+cal(x,y-1)-cal(x-1,y-1);
            return dp[x][y];
        }
}
int main()
{
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &save[i][j]);
            cal(i,j);
        }
    }
    int t;
    scanf("%d", &t);
    while(t>0)
    {
        int a,b,c,d;
        scanf("%d %d %d %d", &a,&b,&c,&d);
        printf("%d\n", dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1]);
        t--;
    }
    return 0;
}
