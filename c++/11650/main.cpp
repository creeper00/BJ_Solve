#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int,int>> v;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        v.push_back(pair<int,int>(a,b));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
        printf("%d %d\n", v[i].first, v[i].second);
    return 0;
}
