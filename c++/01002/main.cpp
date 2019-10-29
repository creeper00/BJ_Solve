#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t>0)
    {
        int counter = 0;
        int x1,y1,x2,y2,r1,r2;
        scanf("%d %d %d %d %d %d", &x1,&y1,&r1,&x2,&y2,&r2);
        int n = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        if(n>(r1+r2)*(r1+r2)) counter =0;
        else if(n== (r1+r2)*(r1+r2) && n!=0) counter = 1;
        else if(n>(r2-r1)*(r2-r1)&&n<(r1+r2)*(r1+r2)) counter =2;
        else if(n==(r2-r1)*(r2-r1) && n!=0) counter=1;
        else if(n<(r2-r1)*(r2-r1)) counter =0;
        else if(n==0 && r1==r2) counter = -1;
        else counter=0;

        printf("%d\n", counter);
        t--;
    }
    return 0;
}
