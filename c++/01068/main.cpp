#include <iostream>
#include <vector>

using namespace std;
vector <int> save[50];

void cal(int n)
{
    while(!save[n].empty())
    {
        int v=save[n].size();
        cal(save[n][v-1]);
        save[n].pop_back();
    }
    save[n].push_back(-1);
}
int main()
{
    int t,n,temp,ans=0;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &temp);
        if(temp==-1) continue;
        save[temp].push_back(i);
    }
    scanf("%d", &n);
    cal(n);
    for(int i=0; i<t; i++)
    {
        if(save[i].empty() || (save[i][0]==n && save[i].size()==1)) ans++;
    }
    printf("%d", ans);
    return 0;
}
