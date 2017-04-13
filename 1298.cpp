
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v[102];
int A[102],B[102];
bool visited[102];

bool dfs(int start){
    visited[start] =1;
    for(int &n : v[start]){
        if(B[n]==-1 || (!visited[B[n]] && dfs(B[n]))){
            A[start] = n;
            B[n] = start;
            return true;
        }
    }
    return false;
}
int main(){
    int N,M,ans=0;
    scanf("%d%d",&N,&M);
    for(int i=0,a,b;i<M;i++){
        scanf("%d%d",&a,&b);
        v[a-1].push_back(b-1);
    }
    
    fill(A, A+N, -1);
    fill(B, B+N, -1);
    
    for(int i=0;i<N;i++){
        if(A[i]==-1){
            fill(visited, visited+N, false);
            if(dfs(i)) ans++;
        }
    }
    printf("%d\n",ans);
}
