#include <iostream>

using namespace std;
int arr[15];
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int a,b;
        scanf("%d", &a);
        scanf("%d", &b);
        for(int j=0; j<=a; j++)
        {
            for(int l=1; l<=b; l++)
            {
                if(j==0) arr[l]=l;
                else if(l!=1) arr[l]=arr[l-1]+arr[l];
            }
        }
        printf("%d\n", arr[b]);
    }
    return 0;
}
