#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    private : stack <int> s1,s2;
    public :
        void enqueue(int i)
        {
            if(s2.empty()) s2.push(i);
            else
            {
                while(!s2.empty())
                {
                    s1.push(s2.top());
                    s2.pop();
                }
                s1.push(i);
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        int dequeue()
        {
            int ans=s2.top();
            s2.pop();
            return ans;
        }

};
int main()
{
    Queue q = Queue();
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        char a;
        int b;
        scanf(" %c", &a);
        if(a=='e')
        {
            scanf("%d", &b);
            q.enqueue(b);
        }
        else printf("%d\n", q.dequeue());
    }
    return 0;
}
