#include <iostream>

using namespace std;
int n,a;
int save[1001];
int dp[1001];
int cal(int t)
{
    int temp=0;
    if(t==n) return dp[n]=1;
    else if(dp[t]>0) return dp[t];
    else
    {
        for(int i=t+1; i<=n; i++)
            if(save[t]<save[i] && dp[t]<cal(i)+1) dp[t]=cal(i)+1;
    }
    if(dp[t]==0) dp[t]=1;
    return dp[t];
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &save[i]);
    int ans=0;
    int b=save[1];
    for(int i=n; i>0; i--)
        if(cal(i)>ans) ans=cal(i);
    printf("%d", ans);
    return 0;
}
