#include <iostream>

using namespace std;
int wine[10002];
int save[10002];
int cal(int t)
{
    if(t==0) return 0;
    else if(t==1) return wine[1];
    else if(t==2) return wine[1]+wine[2];
    else
    {
        if(save[t]>0) save[t];
        else
        {
            if(cal(t-3)+wine[t-1]+wine[t]>save[t]) save[t]=cal(t-3)+wine[t-1]+wine[t];
            if(cal(t-2)+wine[t]>save[t]) save[t]=cal(t-2)+wine[t];
            if(t-4>0 && cal(t-4)+wine[t-1]+wine[t]>save[t]) save[t]=cal(t-4)+wine[t-1]+wine[t];
            return save[t];
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d", &wine[i]);
    }
    if(cal(t)>cal(t-1)) printf("%d", cal(t));
    else printf("%d", cal(t-1));
    return 0;
}
