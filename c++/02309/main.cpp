#include <iostream>

using namespace std;

int save[9];
int newb[8];
int main()
{
    int i;
    for(i=0; i<9; i++)
    {
        scanf("%d", &save[i]);
    }
    int a=0;
    int b=1;
    int sum=0;
    for(i=0; i<36; i++)
    {
        for(int l=0; l<9; l++)
        {
            if(l!=a && l!=b) sum=sum+save[l];
        }
        if(sum==100) break;
        sum=0;
        b++;
        if(b==9) a++, b=a+1;
    }
    int y=0;
    for(int v=0; v<9; v++)
    {
        if(v!=a && v!=b) newb[y]=save[v], y++;
    }
    int m=1;
    while(m!=0)
    {
        m=0;
        for(int n=0; n<7; n++)
        {
            if(newb[n]>newb[n+1])
            {
                int temp = newb[n];
                newb[n]=newb[n+1];
                newb[n+1]=temp;
                m++;
            }
        }
    }
    for(int u=1; u<8; u++)
    {
        printf("%d\n", newb[u]);
    }
    return 0;
}
