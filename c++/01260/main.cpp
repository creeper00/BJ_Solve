#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> v[1002];
int check[1002];
int check2[1002];
vector <int> d;
queue <int> q;

void dfs(int t)
{
    if(!check[t]) { d.push_back(t); check[t]=1;}
    for(int i=0; i<v[t].size(); i++)
    {
        if(!check[v[t][i]]) dfs(v[t][i]);
    }
}
void bfs(int t)
{
    check2[t]=1;
    q.push(t);
    while(!q.empty())
    {
        int x=q.front();
        for(int i=0; i<v[x].size(); i++)
        {
            if(!check2[v[x][i]]) {check2[v[x][i]]=1; q.push(v[x][i]);}
        }
        d.push_back(q.front());
        q.pop();
    }

}
int main()
{
    int n,m,s;
    scanf("%d %d %d", &n, &m, &s);
    for(int i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d %d", &a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    dfs(s);
    for(int i=0; i<d.size(); i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
    d.clear();
    bfs(s);
    for(int i=0; i<d.size(); i++)
    {
        printf("%d ", d[i]);
    }
    return 0;
}
