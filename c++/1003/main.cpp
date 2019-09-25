#include <iostream>

using namespace std;

int zero=0;
int one=0;
int mem[41]={0,1,1,};
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        if(mem[n]>0) return mem[n];
        mem[n]=fibonacci(n-1) + fibonacci(n-2);
        return mem[n];
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    fibonacci(40);
    for(int i=0; i<t; i++)
    {
        zero=0;
        one=0;
        int n;
        scanf("%d", &n);
        if(n==0) zero=1;
        else zero=mem[n-1];
        one=mem[n];
        printf("%d %d\n", zero, one);
    }
    return 0;
}
