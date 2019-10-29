#include <iostream>

using namespace std;

int main()
{
    int e,s,m;
    scanf("%d %d %d", &e, &s, &m);
    int e1=1, s1=1, m1=1;
    int sum=1;
    while(e1!=e || s1!=s || m1!=m)
    {
        sum++;
        e1++, s1++, m1++;
        if(e1>15) e1=1;
        if(s1>28) s1=1;
        if(m1>19) m1=1;
    }
    printf("%d", sum);
    return 0;
}
