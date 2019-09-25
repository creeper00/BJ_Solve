#include <iostream>
#include <vector>

using namespace std;

vector<int> v[2];
int n, b=1, c=1, d=1;
int save[501];
int arr[501][501];
int bosu[501];
int jinbo[501];
int nope[501];
int flag[501];
int sum;
int plussum;
int saver;
void cal(int t)
{
    for(int i=1; i<=v[0].size(); i++)
    {
        for(int j=1; j<=c; j++)
        {
            plussum=plussum+arr[v[0][i]][jinbo[j]];
        }
    }
    for(int i=1; i<=b; i++)
    {
        for(int j=1; j<=v[0].size(); j++)
        {
            if()
        }
    }
}
void powerset(int n,int depth)
{
    if(n==depth){
        int l=0;
        for(int i=1;i<=n;i++){
            if(flag[i]==1) v[0].push_back(nope[i]);
        }
        if(plussum==0 || saver==0|| plussum<saver) saver=plussum;

        return;
    }
    flag[depth]=1;
    powerset(n,depth+1);
    flag[depth]=0;
    powerset(n,depth+1);
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &save[i]);
        if(save[i]==1) {bosu[b]=save[i]; b++;}
        else if(save[i]==2) {jinbo[c]=save[i]; c++;}
        else {nope[d]=save[i]; d++;}
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &arr[i][j]);
    for(int i=1; i<b; i++)
    {
        for(int j=1; j<c; j++)
        {
            sum=sum+arr[bosu[i]][jinbo[j]];
        }
    }
    powerset(d+1,1);
    printf("%d", sum+saver);
    return 0;
}
