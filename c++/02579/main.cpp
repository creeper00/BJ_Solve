#include <iostream>

using namespace std;

int save[301];
int stair[301];
int on=0;
int ender=0;
int cal(int t)
{
    if(t==0) return 0;
    else if(t==1) return stair[1];
    else
    {
        if(save[t]>0) return save[t];
        else {

        if( t>=3 && (cal(t-3)+stair[t]+stair[t-1])>=save[t]) save[t]=(cal(t-3)+stair[t]+stair[t-1]);
        else save[t]=cal(t-1)+stair[t];
        if( (cal(t-2)+stair[t]) >save[t]) save[t]=cal(t-2)+stair[t];
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
        scanf("%d", &stair[i]);
    }
    ender=t;
    printf("%d", cal(t));
    return 0;
}
