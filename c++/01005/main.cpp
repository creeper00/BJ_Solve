#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int save[1001];
int time[1001];
int ans[1001];
queue <int> q;
vector <int> v[1001];

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int n,k,f;
        scanf("%d %d", &n, &k);
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &time[j]);
        }
        for(int j=1; j<=k; j++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            save[b]++;
        }
        scanf("%d", &f);
        for(int i=1; i<=n; i++)
        {
            if(!save[i]) { ans[i]=time[i]; q.push(i);}
        }
        while(!q.empty())
        {
            int e=q.front();
            q.pop();
            int s=v[e].size();
            for(int i=0; i<s; i++)
            {
                save[v[e][i]]--;
                if(ans[v[e][i]]==0 || ans[e]+time[v[e][i]]>ans[v[e][i]]) ans[v[e][i]]=ans[e]+time[v[e][i]];
                if(!save[v[e][i]]) q.push(v[e][i]);
            }
        }
        printf("%d\n", ans[f]);
        for(int i=1; i<=n; i++)
        {
            save[i]=0;
            ans[i]=0;
            time[i]=0;
            v[i].clear();
        }
    }
}
