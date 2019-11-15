#include <iostream>
#include <algorithm>
using namespace std;
bool cmp ( const pair<int, string> &a,const pair<int, string> &b){
    return a.first < b.first;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    pair<int, string> arr[n];
    for(int i=0; i<n; i++){
        int a;
        string b;
        cin >> a >>b;
        arr[i] = pair<int ,string> (a,b);
    }
    stable_sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++)
        cout << arr[i].first <<" "<< arr[i].second <<"\n";
    return 0;
}


