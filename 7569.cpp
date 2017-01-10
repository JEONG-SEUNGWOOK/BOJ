
#include <cstdio>
#include <queue>
using namespace std;

struct Pos{
    int m,n,h,cnt=0;
};
int pm[6]={1,-1,0,0,0,0};
int pn[6]={0,0,1,-1,0,0};
int ph[6]={0,0,0,0,1,-1};
int box[101][101][101];
bool isVisited[101][101][101];
queue<Pos> q;
int ans=0;
int main(){
    int M,N,H,cnt=0,ripen=0;
    scanf("%d%d%d",&M,&N,&H);
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                int a;
                scanf("%d",&a);
                box[j][k][i]=a;
                if(a==1){
                    ++ripen;
                    Pos t;
                    t.m=k, t.n=j, t.h=i;
                    q.push(t);
                    isVisited[j][k][i]=true;
                }
                if(a!=-1) ++cnt;
            }
        }
    }
    while(!q.empty()){
        
        Pos p=q.front(); q.pop();
        
        for(int i=0;i<6;i++){
            int nm=p.m+pm[i], nn=p.n+pn[i], nh=p.h+ph[i], nc=p.cnt;
            if(nm>=0 && nn>=0 && nh>=0 && nm<M && nn<N && nh<H && !isVisited[nn][nm][nh] && box[nn][nm][nh]==0){
                Pos t;
                t.m=nm, t.n=nn, t.h=nh, t.cnt=nc+1;
                q.push(t);
                box[nn][nm][nh]=1;
                isVisited[nn][nm][nh]=true;
                ++ripen;
                if(ripen==cnt) {
                    ans=t.cnt;
            
                    break;
                }
            }
        }
        
    }
    if(ripen==cnt) printf("%d\n",ans);
    else printf("-1\n");
}
