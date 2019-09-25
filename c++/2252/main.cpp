#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int save[32001];

int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    queue <int> q;
    vector <int> v[32001];
    for(int i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d %d", &a,&b);
        v[a].push_back(b);
        save[b]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(!save[i]) q.push(i);
    }

    while(!q.empty())
    {
        int e=q.front();
        printf("%d ", e);
        q.pop();
        int s=v[e].size();
        for(int i=0; i<s; i++)
        {
            save[v[e][i]]--;
            if(!save[v[e][i]]) q.push(v[e][i]);
        }
    }
    return 0;
}
