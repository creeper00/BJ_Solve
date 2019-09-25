#include <iostream>

using namespace std;
int save[101];
int main()
{
    int i=1;
    while(1)
    {
        int sum=0;
        sum=i*i;
        if(10000>=sum) save[i]=sum;
        else break;
        i++;
    }
    int n,m,l=1;
    int mini=0, add=0;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=100; i++)
    {
        if(save[i]>=n && save[i]<=m)
        {
            if(l==1) mini=save[i], l=0;
            add=add+save[i];
        }
    }
    if(add==0) printf("-1");
    else printf("%d\n%d", add, mini);
    return 0;
}
