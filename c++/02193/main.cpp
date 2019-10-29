#include <iostream>

using namespace std;

long long int save[93][2];

long long int cal(int t, int n)
{
    if(t==1)
    {
        if(n==1) return 1;
        else return 0;
    }
    else
    {
        if(save[t][n]>0) return save[t][n];
        else
        {
            if(n==1) save[t][n]=cal(t-1,n-1);
            if(n==0) save[t][n]=cal(t-1,n)+cal(t-1,n+1);
            return save[t][n];
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    printf("%lld", cal(t,1)+cal(t,0));
    return 0;
}
