#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int i=1,sum=1;
    while(n>1)
    {
        i++;
        sum+=i;
        if(sum>=n) break;
    }
    if(i%2==0) printf("%d/%d", (n-sum+i), 1+sum-n);
    else printf("%d/%d", 1+sum-n,(n-sum+i));

    return 0;
}
