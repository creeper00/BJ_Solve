#include <iostream>

using namespace std;
int save[2][100001];
int dp[2][100001];
int n;
int cal(int i, int t)
{
    if(t>n) return 0;
    else
    {
        if(dp[i][t]>-1) return dp[i][t];
        else
        {
            if(save[i][t]+cal(1-i,t+1)>save[i][t]+cal(1-i,t+2)) dp[i][t]=save[i][t]+cal(1-i,t+1);
            else dp[i][t]=save[i][t]+cal(1-i,t+2);
            return dp[i][t];
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            dp[0][i]=-1,dp[1][i]=-1;
        for(int i=1; i<=n; i++)
            scanf("%d", &save[0][i]);
        for(int i=1; i<=n; i++)
            scanf("%d", &save[1][i]);

        if(cal(0,1)>cal(1,1)) printf("%d\n", cal(0,1));
        else printf("%d\n", cal(1,1));

        for(int i=1; i<=n; i++)
            dp[0][i]=-1, dp[1][i]=-1;
    }
    return 0;
}
