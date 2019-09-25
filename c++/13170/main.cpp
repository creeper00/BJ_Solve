#include <iostream>

using namespace std;

int main()
{
    int n,k,p,w;
    scanf("%d %d %d %d", &n,&k, &p, &w);
    int res=p/w;
    if(p%w!=0) res++;
    printf("%d", res);
    return 0;
}
