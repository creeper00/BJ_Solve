#include <iostream>

using namespace std;

int save[100];
int ans[3];
int main()
{
    int m,n,i;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
    {
        scanf("%d", &save[i]);
    }
    int num=n*(n-1)*(n-2)/3;
    int sum=0;
        for(int a=0; a<n-2; a++)
        {
            for(int b=a+1; b<n-1; b++)
            {
                for(int c=b+1; c<n; c++)
                {
                    if(save[a]+save[b]+save[c]==m)
                    {
                        sum=m;
                        break;
                    }
                    if(save[a]+save[b]+save[c]<m && save[a]+save[b]+save[c]>sum) sum=save[a]+save[b]+save[c];
                }
            }
        }
        printf("%d", sum);

    return 0;
}
