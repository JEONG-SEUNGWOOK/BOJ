
#include <cstdio>
#include <queue>
using namespace std;
struct Pos{
    int m,n,cnt=0;
};
int px[4]={1,-1,0,0};
int py[4]={0,0,1,-1};
int box[1001][1001];
bool isVisited[1001][1001];
int ripe=0,cnt=0,ans=0;
queue <Pos> q;

int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&box[i][j]);
            if(box[i][j]==1){
                Pos t;
                t.m=j,t.n=i;
                q.push(t);
                ripe++;
                isVisited[i][j]=true;
            }
            if(box[i][j]!=-1) cnt++;
        
        }
    }
    while(!q.empty()){
        Pos p=q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nm=p.m+px[i], nn=p.n+py[i], nc=p.cnt;
            if(nm>=0 && nn>=0 && nm<M && nn<N && box[nn][nm]==0 && !isVisited[nn][nm]){
                isVisited[nn][nm]=true;
                Pos n;
                n.m=nm, n.n=nn, n.cnt=nc+1;
                q.push(n);
                ripe++;
                if(ripe==cnt){
                    ans=n.cnt;
                    break;
                }
            }
        }
    }
    if(ripe==cnt) printf("%d\n",ans);
    else printf("-1\n");
}
