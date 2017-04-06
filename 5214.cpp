
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N,K,M,cnt=1;
vector<int> v[200002];
bool visited[100002];
queue<int> q;
int main(){
    scanf("%d%d%d",&N,&K,&M);
    
    for(int i=0, temp ;i<M;i++){
        for(int j=0;j<K;j++){
            scanf("%d",&temp);
            v[N+i+1].push_back(temp);
            v[temp].push_back(N+i+1);
        }
    }
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int n=q.front();
            q.pop();
            
            if(n==N){
                printf("%d\n",cnt);
                return 0;
            }
            for(auto &l : v[n]){
                for(auto &ln : v[l]){
                    if(visited[ln]) continue;
                    q.push(ln);
                    visited[ln]=1;
                }
            }
        }
        cnt++;
    }
    printf("-1\n");
}
