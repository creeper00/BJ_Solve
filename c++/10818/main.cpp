#include <iostream>

using namespace std;

int main()
{
    int n,a=0,b=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(a==0 || a>temp) a=temp;
        if(b==0 || b<temp) b=temp;
    }
    printf("%d %d", a,b);
    return 0;
}
