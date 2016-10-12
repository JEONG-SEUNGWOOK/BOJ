
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int ans[4]={0,};
        for(int i=0; i<s.size(); i++){
            int n=s.at(i);
            if(n>=97 && n<=122)ans[0]++;
            else if(n>=65 && n<=90) ans[1]++;
            else if(n>=48 && n<=57) ans[2]++;
            else ans[3]++;
        }
        s.clear();
        
        for(int i=0; i<4; i++){
            if(i!=3) cout<<ans[i]<<" ";
            else cout<<ans[i]<<"\n";
        }
    }
}
