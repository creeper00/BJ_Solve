#include <iostream>
#include <map>

using namespace std;

map<string,int> m;

char str[10001];

int cal(int a, int b, double check)
{
        int e=(b-a+1);
    for(int i=1; i<=e/2; i++)
    {
        double t=(double) i/e;
        if( 2*t<=check ) continue;
        else
        {
            int checker=0;
            for(int j=0; j<i; j++)
            {
                if(str[j+a-1]==str[b-j-1]) continue;
                else {checker=1; break;}
            }
            if(checker==0)  return 1;
            else return 0;
        }
    }
    return 0;
}


int pp(int c, int t, double check, string s)
{
    string sub2=s.substr(c-1,t-c+1);
    if(m[sub2]!=0) { return m[sub2];}
    int dep=1;
    int a=0;
    for(int i=1; i<=t; i++)
    {
        if(str[c-1]!=str[t-i]) continue;
        a=cal(c,t+1-i,check);
        if(i==2) continue;
        if(i<2 && a==1)
        {
            string sub=s.substr(c-1,t+2-c-i);
            m.insert(make_pair(sub,dep));
            return dep;
        }
        else
        {
            if(a==1 && i>2)
            {
                string sub4=s.substr(c-1,t+2-c-i);
                m.insert(make_pair(sub4,dep));
                if(pp(t+2-i,t,check,s))
                {
                    int g=pp(t+2-i,t,check,s);
                    string sub3=s.substr(c-1,t-c+1);
                    m.insert(make_pair(sub3,dep+g));
                    return dep+g;
                }
            }
        }
    }
    if(a==0)dep--;
    return dep;
}
int main()
{
    int n;
    int k,l;
    scanf("%d %d %d", &n, &k, &l);
    scanf("%s", str);
    double check=(double) k/l;
    string s(str);
    printf("%d", pp(1,n,check,s));
    return 0;
}
