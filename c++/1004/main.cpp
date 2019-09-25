#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int start[2], arrive[2];
        scanf("%d %d %d %d", &start[0], &start[1], &arrive[0], &arrive[1]);
        int t;
        int res=0;
        scanf("%d", &t);
        int ar1[t],ar2[t],ar3[t];
        for(int j=0; j<t; j++)
        {
            scanf("%d %d %d", &ar1[j], &ar2[j], &ar3[j]);
            int x=(ar1[j]-start[0])*(ar1[j]-start[0]);
            int y=(ar2[j]-start[1])*(ar2[j]-start[1]);
            int a=(ar1[j]-arrive[0])*(ar1[j]-arrive[0]);
            int b=(ar2[j]-arrive[1])*(ar2[j]-arrive[1]);
            int r=ar3[j]*ar3[j];
            if(x+y<r)
            {
                res++;
                if(a+b<r) res--;
            }
            if(a+b<r)
            {
                    res++;
                    if(x+y<r) res--;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
