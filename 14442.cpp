#include <iostream>
#include <queue>
using namespace std;

struct Pos{
public:
    int r,c,k=0,cnt=0;
    Pos(){}
    Pos(int _r, int _c, int _k, int _cnt): r(_r), c(_c), k(_k), cnt(_cnt){}
};
int N,M,K;
char map[1002][1002];
int pr[4] = {1,-1,0,0};
int pc[4] = {0,0,1,-1};
bool visited[1002][1002][11];
queue<Pos> q;

int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<N;i++)
        cin>>map[i];
    
    q.push(Pos(0,0,0,1));
    visited[0][0][0] = 1;
    
    while(!q.empty()){
        int r = q.front().r, c = q.front().c, k = q.front().k, cnt = q.front().cnt;
        q.pop();
        
        if(r == N-1 && c == M-1){
            cout<<cnt<<"\n";
            return 0;
        }
        for(int i=0;i<4;i++){
            int nr = r + pr[i];
            int nc = c + pc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(visited[nr][nc][k]) continue;
            if(map[nr][nc] == '1'){
                if(k < K) {
                    q.push(Pos(nr, nc, k+1, cnt+1)),
                    visited[nr][nc][k+1] = 1;
                }
                continue;
            }
            visited[nr][nc][k] = 1;
            q.push(Pos(nr, nc, k, cnt+1));
        }
    }
    puts("-1\n");
}
