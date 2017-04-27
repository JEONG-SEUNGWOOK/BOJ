
#include <iostream>
using namespace std;

int N,M,ans=0;
int map[501][501];
bool visited[501][501];

int pr[4]={1,-1,0,0};
int pc[4]={0,0,1,-1};

void dfs(int r, int c, int sum, int cnt){
    sum += map[r][c];
    if(cnt == 3) {
        if(sum > ans) ans = sum;
        return;
    }
    visited[r][c]=1;
    for(int i=0;i<4;i++){
        int nr = r+pr[i], nc = c+pc[i];
        if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
        if(visited[nr][nc]) continue;
        dfs(nr, nc, sum, cnt+1);
    }
    visited[r][c]=0;
}
void fuckyou(int i, int j){
    for(int k=0;k<4;k++){
        int sum = map[i][j];
        bool flag = 1;
        for(int l=0;l<4;l++){
            if(k==l) continue;
            int nr = i+pr[l], nc = j+pc[l];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) {
                flag = 0;
                break;
            }
            sum += map[nr][nc];
        }
        if(flag && sum > ans) ans = sum;
    }
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&map[i][j]);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dfs(i,j,0,0);
            fuckyou(i,j);
        }
    }
    printf("%d\n",ans);
}
