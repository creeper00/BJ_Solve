#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int n,m;
        long long int sum=1;
        scanf("%d %d", &n,&m);
        for(int i=1; i<=n; i++)
        {
            sum=sum*(m+1-i)/i;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
