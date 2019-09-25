#include <iostream>

using namespace std;
unsigned int a=0;
int data[31];
int flag[31];

void powerset(int n,int depth)
{
    if(n==depth){
        int l=0;
        for(int i=0;i<n;i++){
            if(flag[i]==1) l=l+data[i];
        }
        a=a^l;
        return;
    }
    flag[depth]=1;
    powerset(n,depth+1);
    flag[depth]=0;
    powerset(n,depth+1);
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }
    powerset(n,0);
    printf("%d",a);
    return 0;
}
