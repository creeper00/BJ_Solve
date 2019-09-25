#include <iostream>

using namespace std;

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    if( (a%30)*2*6 == b ) printf("O");
    else printf("X");
    return 0;
}
