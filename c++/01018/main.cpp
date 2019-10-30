#include <iostream>

using namespace std;
char arr[51][51];
char ar[8][8];
void change(int a, int b){
    if(ar[a][b]=='W') ar[a][b]='B';
    else ar[a][b]='W';
}
int checker(int a, int b){
    int ans=0;
    for(int i=a; i<(a+8); i++){
        for(int j=b; j<(b+8); j++){
            ar[i-a][j-b]=arr[i][j];
        }
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i!=7 && ar[i][j]==ar[i+1][j]) change(i+1,j), ans++;
            if(j!=7 && ar[i][j]==ar[i][j+1] ) change(i,j+1), ans++;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    int sum=-1;
    for(int i=0; i<(n-7); i++){
        for(int j=0; j<(m-7); j++){
                int temp = checker(i,j);
                if(temp>32) temp=64-temp;
                if(sum>temp) sum=temp;
                if(sum==(-1) ) sum=temp;
        }
    }
    printf("%d", sum);
    return 0;
}
