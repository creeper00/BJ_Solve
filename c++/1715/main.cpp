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
        q.push(a);
    }
    int sum=0;
    while(q.size()!=1)
    {
        int b,c;
        b=q.top();
        q.pop();
        c=q.top();
        q.pop();
        sum=sum+b+c;
        q.push(b+c);
    }
    printf("%d", sum);
    return 0;
}
