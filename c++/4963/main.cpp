#include <iostream>

using namespace std;

int save[50][50];
int w,h;
void cal(int a, int b)
{
    for(int i=-1; i<=1; i++)
        for(int j=-1; j<=1; j++)
    if((i!=0 || j!=0) && save[a+i][b+j]>0 && a+i>=0 && a+i<h && b+j>=0 && b+j<w) {save[a+i][b+j]=0, cal(a+i,b+j);}
}
int main()
{
    while(1)
    {
        scanf("%d %d", &w, &h);
        if(w==0 && h==0) break;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            scanf("%d", &save[i][j]);
        }
        int ans=0;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
                if(save[i][j]==1) {cal(i,j), ans++;}
        }
        printf("%d\n", ans);
    }
    return 0;
}
