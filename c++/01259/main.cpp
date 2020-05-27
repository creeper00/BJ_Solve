#include <iostream>

using namespace std;

int main()
{
    while(1){
        string s,n="";
        cin >> s;
        if(s=="0") break;
        for(int i=s.length()-1; i>=0; i--)
            n+=s[i];
        if(s.compare(n)==0) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
