#include <iostream>
#include <cstdio>
using namespace std;

int main() {
 char str[100];
 while (fgets(str, 100, stdin) != NULL) {
 printf("%s", str);
 }
 return 0;
}
