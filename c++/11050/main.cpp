#include <iostream>

using namespace std;

int main()
{
    int a,b,res=1;
    scanf("%d %d", &a,&b);
    if(a==b || a==0 || b==0) printf("1");
    else{
      for(int i=0; i<b; i++){
        res=res*(a-i);
      }
      for(int i=b; i>0; i--){
        res=res/i;
      }
      printf("%d", res);
    }
    return 0;
}
