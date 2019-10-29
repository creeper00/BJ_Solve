#include <iostream>
#include <vector>
using namespace std;

vector<int> v[51];
int save[51][51];
int n;

void cal(int t)
{
    for(int i=0; i<v[t].size(); i++)
    {
        if(!save[t][v[t][i]]) save[t][v[t][i]]=1;
        for(int j=1; j<=n; j++)
        {
            if(j==t) continue;
            for(int l=0; l<v[j].size(); l++)
            {
                if(v[j][l]==v[t][i] && save[t][j]!=1) {save[t][j]=1; break;}
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        char temp[n+1];
        scanf("%s", temp);
        for(int j=0; j<n; j++)
            if(temp[j]=='Y') {v[i].push_back(j+1);}
    }
    for(int i=1; i<=n; i++)
        cal(i);
    int sum=0, res=0;
    for(int i=1; i<=n; i++)
    {
        res=0;
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            if(save[i][j]) res++;
        }
        if(res>sum) sum=res;
    }
    printf("%d", sum);
    return 0;
}
