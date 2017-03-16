

#include <cstdio>
#include <deque>
using namespace std;

int N,M,ans=0;
deque<int> dq;
int main(){
    scanf("%d%d",&N,&M);
    
    for(int i=1;i<=N;i++) dq.push_back(i);
    
    for(int i=0;i<M;i++){
        int n, pos=0, sz = dq.size();
        scanf("%d",&n);
        for(int i=0;i<sz;i++)
            if(dq.at(i) == n)
                pos = i;
        
        if(pos <= sz/2) {
            while(1){
                if(dq.front() == n) {
                    dq.pop_front();
                    break;
                }
                else{
                    ans++;
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
        }
        else{
            while (1) {
                
                if(dq.front() == n){
                    dq.pop_front();
                    break;
                }
                else {
                    ans++;
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
        }
    }
    printf("%d\n",ans);
}
