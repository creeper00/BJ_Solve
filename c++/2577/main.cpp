#include <iostream>
#include <cstring>
using namespace std;
char save[20];
int temp[10];
int main()
{
    int a,b,c,n;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    n=a*b*c;
    string s=to_string(n);
    strcpy(save,s.c_str());
    for(int i=0; i<strlen(save); i++)
        temp[save[i]-'0']++;

    for(int i=0; i<=9; i++)
        printf("%d\n", temp[i]);

    return 0;
}
