
#include <iostream>
#include <string>
using namespace std;

int alpha[26];
int main(){
    string s;
    cin>>s;
    for(int i=0; i<26; i++)
        alpha[i]=-1;
    
    for(int i=0; i<s.size();i++){
        if(alpha[s.at(i)-'a'] == -1)alpha[s.at(i)-'a'] = i;
    }
    for(int i=0; i<26 ;i++){
        if(i!=25)cout<<alpha[i]<<" ";
        else cout<<alpha[i];
    }
}

