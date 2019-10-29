#include <iostream>

using namespace std;

int save[90001];

int cal(int t)
{
    if(t==1) return 0;
    else if(t==2) return 1;
    else if(t==3) return 2;
    else if(t==4) return 3;
    else
    {
        if(save[t]>0) return save[t];
        else
        {
            if(t%2==0) save[t]=2*cal(t/2)+1;
            else save[t]=cal(t/2)+cal(t/2+1)+1;
            return save[t];
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    printf("%d", cal(n*m));
    return 0;
}
