#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[2000000];
    scanf("%[^\n]", input);
    int a = strlen(input);
    int cnt=1;
    for(int i=0; i<a; i++)
    {
        if(input[i]==' ')
        {
            cnt=cnt+1;

        }
    }
    if(input[0]==' ') cnt=cnt-1;
    if(input[a-1]==' ') cnt=cnt-1;
    cout << cnt << endl;
}
