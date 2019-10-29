#include <iostream>
#include <queue>
using namespace std;
priority_queue <int, vector<int>, greater<int>> q;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        if(a==0)
        {
            if(!q.size()) printf("0\n");
            else  { printf("%d\n", q.top()); q.pop();}
        }
        else q.push(a);
    }
    return 0;
}
