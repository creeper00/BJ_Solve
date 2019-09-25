#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n,c;
    char arr[11];
    scanf("%s", arr);
    string s=arr;
    int siz=strlen(arr);
    scanf("%d", &n);
    string a,b;
    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            a=to_string(i);
            b=to_string(j);
            s.replace(siz-2, 1, a);
            s.replace(siz-1, 1, b);
            c=stoi(s);
            if(c%n==0) break;
        }
        if(c%n==0) break;
    }
    cout << a << b;
    return 0;
}
