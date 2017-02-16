
#include <stdio.h>

bool visited[52][52];
int map[52][52], cnt,R,C;
int pr[8]={1,-1,0,0,1,1,-1,-1};
int pc[8]={0,0,1,-1,1,-1,1,-1};

void dfs(int r,int c){
    visited[r][c]=1;
    for(int i=0;i<8;i++){
        int nr = r+pr[i], nc = c+pc[i];
        if(nr<0 || nc<0 || nr>=R || nc>=C) continue;
        if(map[nr][nc]==0) continue;
        if(visited[nr][nc]) continue;
        dfs(nr,nc);
    }
}
int main(){
    while(scanf("%d%d",&C,&R)){
        if(R==0 && C==0) break;
        cnt=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                map[i][j]=0;
                visited[i][j]=0;
            }
        }
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                scanf("%d",&map[i][j]);
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j]==1 && !visited[i][j] ){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }
}
