
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

list<char> l;
int main(){
    string s, cmd;
    int N;
    cin >> s;
    for(int i=0; i<s.size(); i++)
        l.push_back(s.at(i));
    
    int point = l.size();
    cin >> N;
    while(N--){
        cin>>cmd;
        if(cmd=="L" && point!=0)
            --point;
        else if(cmd=="D" && point!=l.size())
            ++point;
        else if(cmd=="B" && point!=0){
                    }
        else if(cmd=="P"){
            
        }
    }
    for(auto n:l)
        cout<<n;
}
