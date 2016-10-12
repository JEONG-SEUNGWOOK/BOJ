
#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,sum=0;
    string num;
    cin>>N>>num;
    for(int i=0; i<N; i++)
        sum += num.at(i)-'0';
    
    cout<<sum;
    return 0;
}
