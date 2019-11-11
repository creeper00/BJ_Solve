#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int ans[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int mid=1;
    while(mid<n){
        for(int i=0; i<n; i=(i+mid*2)){
            int a=0, b=0,c;
            if( (i+mid*2)<n ) c=i+mid*2;
            else c=n;
            for(int j=i; j<c; j++){
                if( (i+mid+b)>=n ) {ans[j]=arr[i+a]; a++; }
                else if( a>=mid ) { ans[j]=arr[i+mid+b]; b++; }
                else if(b>=mid) { ans[j]=arr[i+a]; a++; }
                else if(arr[i+a] > arr[i+mid+b]) { ans[j]=arr[i+mid+b]; b++; }
                else { ans[j]=arr[i+a]; a++;}
            }
        }
        for(int i=0; i<n; i++){
            arr[i]=ans[i];
        }
        mid=mid*2;
    }
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}
