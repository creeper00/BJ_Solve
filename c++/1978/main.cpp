#include <iostream>

using namespace std;

int save[100];
int ans;
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &save[i]);
    }
    for(int i=0; i<t; i++)
    {
        int sum=0;
        if(save[i]==1) continue;
        for(int j=save[i]-1; j>1; j--)
        {
            if(save[i]%j==0) {sum++; break;}
        }
        if(sum==0) ans++;
    }
    printf("%d", ans);
    return 0;
}
