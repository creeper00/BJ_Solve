#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    double sum=0;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sum = sum/n;
    int average = round(sum);

    sort(arr, arr+n);
    int median=0;
    if(n%2==0) median = arr[n/2];
    else median = arr[n/2];

    int freq = 0;
    int counter = 1;
    int cc=0, check=0;
    for(int i=0; i<(n-1); i++){
        if(arr[i]==arr[i+1]) counter++;
        else {
            if(cc<counter) {cc=counter; freq=arr[i]; check=0;}
            else if(cc==counter){
                if(check==0) {freq = arr[i]; check=1;}
            }
            counter=1;
        }
    }
    if(cc<counter) {cc=counter; freq=arr[n-1];}
    else if(cc==counter && check==0) freq=arr[n-1];


    int range = arr[n-1]-arr[0];

    printf("%d\n%d\n%d\n%d", average, median, freq, range);
}
