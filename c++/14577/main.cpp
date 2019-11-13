#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    long long int n,m;
    scanf("%lld %lld", &n, &m);
    vector<long long int> v(n);
    vector<long long int> save(n);
    for(int i=0; i<n; i++){
        long long int temp;
        scanf("%lld", &temp);
        v[i]=temp;
        save[i]=temp;
    }
    vector<long long int>::iterator it0, it1;
    sort(v.begin(), v.end());

    for(int i=0; i<m; i++){
        int a;
        scanf("%d", &a);
        if(a==1){
            long long int b,c;
            scanf(" %lld %lld", &b, &c);
            it0 = lower_bound(v.begin(), v.end(), save[b-1]);
            v.erase(it0);
            save[b-1]+=c;
            it1 = lower_bound(v.begin(), v.end(), save[b-1]);
            v.insert(it1, save[b-1]);
        }
        else if(a==2){
          long long int b,c;
            scanf(" %lld %lld", &b, &c);
            it0 = lower_bound(v.begin(), v.end(), save[b-1]);
            v.erase(it0);
            save[b-1]-=c;
            it1 = lower_bound(v.begin(), v.end(), save[b-1]);
            v.insert(it1, save[b-1]);
        }
        else if(a==3){
            long long int b,c;
            scanf(" %lld %lld", &b, &c);
            it0 = upper_bound(v.begin(), v.end(), c);
            it1 = lower_bound(v.begin(), v.end(), b);
            printf("%d\n",it0-it1);
        }
        else if(a==4){
            int b;
            scanf("%d", &b);
            printf("%lld\n", v[n-b]);
        }
    }
    return 0;
}
