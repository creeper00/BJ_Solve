#include <iostream>

using namespace std;
int t;
void cal(int n, int m)
{
    if(n==1) printf("*");
    else
    {
        int a=n/3;
        int b=m%n;
        for(int i=1; i<=n; i=i+a)
        {
            if(b>a && b<=2*a && i>a && i<=2*a)
            {
                for(int j=1; j<=a; j++)
                    printf(" ");
            }
            else cal(n/3,m);
        }
    }
}
int main()
{
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        cal(t,i);
        printf("\n");
    }
    return 0;
}
