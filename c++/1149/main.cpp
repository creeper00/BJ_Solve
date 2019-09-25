#include <stdio.h>

using namespace std;

int con1(int t);
int con2(int t);

int price[1001][3];
int save[1001][3];

int cal(int t, int n)
{
    if(t==1) return price[1][n];
    else
    {
        if(save[t][n]>0) return save[t][n];
        else
        {
            if(save[t][n]==0 || cal(t-1, con1(n))+price[t][n]<=save[t][n]) save[t][n]=cal(t-1,con1(n))+price[t][n];
            if(save[t][n]==0 || cal(t-1, con2(n))+price[t][n]<=save[t][n]) save[t][n]=cal(t-1,con2(n))+price[t][n];
            return save[t][n];
        }
    }
}

int con1 (int t)
{
    if(t==0) return 1;
    else if(t==1) return 2;
    else return 0;
}
int con2 (int t)
{
    if(t==0) return 2;
    else if(t==1) return 0;
    else return 1;
}

int mini(int a, int b, int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d %d %d", &price[i][0],&price[i][1],&price[i][2]);
    }
    int a=cal(t,0);
    for(int i=1; i<=t; i++)
    {
        save[i][0]=0;
        save[i][1]=0;
        save[i][2]=0;
    }
    int b=cal(t,1);
    for(int i=1; i<=t; i++)
    {
        save[i][0]=0;
        save[i][1]=0;
        save[i][2]=0;
    }
    int c=cal(t,2);
    printf("%d", mini(a,b,c));

}
