#include <iostream>
#include <algorithm>
using namespace std;

int save[1000001];


int main()
{
    int t;
    scanf("%d", &t);
    for(int i=t; i>1; i--)
    {
        if(i%2==0 && (save[i/2]> save[i]+1 || save[i/2]==0)) save[i/2]=save[i]+1;
        if(i%3==0 && save[i/3]==0) save[i/3]=save[i]+1;
        if(save[i-1]>save[i]+1 || save[i-1]==0) save[i-1]=save[i]+1;
    }
    printf("%d", save[1]);
    return 0;
}

