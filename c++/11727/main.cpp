#include <iostream>

using namespace std;
int save[1001];
int cal(int t)
{
    if(t==1) return 1;
    else if(t==2) return 3;
    else
    {
        if(save[t]>0) return save[t];
        else
        {
            save[t]=(cal(t-1)+cal(t-2)*2)%10007;
            return save[t];
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d",cal(n));
    return 0;
}
