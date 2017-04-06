
#include <cstdio>
#include <queue>
using namespace std;

struct Pos{
public:
    int redR, redC, blueR, blueC;
    Pos(){}
    Pos(int rr,int rc,int br, int bc): redR(rr), redC(rc), blueR(br), blueC(bc){}
};
int N,M,cnt=0;
char board[12][12];
bool visited[12][12][12][12];
int pr[4]={0,0,1,-1};
int pc[4]={1,-1,0,0};
queue<Pos> marble;

int main(){
    scanf("%d%d",&N,&M);
    
    int a,b,c,d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %c",&board[i][j]);
            if(board[i][j]=='R')
                a=i, b=j;
            
            if(board[i][j]=='B')
                c=i, d=j;
            
        }
    }
    visited[a][b][c][d] = 1;
    marble.push(Pos(a,b,c,d));
    
    while(!marble.empty()){
        int sz = marble.size();
        while(sz--){
            int br = marble.front().blueR, bc = marble.front().blueC;
            int rr = marble.front().redR, rc = marble.front().redC;
            marble.pop();
            
            if(board[rr][rc]=='O'){
                printf("1\n");
                return 0;
            }
            for(int i=0;i<4;i++){
                int nbr=br, nbc=bc, nrr=rr, nrc=rc;
                bool bf=0;
                //move red marble
                while(board[nrr+pr[i]][nrc+pc[i]]!='#' && board[nrr][nrc]!='O'){
                    nrr += pr[i];
                    nrc += pc[i];
                }
                //move blue marble
                while(board[nbr+pr[i]][nbc+pc[i]]!='#' && board[nbr][nbc]!='O'){
                    nbr += pr[i];
                    nbc += pc[i];
                    if(board[nbr][nbc]=='O') bf=1;
                }
                if((nrr == nbr && nrc == nbc)){
                    if(i==0) {
                        if(bc>rc) nrc-=1;
                        else nbc-=1;
                    }
                    else if(i==1){
                        if(bc>rc) nbc+=1;
                        else nrc +=1;
                    }
                    else if(i==2){
                        if(br>rr) nrr-=1;
                        else nbr-=1;
                    }
                    else {
                        if(br>rr) nbr+=1;
                        else nrr+=1;
                    }
                }
                if(bf) continue;
                if(visited[nrr][nrc][nbr][nbc]) continue;
                marble.push(Pos(nrr,nrc,nbr,nbc));
                visited[nrr][nrc][nbr][nbc]=1;
            }
        }
        cnt++;
        if(cnt>10) break;
    }
    printf("0\n");
}
