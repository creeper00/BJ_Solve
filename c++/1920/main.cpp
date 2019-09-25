#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main()
{
    int n,m;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        s.insert(a);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int b;
        scanf("%d", &b);
        printf("%d\n", s.count(b));
    }
    return 0;
}
