#include <iostream>

using namespace std;
int save[101];
int dp[10001];
int n,k;

int main()
{
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
        scanf("%d", &save[i]);
    dp[0]=1;
    for(int i=1; i<=n; i++)
        for(int j=save[i]; j<=k; j++)
            if(j-save[i]>=0) dp[i][j]+=dp[j-save[i]];
    printf("%d", dp[save[1]][k]);
    return 0;
}
