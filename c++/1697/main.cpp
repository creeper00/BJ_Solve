#include <iostream>
#include <queue>

using namespace std;
int save[100001];
queue <int> q;

int main()
{
    int v,m,res=0;
    scanf("%d %d", &v,&m);
    q.push(v);
    while(1)
    {
        int l=q.size();
        for(int i=0; i<l; i++)
        {
            v=q.front();
            q.pop();
            if(v==m) {printf("%d", res); return 0;}
            if(v-1>=0 && save[v-1]==0) {save[v-1]=1; q.push(v-1);}
            if(v+1<=100000 && save[v+1]==0) {save[v+1]=1; q.push(v+1);}
            if(v*2<=100000 && save[v*2]==0) {save[v*2]=1; q.push(v*2);}
        }
        res++;
    }
    return 0;
}
