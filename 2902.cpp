
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    cout<<s.at(0);
    for(int i=0;i<s.size();i++){
        if(s.at(i)=='-') cout<<s.at(i+1);
    }
    cout<<"\n";
}
