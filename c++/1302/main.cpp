#include <iostream>
#include <map>

using namespace std;
map<string,int> m;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    int val=0;
    string ans;
    for(auto pr: m)
    {
        if(pr.second>val) {val=pr.second; ans=pr.first;}
    }
    cout << ans;
    return 0;
}
