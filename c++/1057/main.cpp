#include <iostream>

using namespace std;
int save[100001];
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i=1; i<=n; i++)
    {
        save[i]=i;
    }
    int sum=1;
    while(1)
    {
        for(int i=1; i<=n; i=i+2)
        {
            if(i==n && i%2==1) save[(i+1)/2]=save[i];
            else if( (save[i]==a && save[i+1]==b) || (save[i]==b && save[i+1]==a) ) {printf("%d", sum); return 0;}
            else if(save[i]==a) save[i/2+1]=a;
            else if(save[i+1]==a) save[(i+1)/2]=a;
            else if(save[i]==b) save[i/2+1]=b;
            else if(save[i+1]==b) save[(i+1)/2]=b;
            else save[i/2+1]=save[i];
        }
        sum++;
        if(n%2==0) n=n/2;
        else n=n/2+1;
    }
    return 0;
}
