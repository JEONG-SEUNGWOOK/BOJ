
#include <stdio.h>

bool map[1011][1011];
int N,M,cnt=0;

void dfs(int ii, int jj){
    map[ii][jj] = false;
    for(int i=1; i<=N; i++){
        if(map[jj][i]) dfs(jj,i);
    }
}
int main(){
    scanf("%d %d",&N,&M);
    while(M--){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b] = map[b][a] = map[a][a] = map[b][b] = true;
    }
    
    for(int i=1;i<=N;i++)
        if(!map[i][i]) cnt++;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]) {
                ++cnt;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",cnt);
}
