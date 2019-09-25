#include <iostream>

using namespace std;
int cal(int a, int b, int c, int n,int k);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n",cal(1,2,3,n,0));
    cal(1,2,3,n,1);
    return 0;
}

int cal(int a, int b, int c, int n,int k)
{
    if(n==1)
    {
        if(k==1) printf("%d %d\n",a,c);
        return 1;
    }
    else
    {
        int sum=1;
        sum+=cal(a,c,b, n-1,k);
        if(k==1) printf("%d %d\n",a,c);
        sum+=cal(b,a,c, n-1,k);
        return sum;
    }
}
