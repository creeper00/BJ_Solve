#include <iostream>

using namespace std;
int arr[26];
char ans[15];
int main()
{
    scanf("%s", ans);
    int t=2;
    for(int i=0; i<26; i++)
    {
        if(t==7 || t==9)
        {
            arr[i]=t;
            arr[i+1]=t;
            arr[i+2]=t;
            arr[i+3]=t;
            i=i+3;
            t++;
        }
        else
        {
            arr[i]=t;
            arr[i+1]=t;
            arr[i+2]=t;
            i=i+2;
            t++;
        }
    }
    int n=0;
    int sum=0;
    while(ans[n]!='\0')
    {
        sum+=arr[ans[n]-'A']+1;
        n++;
    }
    printf("%d", sum);
    return 0;
}
