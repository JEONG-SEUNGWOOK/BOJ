
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

deque<pair<int, int>> q;
pair<int, int>p;
int N;
int main(){
    cin>>N;
    
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        q.push_back(make_pair(i, a));
    }
    
    int pos=0, target, a;
    
    p = q.front();
    q.pop_front();
    cout<<p.first;
    target=p.second;
    while(!q.empty()){
        pos=0;
        if(target>0){
            
            while(++pos < target){
                p = q.front(); q.pop_front();
                q.push_back(p);
            }
            p = q.front(); q.pop_front();
            
        }
        else {
            while(--pos > target){
                p = q.back(); q.pop_back();
                q.push_front(p);
            }
            p = q.back(); q.pop_back();
            
        }
        a = p.first;
        target = p.second;
        cout<<" "<<a;
    }
}
