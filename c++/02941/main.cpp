#include <iostream>

using namespace std;
char arr[100];
int main()
{
    scanf("%s", arr);
    int i=0;
    int sum=0;
    while(arr[i]!='\0')
    {
        if(arr[i]=='c' && arr[i+1]=='=') sum++,i++;
        else if(arr[i]=='c' && arr[i+1]=='-' ) sum++, i++;
        else if(arr[i]=='d' && arr[i+1]=='z' && arr[i+2]=='=' ) sum++, i=i+2;
        else if(arr[i]=='d' && arr[i+1]=='-' ) sum++, i++;
        else if(arr[i]=='l' && arr[i+1]=='j' ) sum++, i++;
        else if(arr[i]=='n' && arr[i+1]=='j' ) sum++, i++;
        else if(arr[i]=='s' && arr[i+1]=='=' ) sum++, i++;
        else if(arr[i]=='z' && arr[i+1]=='=' ) sum++, i++;
        else sum++;
        i++;
    }
    printf("%d", sum);
    return 0;
}
