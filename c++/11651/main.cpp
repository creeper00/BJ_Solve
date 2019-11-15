#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[100000];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        arr[i]=pair<int,int>(a,b);
    }
    sort(arr, arr+n, [](pair<int, int> &a, pair<int, int> &b)->bool{
         if(a.second == b.second) return a.first <b.first;
         else return a.second < b.second;
    });
    for(int i=0; i<n; i++)
        printf("%d %d\n", arr[i].first, arr[i].second);
    return 0;
}
