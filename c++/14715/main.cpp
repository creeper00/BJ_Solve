#include <iostream>
#include <vector>
using namespace std;
int save[1000001];
vector <int> v;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=2; i<=n; i++)
    {
        if(save[i]==1) continue;
        else
        {
            int a=2;
            while(a*i<=n)
            {
                save[a*i]=1;
                a++;
            }
        }
    }
    for(int i=2; i<=n; i++)
        if(!save[i]) v.push_back(i);
    int sum=0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]==n) continue;
        int a=0,b=n,c=v[i];
        while(b/c!=0 && b%c==0)
        {
            a++;
            b=b/c;
        }
        sum+=a;
    }
    int ans=0;
    while(sum>1)
    {
        if(sum%2!=0) sum++;
        sum=sum/2;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
