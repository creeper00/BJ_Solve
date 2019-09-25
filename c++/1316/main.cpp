#include <stdio.h>
#include <string.h>

char arr[100];
int check()
{
    int i=0;
    while(arr[i]!='\0')
    {
        if(arr[i]!=arr[i+1])
        {
            int j=i+1;
            while(arr[j]!='\0')
            {
                if(arr[i]==arr[j]) return 0;
                j++;
            }
        }
        i++;
    }
    return 1;
}
int main()
{
    int n,sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int i=0; i<100; i++)
            arr[i]=0;
        scanf("%s", arr);
        sum+=check();
    }
    printf("%d", sum);
    return 0;
}
