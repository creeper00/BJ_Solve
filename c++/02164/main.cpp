#include <iostream>
#include<queue>
using namespace std;
queue <int> q1;
queue <int> q2;
int main()
{
    int n,l=0,m=0;
    scanf("%d", &n);
    if(n==1) {
        printf("%d", n);
        return 0;
    }
    for(int i=1; i<=n; i++){
        q1.push(i);
    }
    while(q1.size()!=1 && q2.size()!=1){
        if(l==0){
            while(!q1.empty()){
                if(m==0) {m++; q1.pop();}
                if(!q1.empty() && m==1) { q2.push(q1.front()); q1.pop(); m=0;}
            }
        }
        else{
            while(!q2.empty()){
                if(m==0) {m++; q2.pop();}
                if(!q2.empty() && m==1) { q1.push(q2.front()); q2.pop();}
            }
        }
        l = (l+1)%2;
    }
    if(q1.empty()) printf("%d", q2.front());
    else printf("%d", q1.front());
    return 0;
}
