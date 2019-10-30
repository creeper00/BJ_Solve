#include <iostream>

using namespace std;
int arr[10001];
int main()
{
    arr[1]=1;
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    int i=2;
    while(i<=b){
        if(arr[i]==1) i++;
        else {
            int j=2;
            while(i*j<=b){
                arr[i*j]=1;
                j++;
            }
            i++;
        }
    }
    i=0;
    int sum=0,mini=0;
    for(int j=a; j<=b; j++){
        if(arr[j]==0) {
            if(i==0) { mini=j,i=1;}
            sum+=j;
        }
    }
    if(mini==0) printf("-1");
    else printf("%d\n%d\n", sum,mini);
    return 0;
}
