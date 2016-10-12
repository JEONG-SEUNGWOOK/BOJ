
#include <iostream>
#include <string>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int R; string s;
        cin>>R>>s;
        for(int i=0;i<s.size();i++)
            for(int j=0;j<R;j++)
                cout<<s.at(i);
        
        cout<<'\n';
    }
}
