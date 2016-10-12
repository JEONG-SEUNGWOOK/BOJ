
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<string> v;
    string s, temp;
    cin>>s;
    for(int i=0;i<s.size();i++){
        temp.clear();
        for(int j=i;j<s.size();j++){
            temp+=s.at(j);
        }
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(auto a: v)
        cout<<a<<"\n";
}
