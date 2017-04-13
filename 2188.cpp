

#include <cstdio>
#include <vector>
using namespace std;

int N,M,ans=0;
int A[202],B[202];
vector<int> v[202];
bool visited[202];

bool dfs(int start){
    visited[start]=1;
    //printf("start : %d\n",start+1);
    for(int &n : v[start]){
        if(B[n]==-1 || (!visited[B[n]] && dfs(B[n]))){
            A[start] = n;
            B[n] = start;
           // printf("소%d 축사%d\n",start+1, n+1);
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&N,&M);
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
            fill(visited, visited+N,false);
            if(dfs(i)) ans++;
        }
    }
    
    printf("%d\n",ans);
}
