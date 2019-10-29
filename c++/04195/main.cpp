#include <iostream>
#include <map>

using namespace std;
int p[200001];
int ssize[200001];
map <string, int> mp;

int parent(int i)
{
    if(p[i]==i) return i;
    else return p[i]=parent(p[i]);
}

int setp (int i, int j)
{
    int pi=parent(i);
    int pj=parent(j);
    if(pi!=pj) { p[pi]=pj; ssize[pj]=ssize[pi]+ssize[pj]; }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int m, e=1;
        cin >> m;
        for(int i=0; i<m; i++)
        {
            string a, b;
            cin>>a>>b;
            if(!mp[a]) { mp[a]=e; ssize[mp[a]]=1; p[e]=e; e++; }
            if(!mp[b]) { mp[b]=e; ssize[mp[b]]=1; p[e]=e; e++; }
            setp(mp[a], mp[b]);
            printf("%d\n", ssize[parent(mp[b])]);
        }
        for(int i=1; i<=mp.size(); i++)
            p[i]=0;
        mp.clear();
    }
    return 0;
}
