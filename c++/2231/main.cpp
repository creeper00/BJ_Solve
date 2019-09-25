#include <iostream>

using namespace std;

int main()
{
    int ans=0,temp=0;
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int a=i;
        temp=a;
        while(a)
        {
            temp=temp+a%10;
            a=a/10;
        }
        if(temp==n) {ans=i; break;}
    }
    printf("%d", ans);
    return 0;
}
