#include <iostream>
#include <deque>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        deque<pair<int, bool>> dq;
        int N,M,a,ans=0;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            cin>>a;
            i==M ? dq.push_back(make_pair(a,true)) : dq.push_back(make_pair(a,false));
        }
        while(!dq.empty()){
            int f = dq.front().first;
            bool c = dq.front().second;
            bool flag = false;
            dq.pop_front();
            for(int i=0;i<dq.size();i++){
                if(f < dq.at(i).first) {
                    dq.push_back(make_pair(f, c));
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans++;
                if(c) break;
            }
        }
        cout<<ans<<"\n";
    }
}
