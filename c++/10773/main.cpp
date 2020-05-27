#include <iostream>
#include <stack>
using namespace std;
stack <int> st;
int main()
{
    int n,ans=0;
    scanf("%d", &n);
    while(n){
        n--;
        int m;
        scanf("%d", &m);
        if(m!=0) st.push(m);
        else if(m==0 && !st.empty()) st.pop();
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    printf("%d", ans);
    return 0;
}
