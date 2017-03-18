

#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;

int main(){
    int N;
    map<string, bool, greater<string>> m;
    cin>>N;
    while(N--){
        string s, b;
        cin>>s>>b;
        if(b=="enter") m[s]=1;
        else m[s]=0;
    }
    for(auto b : m){
        if(b.second) cout<<b.first<<"\n";
    }
    return 0;
}
