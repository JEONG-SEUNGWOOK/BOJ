

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N,M,A,B,cnt=0;
bool visited[1002];
vector<int> v[1002];
queue<int> q;
int main(){
    scanf("%d%d%d%d",&A,&B,&N,&M);
    for(int i=0, a,b;i<M;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[A]=1;
    q.push(A);
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int n = q.front();
            q.pop();
            if(n==B){
                printf("%d\n",cnt);
                return 0;
            }
            for(auto &l : v[n]){
                if(visited[l]) continue;
                visited[l]=1;
                q.push(l);
            }
        }
        cnt++;
    }
    printf("-1\n");
}
