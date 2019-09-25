#include <bits/stdc++.h>

using namespace std;
int height[5001];
vector <int> v[5001];
int save[5001];
int n,m;
int cal(int l)
{
    if(save[l]>0) return save[l];
    else
    {
        int sum=0;
        for(int i=0; i<v[l].size(); i++)
        {
            int g = v[l][i];
            if( height[g] >height[l] )
            {
                if( cal(g)> sum ) sum = cal(g);
            }
        }
        return save[l]=sum+1;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &height[i]);
    for(int i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
        printf("%d\n", cal(i));
    return 0;
}
