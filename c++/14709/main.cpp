#include <iostream>
#include <vector>
using namespace std;
vector <int> v[6];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d %d", &a ,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(v[1].size()!=2) { printf("Woof-meow-tweet-squeek"); return 0;}
    else
    {
        for(int i=0; i<2; i++)
        {
            int num = v[1].front();
            if(num == 3 || num ==4) continue;
            else
            {
                printf("Woof-meow-tweet-squeek");
                return 0;
            }
        }
    }
    if(v[3].size()!=2) { printf("Woof-meow-tweet-squeek"); return 0; }
    else
    {
        for(int i=0; i<2; i++)
        {
            int num = v[3].front();
            if(num == 1 || num ==4) continue;
            else
            {
                printf("Woof-meow-tweet-squeek");
                return 0;
            }
        }
    }
    if(v[4].size()!=2) { printf("Woof-meow-tweet-squeek"); return 0; }
    else
    {
        for(int i=0; i<2; i++)
        {
            int num = v[4].front();
            if(num == 3 || num ==1) continue;
            else{ printf("Woof-meow-tweet-squeek"); return 0;}
        }
    }
    printf("Wa-pa-pa-pa-pa-pa-pow!");
    return 0;
}
