#include <iostream>

using namespace std;
long int dp[10];
long int save[10];
int n;
int main()
{
    scanf("%d", &n);
    for(int i=0; i<=9; i++)
        dp[i]=1,save[i]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=9; j++)
        {
            for(int l=0; l<=9; l++)
            {
                if(j>l) dp[j]+=save[l], dp[j]=dp[j]%10007;
                else break;
            }
        }
        for(int l=1; l<=9; l++)
                save[l]=dp[l];
    }
    long int sum=0;
    for(int i=0; i<=9; i++)
    {
        sum+=dp[i];
    }
    printf("%ld", sum%10007);
    return 0;
}
