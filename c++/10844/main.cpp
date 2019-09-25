#include <iostream>

using namespace std;
long long int a=1000000000;
long long int save[101][10];
long long int cal(int n,int t)
{
    if(n==1) return save[1][t];
    else
    {
        if(save[n][t]>0) return save[n][t];
        else
        {
            if(t==0) save[n][t]=cal(n-1,t+1)%a;
            else if(t==9) save[n][t]=cal(n-1,t-1)%a;
            else save[n][t]=(cal(n-1,t-1)+cal(n-1,t+1))%a;
            return save[n][t];
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=9; i++)
        save[1][i]=1;
    long long int sum=0;
    for(int j=0; j<=9; j++)
        sum=sum+cal(t,j);
    printf("%lld",sum%a);
    return 0;
}
