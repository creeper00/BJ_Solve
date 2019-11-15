#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, [](string &c, string &d)->bool {
           if((int) c.size()== (int) d.size()) return c.compare(d)<0;
           else return (int) c.size()< (int) d.size();
        });
    for(int i=0; i<n; i++){
        if(i!=0 && arr[i].compare(arr[i-1])==0) continue;
        cout << arr[i] << endl;
    }
    return 0;
}
