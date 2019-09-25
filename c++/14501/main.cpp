#include <iostream>

using namespace std;

int save[17][2];
int sum,n;
int cal(int t)
{
    if(t>n) return 0;
    int temp=0;
    for(int i=t; i<=n; i++)
        if( (save[i][1]+cal(i+save[i][0]))>temp && (i+save[i][0])<=n+1) temp=save[i][1]+cal(i+save[i][0]);
    return temp;
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int a,b;
        scanf("%d %d", &a,&b);
        save[i][0]=a, save[i][1]=b;
    }
    for(int i=1; i<=n; i++)
        if( (cal(save[i][0]+i)+save[i][1])>sum && (i+save[i][0])<=n+1 ) sum=cal(save[i][0]+i)+save[i][1];
    printf("%d", sum);
    return 0;
}
