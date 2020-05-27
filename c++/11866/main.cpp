#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

int main()
{
    int n,k,a;
    scanf("%d %d", &n, &k);
    a=k;
    for(int i=1; i<=n; i++)
        q.push(i);
    printf("<");
    while(q.size()!=1){
        a--;
        if(a==0){
            printf("%d, ", q.front());
            q.pop();
            a=k;
        }
        else {
            int l = q.front();
            q.pop();
            q.push(l);
        }
    }
    printf("%d>", q.front());
    return 0;
}
