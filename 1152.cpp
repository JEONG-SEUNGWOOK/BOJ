
#include <iostream>
using namespace std;

int main(){
    char c;
    int cnt=1;
    while ((c = getchar()) != EOF && c != '\n')
        if(c==' ') cnt++;
    cout<<cnt;
}
