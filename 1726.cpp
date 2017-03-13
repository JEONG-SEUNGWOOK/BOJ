

#include <cstdio>
#include <queue>

using namespace std;

class Pos{
public:
    int r,c,dir,cnt=0;
    Pos(){};
    Pos(int _r, int _c, int _dir, int _cnt) : r(_r), c(_c), dir(_dir), cnt(_cnt){};
};

int N,M;
int map[102][102];
int pr[5] = {0, 0,0,1,-1};
int pc[5] = {0, 1,-1,0,0};
bool visited[102][102][5];
Pos st, en;
queue<Pos> q;

int opp(int n){
    if (n == 1)return 2;
    else if (n == 2)return 1;
    else if (n == 3)return 4;
    else return 3;
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d",&map[i][j]);
    
    scanf("%d%d%d%d%d%d",&st.r, &st.c, &st.dir, &en.r, &en.c, &en.dir);
    
    q.push(st);
    visited[st.r][st.c][st.dir] = 1;
    
    while(!q.empty()){
        int r=q.front().r, c=q.front().c, dir=q.front().dir, cnt=q.front().cnt;
        q.pop();
        if(r == en.r && c == en.c && dir == en.dir){
            printf("%d\n",cnt);
            return 0;
        }
        
        int nr, nc;
        for(int i=1; i<=3; i++){
            nr = r + pr[dir] * i;
            nc = c + pc[dir] * i;
            if(nr <1  || nc < 1 || nr > N || nc > M) break;
            if(map[nr][nc]) break;
            if(visited[nr][nc][dir]) continue;
            visited[nr][nc][dir] = 1;
            q.push(Pos(nr,nc,dir,cnt+1));
        }
        
        for(int i=1; i<=4; i++){
            if(i == dir || i == opp(dir)) continue;
            if(visited[r][c][i]) continue;
            visited[r][c][i] = 1;
            q.push(Pos(r,c,i,cnt+1));
        }
    }
    return 0;
}
