/*

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int ans=0,cnt=0;
string s;
vector<string> suf;
int main(){
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        string temp;
        for(int j=i;j<s.size();j++) temp += s.at(j);
        suf.push_back(temp);
    }
    
    sort(suf.begin(), suf.end());
    
    
    for(vector<string>::iterator iter = suf.begin(); iter != suf.end(); iter++){
        cout<<*iter<<endl;
    }
    
    for (int i = 0; i < suf.size() - 1; ++i) {
        while (suf[i][cnt] == suf[i + 1][cnt]) ++cnt;
        ans = max(ans, cnt); cnt = 0;
    }
    cout<<ans<<"\n";
    
    
}
*/
