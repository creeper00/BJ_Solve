#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <char> v;
void VPSchecker(char *arr);
stack <char> st;

int main()
{
    int n;
    cin>>n;
    for(int r=0; r<n; r++){
        char arr[51];
        scanf("%s", arr);
        VPSchecker(arr);
        v.clear();
    }
    return 0;
}

void VPSchecker(char *arr) {
    int i=0,flag=0;
    while(arr[i]!='\0'){
        if(arr[i]=='(') v.push_back(arr[i]);
        else if(arr[i]==')'){
            if(!v.empty()) v.pop_back();
            else {
                flag = 1;
                break;
            }
        }
        i++;
    }
    if(!v.empty() || flag==1) printf("NO\n");
    else printf("YES\n");
}
