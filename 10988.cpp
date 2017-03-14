
#include <iostream>
#include <string>
using namespace std;

bool isPalin(string s){
    int sz = s.size();
    for(int i=0;i<sz/2;i++){
        if(s.at(i) != s.at(sz-i-1)){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    cin>> s;
    cout<<isPalin(s)<<"\n";
}
