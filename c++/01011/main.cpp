#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        long long int a,b,j=0, sum=0;
        scanf("%lld %lld", &a,&b);
        long int n=b-a;
        long int m=n%2;
        n=n/2;
        while(1)
        {
            j++;
            sum+=j;
            if(n<sum) break;
        }
        sum-=j;
        j--;
        if( ((n-sum)*2+m) > (j+1) ) j=j*2+2;
        else if( ((n-sum)*2+m)>0 ) j=j*2+1;
        else j=j*2;
        printf("%lld\n",j);
    }
    return 0;
}
