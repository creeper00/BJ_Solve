#include <iostream>
#include <math.h>

using namespace std;
int n,a,b;
int save[256][256];
int p;
void cal(int t, int x ,int y)
{
    if(t==1)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                save[x+i][y+j]=p;
                p++;
            }
        }
    }
    else
    {
        int l=(int)pow(2.0, (double)t-1.0);
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                cal(t-1, x+i*l, y+j*l);
            }
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &a, &b);
    if(n<9)
    {
        cal(n,0,0);
        printf("%d", save[a][b]);
    }
    else
    {
        cal(8,0,0);
        int d=save[255][255];
        d++;
        long long int dd;
        int n1=0;
        while(a>=256)
        {
            a-=256;
            n1++;
        }
        int n2=0;
        while(b>=256)
        {
            b-=256;
            n2++;
        }
        dd=d*(save[n1][n2])+save[a][b];
        printf("%lld", dd);

    }
    return 0;
}
