#include <iostream>

using namespace std;

int main()
{
    int x,y,w,h;
    scanf("%d %d %d %d", &x,&y,&w,&h);
    int sum=x;
    if(y<sum) sum=y;
    if( (w-x)<sum ) sum=w-x;
    if( (h-y)<sum ) sum=h-y;
    printf("%d", sum);
    return 0;
}
