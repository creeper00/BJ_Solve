#include <iostream>

using namespace std;
int arr[1000001];
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
        if(arr[j]==0) printf("%d\n", j);
    }
    return 0;
}
