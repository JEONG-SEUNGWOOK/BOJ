

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    vector<string> v;
    int cnt=0,ans=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
        v.push_back(s.substr(i,s.size()));
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<v.size()-1;i++){
        while(v[i][cnt] == v[i+1][cnt]) cnt++;
        ans = max(cnt, ans);
        cnt=0;
    }
    cout<<ans<<"\n";
}
