#include <iostream>
#define SIZE 10000
using namespace std;

class MyDeque{
private :
    int data[SIZE+1];
    int myfront, myback;

public :
    MyDeque(){
        myfront=0;
        myback=0;
    }
    void pushback(int x){
        int ret = myback;

        if(myback == SIZE) myback=0;
        else myback++;
        if(myback == myfront) {
                printf("deque full\n");
                myback = ret;
        }
        else data[myback] = x;
    }
    void pushfront(int x){
        int ret = myfront;

        if(myfront == 0) myfront=SIZE;
        else myfront--;
        if(myback == myfront) {
                printf("deque full\n");
                myfront = ret;
        }
        else data[ret] = x;
    }
    void popback(){
        if(myback == myfront) printf("-1\n");
        else {
            int t = myback;
            if(t==0) t=SIZE;
            else t--;;
            printf("%d\n", data[myback]);
            myback = t;
        }
    }
    void popfront(){
        if(myback == myfront) printf("-1\n");
        else {
            int t = myfront;
            if(t==SIZE) t=0;
            else t++;
            printf("%d\n", data[t]);
            myfront = t;
        }
    }
    void sizeofdeque(){
        if(myback == myfront) {
                printf("0\n");
                return;
        }
        int siz = myback-myfront;
        if(siz<0) printf("%d\n", siz+SIZE+1);
        else printf("%d\n", siz);
    }
    void isempty(){
        if(myback == myfront) printf("1\n");
        else printf("0\n");
    }
    void dfront(){
        if(myback == myfront) printf("-1\n");
        else {
            int t = myfront;
            if(t==SIZE) t=0;
            else t++;
            printf("%d\n", data[t]);
        }
    }
    void dback(){
        if(myback == myfront) printf("-1\n");
        else {
            printf("%d\n", data[myback]);
        }
    }
};
int main()
{
    int n;
    MyDeque d = MyDeque();
    scanf("%d", &n);

    while(n--){
        char s[100];
        scanf(" %[^\n]s", s);
        char k[100];
        if(s[0]=='p' && s[1]=='u' && s[5]=='f'){
            int siz=0;
            while(s[siz]!='\0'){
                siz++;
            }
            for(int i=11; i<siz; i++){
                k[i-11] = s[i];
            }
            int x = atoi(k);
            d.pushfront(x);
        }
        else if(s[0]=='p' && s[1]=='u' && s[5]=='b'){
            int siz=0;
            while(s[siz]!='\0'){
                siz++;
            }
            for(int i=10; i<siz; i++){
                k[i-10] = s[i];
            }
            int x = atoi(k);
            d.pushback(x);
        }
        else if(s[0]=='p' && s[1]=='o' && s[4]=='f'){
            d.popfront();
        }
        else if(s[0]=='p' && s[1]=='o' && s[4]=='b'){
            d.popback();
        }
        else if(s[0]=='s'){
            d.sizeofdeque();
        }
        else if(s[0]=='e'){
            d.isempty();
        }
        else if(s[0]=='f'){
            d.dfront();
        }
        else if(s[0]=='b'){
            d.dback();
        }

        for(int j=0; j<100; j++)
            k[j]='\0';
    }
    return 0;
}
