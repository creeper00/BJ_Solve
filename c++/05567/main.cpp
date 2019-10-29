#include <iostream>
#include <vector>

using namespace std;
vector<int> v[501];
bool con[501];

void cal(int t)
{
    for(int i=0; i<v[t].size(); i++)
    {
        int z=v[t][i];
        if(!con[z]) con[z]=true;
        for(int j=0; j<v[z].size(); j++)
        {
            if(!con[v[z][j]]) con[v[z][j]]=true;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cal(1);
    int res=0;
    for(int i=2; i<=n; i++)
    {
        if(con[i]) res++;
    }
    printf("%d", res);
    return 0;
}
