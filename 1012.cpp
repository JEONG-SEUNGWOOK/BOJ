
#include <cstdio>
using namespace std;
int T,N,M,K;
bool map[51][51];
bool isVisited[51][51];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x, int y){
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M && !isVisited[nx][ny] && map[nx][ny]){
            isVisited[nx][ny]=true;
            dfs(nx,ny);
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        int cnt=0;
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0; i<N;i++){
            for(int j=0;j<M;j++){
                isVisited[i][j]=false;
                map[i][j]=false;
            }
        }
        while(K--){
            int a,b;
            scanf("%d%d",&a,&b);
            map[a][b]=true;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!isVisited[i][j] && map[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}

