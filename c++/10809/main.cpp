#include <iostream>

using namespace std;

int main()
{
    char arr[100];
    int alpha[26];
    scanf("%s", arr);
    int t=0;
    for(int i=0; i<26; i++)
        alpha[i]=-1;
    while(arr[t]!='\0')
    {
        int num=arr[t]-'a';
        if(alpha[num]==-1) alpha[num]=t;
        t++;
    }
    for(int i=0; i<26; i++)
        printf("%d ", alpha[i]);
    return 0;
}
