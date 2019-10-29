#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int h,w,n;
        scanf("%d %d %d", &h,&w,&n);
        int a=n/h;
        int b=n%h;
        if(b==0) b=h;
        else a++;
        printf("%d\n", b*100+a);
    }
    return 0;
}
