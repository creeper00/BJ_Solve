#include <iostream>
#include <stdlib.h>
using namespace std;

class Mystack {
    private : int data[10001];
              int curr;
    public :
        Mystack(){
            curr = -1;
        }

        void push(int x){
            curr++;
            data[curr] = x;
        }

        void pop(){
            if(curr==-1) printf("-1\n");
            else {
                printf("%d\n", data[curr]);
                curr--;
            }
        }

        void sizeofstack() {
            printf("%d\n", curr+1);
        }

        void isempty(){
            if(curr==-1) printf("1\n");
            else printf("0\n");
        }

        void top(){
            if(curr==-1) printf("-1\n");
            else printf("%d\n", data[curr]);
        }
};


int main()
{
    int n;
    scanf("%d", &n);
    Mystack m = Mystack();
    while(n--){
        char s[100];
        scanf(" %[^\n]s", s);
        char k[20];
        if(s[0]=='p' && s[1]=='u' && s[2]=='s') {
            int siz = 0, num=0;
            while(s[siz] != '\0'){
                siz++;
            }
            for(int j=5; j<siz; j++){
                k[j-5] = s[j];
            }
            int x = atoi(k);
            m.push(x);
        }
        else if(s[0]=='p' && s[1]=='o' && s[2]=='p') {
            m.pop();
        }
        else if(s[0]=='s'){
            m.sizeofstack();
        }
        else if(s[0]=='e'){
            m.isempty();
        }
        else if(s[0]=='t'){
            m.top();
        }

        for(int i=0; i<10; i++)
            k[i]='\0';
    }

    return 0;
}



