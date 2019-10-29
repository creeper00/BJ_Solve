#include <iostream>

using namespace std;
long long int save[101];
long long int cal(int t)
{
    if(t<=3) return save[t]=1;
    else if(t<=5) return save[t]=2;
    else
    {
        if(save[t]>0) return save[t];
        else
        {
            save[t]=cal(t-1)+cal(t-5);
            return save[t];
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", cal(n));
    }
    return 0;
}
