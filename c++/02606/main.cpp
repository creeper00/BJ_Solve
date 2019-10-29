#include <iostream>
#include <vector>

using namespace std;

vector <int> v[101];
int save[101];

void cal(int t)
{
    if(!save[t]) save[t]=1;
    for(int i=0; i<v[t].size(); i++)
    {
        if(!save[v[t][i]]) cal(v[t][i]);
    }
}
int main()
{
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i=1; i<=k; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cal(1);
    int sum=0;
    for(int i=2; i<=n; i++)
    {
        if(save[i]) sum++;
    }
    printf("%d", sum);
    return 0;
}
