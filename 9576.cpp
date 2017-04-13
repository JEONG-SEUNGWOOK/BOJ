
#include <cstdio>
#include <vector>
using namespace std;

int T,N,M;
bool visited[1002];
int A[1002],B[1002];
vector<int> v[1002];

bool dfs(int start){
    visited[start]=1;
    for(int &n : v[start]){
        if(B[n]==-1 || (!visited[B[n]] && dfs(B[n]))){
            A[start]=n;
            B[n]=start;
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            for(int j=a;j<=b;j++)
                v[i].push_back(j-1);
        }
        
        fill(A, A+M, -1);
        fill(B, B+N, -1);
        fill(visited,visited+M,false);
        int ans=0;
        for(int i=0;i<M;i++){
            if(A[i]==-1){
                fill(visited, visited+M, false);
                if(dfs(i)) ans++;
            }
        }
        printf("%d\n",ans);
        
        for(int i=0;i<M;i++)
            v[i].clear();
    }
}
