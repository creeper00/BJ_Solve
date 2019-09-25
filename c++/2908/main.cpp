#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d %d", &a,&b);
    int n,m;
    n = a%10*100+(a/10)%10*10+a/100;
    m = b%10*100+(b/10)%10*10+b/100;
    if(n>m) printf("%d",n);
    else printf("%d",m);
    return 0;
}
