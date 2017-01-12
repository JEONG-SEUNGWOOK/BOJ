
#include <cstdio>
using namespace std;
int N,M,K,ans=0,cnt=1;
bool map[101][101];
bool isVisited[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x, int y){
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M && !isVisited[nx][ny] && map[nx][ny]){
            isVisited[nx][ny]=true;
            cnt++;
            dfs(nx,ny);
        }
    }
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    
    while(K--){
        int a,b;
        scanf("%d%d",&a,&b);
        map[a-1][b-1]=true;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!isVisited[i][j] && map[i][j]){
                cnt=0;
                dfs(i,j);
                if(cnt > ans) ans=cnt;
            }
        }
    }
    printf("%d\n",ans);
    
}
