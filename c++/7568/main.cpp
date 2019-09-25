#include <iostream>

using namespace std;

int save[51][2];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &save[i][0], &save[i][1]);
    }
    for(int j=0; j<n; j++)
    {
        int num=0;
        for(int l=0; l<n; l++)
        {
            if(save[j][0]<save[l][0] && save[j][1]<save[l][1]) num++;
        }
        printf("%d ", num+1);
    }
    return 0;
}
