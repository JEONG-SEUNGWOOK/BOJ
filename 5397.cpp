
#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s1,s2;
int T;
int main(){
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            char c=s.at(i);
            if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')) s1.push(c);
            if(c=='<' && !s1.empty()) s2.push(s1.top()), s1.pop();
            if(c=='>' && !s2.empty()) s1.push(s2.top()), s2.pop();
            if(c=='-' && !s1.empty()) s1.pop();
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            cout<<s2.top();
            s2.pop();
        }
        cout<<"\n";
    }
}
