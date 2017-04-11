
#include <string>
#include <iostream>
using namespace std;
int main(){
    string a,b;
    int cnt=0,ans=987654321;
    cin>>a>>b;
    for(int i=0;i<=b.size()-a.size();i++){
        cnt=0;
        for(int j=0;j<a.size();j++){
            if(a[j]!=b[j+i]) cnt++;
        }
        ans=min(cnt, ans);
    }
    cout<<ans<<"\n";
}
