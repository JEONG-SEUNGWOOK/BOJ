
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,D_cnt=0;
        string p, X, num;
        deque<int> dq;
        int rev = 1;
        bool error = false;
        
        cin>>p>>n>>X;
        
        for(int i=0;i<X.size();i++){
            
            if(X.at(i)>='0' && X.at(i)<='9') num+=X.at(i);
            else {
                if( X.at(i)==',' || X.at(i)==']') dq.push_back(atoi(num.c_str()));
                num.clear();
            }
        }
        
        
        for(int i=0;i<p.size(); i++){
            if(p.at(i)=='R') rev*=-1;
            else if(p.at(i)=='D'){
                D_cnt++;
                if(dq.empty()) {
                    error = true;
                    break;
                }
                else {
                    if(rev == 1) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }
        
        if(n==0) {
            if(D_cnt > 0)
                cout<<"error"<<"\n";
            else
                cout<<"[]"<<"\n";
            
            continue;
        }

        
        if (error) cout<<"error"<<"\n";
        else {
            cout<<"[";
            
            while(!dq.empty()){
                if(rev == 1) {
                    if(dq.size()==1) cout<<dq.front();
                    else cout<<dq.front()<<",";
                    dq.pop_front();
                }
                else {
                    if(dq.size()==1) cout<<dq.front();
                    else cout<<dq.back()<<",";
                    dq.pop_back();
                }
            }
            cout<<"]\n";
        }
    }
}
