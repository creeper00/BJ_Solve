#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q2;
priority_queue <int> q1;
int main()
{
    int n;
    scanf("%d", &n);
    int l=0;
    int a;
    scanf("%d", &a);
    l=a;
    printf("%d\n",l);
    for(int i=2; i<=n; i++)
    {
        scanf("%d", &a);
        if(q1.size()==q2.size())
        {
            if(l>a)
            {
                q1.push(a);
                printf("%d\n",q1.top());
            }
            else
            {
                q1.push(l);
                q2.push(a);
                l=q2.top();
                q2.pop();
                printf("%d\n", q1.top());
            }
        }
        else
        {
            if(l<=a)
            {
                q2.push(a);
                printf("%d\n",l);
            }
            else
            {
                q1.push(a);
                q2.push(l);
                l=q1.top();
                q1.pop();
                printf("%d\n", l);
            }
        }
    }
    return 0;
}
