#include <stdio.h>

int main(){
    int **p;
    int *b;
    int a=2;
    b=&a;
    p=&b;
    printf("%d %d", **p, *b);
}
