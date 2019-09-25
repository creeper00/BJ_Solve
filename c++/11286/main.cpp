#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
struct comp
{
    bool operator() (int i, int j)
    {
        if(abs(i)==abs(j)) return i>j;
        else return abs(i) > abs(j);
    }
};
priority_queue <int, vector<int>, comp> q;
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
