#include <iostream>

using namespace std;
int arr[10001];
int main()
{
    arr[1]=1;
    int t,l=2;
    scanf("%d", &t);
    while(l<=10000){
            if(arr[l]==1) l++;
            else {
                int m=2;
                while(l*m<=10000){
                    arr[l*m]=1;
                    m++;
                }
                l++;
            }
        }
    for(int i=0; i<t; i++){
        int a;
        scanf("%d", &a);
        int num1=0,num2=0;
        for(int j=(a/2); j>=2; j--){
            if(arr[j]==0 && arr[a-j]==0) {
                num1=j;
                num2=a-j;
                break;
            }
        }
        printf("%d %d\n", num1,num2);
    }
    return 0;
}
