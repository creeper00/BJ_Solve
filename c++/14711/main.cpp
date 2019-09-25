#include <iostream>

using namespace std;
int cal[1001][1001];
int save[1001];
int preve[1001];
int n;
void print(int i);
void change(int c)
{
    for(int j=1; j<=n; j++)
    {
        if(cal[c-1][j]==1) cal[c][j]=1;
        else cal[c][j]=-1;
    }
}
void check(int i)
{
    for(int j=1; j<=n; j++)
    {
        if(cal[i][j]==1) save[j]=1;
        else save[j]=0;
    }
}
void tile(int i)
{
    for(int j=1; j<=n; j++)
    {
        if(save[j]==0) continue;
        else
        {
            if(j-1>0)
            {
                if(cal[i][j-1]==1) cal[i][j-1]=-1;
                else cal[i][j-1]=1;
            }
            if(j<n)
            {
                if(cal[i][j+1]==1) cal[i][j+1]=-1;
                else cal[i][j+1]=1;
            }
            if(cal[i][j]==1) cal[i][j]=-1;
            else cal[i][j]=1;
        }
    }
}
void prevchange(int i)
{
    for(int j=1; j<=n; j++)
    {
        if(preve[j]==1)
        {
            if(cal[i][j]==1) cal[i][j]=-1;
            else cal[i][j]=1;
        }
    }
}
void print(int i)
{
    for(int j=1; j<=n; j++)
        {
            if(cal[i][j]==-1) printf(".");
            else printf("#");
        }
        printf("\n");
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        char a;
        scanf(" %c", &a);
        if(a=='.') cal[1][i]=-1;
        else if(a=='#') cal[1][i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(i>1) {change(i);}
        print(i);
        check(i);
        if(i>1) {prevchange(i);}
        for(int j=1; j<=n; j++)
        {
            if(save[j]==1) preve[j]=1;
            else preve[j]=0;
        }
        tile(i);
    }
    return 0;
}
