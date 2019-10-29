#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int m,n,x,y;
        scanf("%d %d %d %d", &m,&n,&x,&y);
        while(1){
            if(x>(m*n) || y>(m*n)) {
                printf("-1\n");
                break;
            }
            else if(x==y) {
                printf("%d\n",x);
                break;
            }
            else if(x<y) x=x+m;
            else y=y+n;
        }
    }
    return 0;
}
