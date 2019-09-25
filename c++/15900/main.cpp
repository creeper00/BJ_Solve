#include <iostream>
#include <vector>

using namespace std;
vector <int> v[500001];
long int sum;
void cal(int t, int n, int m)
{
    int e=v[t].size();
    if(e==1 && t!=1) sum+=n;
    else
    {
        for(int i=0; i<e; i++)
        {
            if(v[t][i]==m) continue;
            else cal(v[t][i], n+1, t);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++)
    {
        int a,b;
        scanf("%d %d", &a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cal(1,0,1);
    if(sum%2==0) printf("No");
    else printf("Yes");
    return 0;
}
