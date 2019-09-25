#include <iostream>

using namespace std;

int main()
{
    int x;
    int sum=0;
    scanf("%d", &x);
    while(x>1)
    {
        if(x%2==1)
        {
            x=x/2;
            sum++;
        }
        else {x=x/2; continue;}
    }
    printf("%d", sum+1);

    return 0;
}
