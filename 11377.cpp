
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v[1002],v2[1002];
bool visited[1002];
int A[1002],B[1002];

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
    int N,M,K,ans=0;
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0,S;i<N;i++){
        scanf("%d",&S);
        for(int j=0,s;j<S;j++){
            scanf("%d",&s);
            v[i].push_back(s-1);
        }
    }
    
    fill(A,A+N,-1);
    fill(B,B+M,-1);
    
    for(int i=0;i<N;i++){
        if(A[i]==-1){
            fill(visited,visited+N,false);
            if(dfs(i)) ans++;
        }
    }
    for(int i=0;i<N && K > 0;i++){
        fill(visited,visited+N,false);
        if(dfs(i)) ans++,K--;
    }
    printf("%d\n",ans);
}
