#include <iostream>
#include <algorithm>
using namespace std;
int searcher(int *arr, int n, int siz);

int main()
{
    int n,m;
    scanf("%d", &n);
    int arr1[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr1[i]);
    scanf("%d", &m);
    int arr2[m];
    for(int j=0; j<m; j++)
        scanf("%d", &arr2[j]);
    sort(arr1, arr1+n);
    for(int i=0; i<m; i++){
        printf("%d ", searcher(arr1, arr2[i], n));
    }
    return 0;
}

int searcher(int *arr, int n, int siz){
    int h = siz;
    int l = 0;
    int m = (h+l)/2;
    int a1=0, a2=0;

    while(h>l){
        m = (h+l)/2;
       if(arr[m]<n) l = m+1;
       else h = m;
    }
    a1 = h+1;
    h =siz;
    l=0;
    while(h>l){
        m = (h+l)/2;
        if(arr[m]<=n) l = m+1;
        else h = m;
    }
    a2 = h+1;
    return a2-a1;
}
