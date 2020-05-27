#include <iostream>
#define SIZE 10001
using namespace std;

class MyQueue {
    private : int data[SIZE];
              int qfront;
              int qback;
              int warn;
    public :
        MyQueue(){
            qfront=0;
            qback=0;
            warn=0;
        }

        void push(int x) {
            if(warn == 1) {
                printf("already full\n");
                return;
            }
            data[qback] = x;
            int t=1;
            if(qfront == qback) t=0;

            if(qback == SIZE-1) qback = 0;
            else qback++;

            if(t==1 && qfront == qback) warn=1;
        }

        void pop(){
            if(warn ==0 && qfront == qback) printf("-1\n");
            else {
                    printf("%d\n", data[qfront]);
                    data[qfront] = -1;
                    if(qfront == SIZE-1) qfront =0;
                    else qfront++;
                    warn = 0;
            }
        }

        void sizeofqueue(){
            if(warn ==0 && qfront == qback) printf("0\n");
            else if(qfront<qback) printf("%d\n", qback-qfront);
            else printf("%d\n", qback-qfront+SIZE);
        }

        void isempty(){
            if(warn ==0 && qfront==qback) printf("1\n");
            else printf("0\n");
        }

        void myfront(){
            if(warn==0 && qfront == qback) printf("-1\n");
            else printf("%d\n", data[qfront]);
        }

        void myback(){
            if(warn==0 && qfront == qback) printf("-1\n");
            else printf("%d\n", data[qback-1]);
        }

};
int main()
{
    int n;
    scanf("%d", &n);
    MyQueue q = MyQueue();

    while(n--){
        char s[100];
        scanf(" %[^\n]s", s);
        char k[20];
        if(s[0]=='p' && s[1]=='u'){
            int siz = 0;
            while(s[siz]!='\0'){
                siz++;
            }
            for(int i=5; i<siz; i++){
                k[i-5] = s[i];
            }
            int x = atoi(k);
            q.push(x);
        }
        else if(s[0]=='p' && s[1]=='o'){
            q.pop();
        }
        else if(s[0]=='s'){
            q.sizeofqueue();
        }
        else if(s[0]=='e'){
            q.isempty();
        }
        else if(s[0]=='f'){
            q.myfront();
        }
        else if(s[0]=='b'){
            q.myback();
        }

        for(int j=0; j<20; j++)
            k[j]='\0';
    }
    return 0;
}
