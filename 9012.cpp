
#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;

    cin>>T;
    while(T--){
        int vps=0;
        string parenthesis;
        cin>>parenthesis;
        for(int i=0; i<parenthesis.size(); ++i){
            char cur = parenthesis.at(i);
            if(cur=='(') ++vps;
            else --vps;
            if(vps < 0)break;
        }
        if(vps == 0)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}
