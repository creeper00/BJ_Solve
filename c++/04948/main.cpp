#include <iostream>

using namespace std;
int save[246912];
int main()
{
    for(int i=1; i<=246912; i++)
    {
        save[i]=i;
    }
    while(1)
    {
        int n;
        scanf("%d", &n);
        if(n==0) break;
        for(int i=2; i<=2*n; i++)
        {
            if(save[i]==0) continue;
            else
            {
                for(int j=i*2; j<=2*n; j=j+i)
                    save[j]=0;
            }
        }
        int sum=0;
        for(int i=n+1; i<=2*n; i++)
        {
            if(save[i]!=0) sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
