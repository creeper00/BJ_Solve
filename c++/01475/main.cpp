#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int ar[10];

int main()
{
    char arr[7];
    scanf("%s",arr);
    int n=strlen(arr);
    for(int i=0; i<n; i++)
    {
        if(arr[i]=='0') ar[0]++;
        else if(arr[i]=='1') ar[1]++;
        else if(arr[i]=='2') ar[2]++;
        else if(arr[i]=='3') ar[3]++;
        else if(arr[i]=='4') ar[4]++;
        else if(arr[i]=='5') ar[5]++;
        else if(arr[i]=='6'|| arr[i]=='9') ar[6]++;
        else if(arr[i]=='7') ar[7]++;
        else if(arr[i]=='8') ar[8]++;
    }
    ar[6]=ar[6]-ar[6]/2;
    sort(ar, ar+10);
    printf("%d", ar[9]);
    return 0;
}
