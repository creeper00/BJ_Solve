#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
char arr[11];
int save[11];
int main()
{
    int i=0;
    scanf("%s", arr);
    while(arr[i]!='\0'){
        save[i]=(int) arr[i] - '0';
        i++;
    }
    sort(save, save+i);
    for(int j=(i-1); j>=0; j--)
        printf("%d", save[j]);
    return 0;
}
