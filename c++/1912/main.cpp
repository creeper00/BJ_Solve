#include <iostream>

using namespace std;

int arr[100001];
int save[100001];
int cal(int t)
{
    if(t==1) {save[1]=arr[1]; return arr[1];}
    else
    {
        if(save[t]>0) return save[t];
        else
        {
            if(arr[t]>arr[t]+cal(t-1)) save[t]=arr[t];
            else save[t]=arr[t]+cal(t-1);
            return save[t];
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum=cal(n);
    for(int i=1; i<=n; i++)
    {
        if(save[i]>sum) sum=save[i];
    }
    printf("%d", sum);
    return 0;
}
