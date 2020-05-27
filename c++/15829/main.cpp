#include <iostream>

using namespace std;

int main()
{
    int l;
    scanf("%d", &l);
    long long int res = 0;
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        long long int num = s[i]-'a'+1;
        long long int mul = 1;
        for(int j=1; j<=i; j++){
            mul = (mul*31)%1234567891;
        }
        mul = mul % 1234567891;
        res = (res + (num*mul)%1234567891) % 1234567891;
    }
    printf("%lld", res%1234567891);
    return 0;
}
