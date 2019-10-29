#include <iostream>
#include <queue>
using namespace std;

priority_queue<string, vector<string>, greater<string>> q;
priority_queue<string, vector<string>, greater<string>> ans;
int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        q.push(s);
    }
    for(int i=0; i<m; i++)
    {
        string s;
        cin>>s;
        q.push(s);
    }
    int sum=0;
    string ss=q.top();
    q.pop();
    int v=q.size();
    for(int i=0; i<v; i++)
    {
        string sss=q.top();
        if(ss==sss) sum++,ans.push(sss);
        ss=sss;
        q.pop();
    }
    int w=ans.size();
    cout<<w<<endl;
    for(int i=0; i<w; i++)
    {
        cout<<ans.top()<<endl;
        ans.pop();
    }
    return 0;
}
