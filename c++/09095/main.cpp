#include <iostream>

using namespace std;

int save[11]={-1,-1,1,3,7,};

int cal(int n)
{
    int sum=0;
    if (n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    else
    {
        if(save[n]>0) return save[n];
        else return save[n]=cal(n-1)+cal(n-2)+cal(n-3);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", cal(n));
    }
    return 0;
}
