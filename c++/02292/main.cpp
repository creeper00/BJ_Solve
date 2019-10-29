#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if(n==1) { printf("1"); return 0; }
    int num = (n-2)/6;
    if(num==0) { printf("2"); return 0; }
    int i=1, j=0;
    while(j<=num)
    {
        j=j+i;
        i++;
    }
    printf("%d",i);
    return 0;
}
