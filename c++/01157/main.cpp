#include <iostream>

using namespace std;
char arr[1000001];
int save[26];
int main()
{
    scanf("%s", arr);
    int t=0;
    while(arr[t]!='\0')
    {
        if(arr[t]>='a') save[arr[t]-'a']++;
        else save[arr[t]-'A']++;
        t++;
    }
    int ans=0;
    int seq=1;
    for(int i=0; i<=25; i++)
    {
        if(i==0) ans=0, seq=1;
        else if(save[i]>save[ans]) seq=1, ans=i;
        else if(save[i]==save[ans]) seq++;
        else continue;
    }
    if(seq>1) printf("?");
    else printf("%c", ans+'A');
    return 0;
}
