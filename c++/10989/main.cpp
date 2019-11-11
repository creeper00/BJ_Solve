#include <iostream>

using namespace std;
int arr[10001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d", &a);
        arr[a]++;
    }
    for(int i=1; i<=10000; i++){
        while(arr[i]!=0){
            printf("%d\n", i);
            arr[i]--;
        }
    }
    return 0;
}
