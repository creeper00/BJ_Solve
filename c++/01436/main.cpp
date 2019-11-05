#include <iostream>
#include <string>
using namespace std;

int checker(int n){
    if(n==1) return 666;
    else if(n<7) return (n-1)*1000+666;
    else{
        int a=6660;
        while(1)
        {
            int i=0,b=a;
            while(b!=0){
                if(b%10 == 6) i++;
                else i=0;
                b=b/10;
                if(i>=3) {
                    n--;
                    break;
                }
            }
            if((n-6)==0) break;
            a++;
        }
        return a;
    }
}
int check(int N){

        int num = 666;

        int turn = 1;

        //완전 탐색

        while (1)

        {

                 //해당 숫자를 찾았다면

                 if (turn == N)

                         break;



                 num++;



                 //해당 숫자를 저장하고

                 int copyNum = num;

                 string s;

                 while (copyNum)

                 {

                         s += (copyNum % 10 + '0');

                         copyNum /= 10;

                 }

                 copyNum = stoi(s);



                 //6이 연속으로 세개 있는지 확인

                 int six = 0;

                 while (copyNum)

                 {

                         int temp = copyNum % 10;

                         if (temp == 6)

                                 six++;

                         else if(six < 3)

                                 six = 0;

                         copyNum /= 10;

                 }

                 //조건을 만족한다면

                 if (six >= 3)

                         turn++;

        }

        return num;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d", check(n), checker(n));
    for(int i=1; i<=10000; i++){
        if(checker(i)!=check(i)) {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
