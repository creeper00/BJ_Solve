#include <iostream>
#include <queue>

using namespace std;

priority_queue <long int, vector<long int>, greater<long int>> q;

int main()
{
    int n,m;
    long int sum=0;
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++)
    {
        long int a;
        scanf("%ld", &a);
        q.push(a);
    }
    for(int i=0; i<m; i++)
    {
        long int b=q.top();
        q.pop();
        long int c=q.top();
        q.pop();
        q.push(b+c);
        q.push(b+c);
    }
    int s=q.size();
    for(int i=0; i<s; i++)
    {
        sum+=q.top();
        q.pop();
    }
    printf("%ld", sum);
    return 0;
}
