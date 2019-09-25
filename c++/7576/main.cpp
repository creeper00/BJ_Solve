#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int save[1001][1001];
queue <int> q;

int initcheck(int n, int m)
{
    for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(save[i][j]==0)
                {
                    int num=0;
                    if( (i-1>0 && save[i-1][j]==-1) || i-1<1) num++;
                    if( (i+1<=m && save[i+1][j]==-1) || i+1>m) num++;
                    if( (j-1>0 && save[i][j-1]==-1) || j-1<1) num++;
                    if( (j+1<=n && save[i][j+1]==-1) || j+1>n) num++;
                    if(num==4) return 1;
                }
            }
        }
        return 0;
}


int main()
{
    int m,n,sub=0;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &save[i][j]);
            if(save[i][j]==1) q.push(n*(i-1)+j);
            if(save[i][j]==-1) sub++;
        }
    }
    int res=0;
    if(initcheck(n,m)) {printf("-1"); return 0;}

    while( !q.empty())
    {
        int e=q.size();
        for(int l=0; l<e; l++)
        {
            int v=q.front();
            q.pop();
            int i=v/n+1;
            if(v%n==0) i--;
            int j=v-(i-1)*n;
            if(save[i][j]==1)
            {
                    if(i-1>0 && save[i-1][j]==0) {save[i-1][j]=1; q.push(n*(i-2)+j);}
                    if(i+1<=m && save[i+1][j]==0) {save[i+1][j]=1; q.push(n*i+j);}
                    if(j-1>0 && save[i][j-1]==0) {save[i][j-1]=1; q.push(n*(i-1)+j-1);}
                    if(j+1<=n && save[i][j+1]==0) {save[i][j+1]=1; q.push(n*(i-1)+j+1);}
            }
        }
        res++;
    }
    printf("%d", res-1);
    return 0;
}
