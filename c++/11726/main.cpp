#include <iostream>

using namespace std;

int save[1000];

int cal(int t)
{
    if(t==0) return 1;
    if(t==1) return 2;
    else
    {
        if(save[t]>0) return save[t];
        else
        {
            save[t]=(cal(t-1)+cal(t-2))%10007;
            return save[t];
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    printf("%d", cal(t-1)%10007);
    return 0;
}
