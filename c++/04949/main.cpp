#include <iostream>
#include <vector>
using namespace std;
vector <char> v;
int main()
{
    char arr[100];
    scanf("%[^\n]s", arr);
    cin.get();
    while( !(arr[0]=='.' && arr[1]=='\0') )
    {
        int i=0, k=0;
        while(arr[i]!='\0'){
            if(arr[i]=='(' || arr[i]=='[') v.push_back(arr[i]);
            else if(arr[i]==')' && v.size()!=0 && v.back()=='(') v.pop_back();
            else if(arr[i]==']' && v.size()!=0 && v.back()=='[') v.pop_back();
            else if(arr[i]==')') {k=1;}
            else if(arr[i]==']') {k=1;}
            i++;
        }
        if(!v.empty() || k==1) printf("no\n");
        else printf("yes\n");
        for(int j=0; j<100; j++){
            arr[j]='\0';
        }
        scanf("%[^\n]s", arr);
        cin.get();
        v.clear();
    }
    return 0;
}
