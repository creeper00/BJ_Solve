#include <iostream>

using namespace std;

int main()
{
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    if(b>a) {
        int temp = a;
        a = b;
        b = temp;
    }
    int n = a, m=b;
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    printf("%d\n", a);
    printf("%d\n", n*m/a);
    return 0;
}
