
#include <stdio.h>
int map[101][101],ans=0,N;
int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
bool isVisited[101][101];

void dfs(int ii, int jj, int k, int cnt){
    isVisited[ii][jj] = true;
    for(int i=0;i<4;i++){
        int ni=ii+di[i], nj=jj+dj[i];
        if(ni >= 0 && nj >= 0 && ni < N && nj < N && map[ni][nj] > k && !isVisited[ni][nj]){
            dfs(ni,nj,k,cnt);
        }
    }
    
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    for(int k=0;k<=100;k++){
        int cnt = 0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                isVisited[i][j]=false;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j] > k && !isVisited[i][j]){
                    cnt++;
                    dfs(i,j,k,cnt);
                }
            }
        }
        if(cnt > ans) ans = cnt;
        if(cnt == 0) break;
    }
    printf("%d\n",ans);
}
