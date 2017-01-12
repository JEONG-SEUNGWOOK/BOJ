
#include <iostream>
#include <queue>
using namespace std;

struct pos{
    int r,c,cnt=0;
};

queue<pos> q;
int R,C,N,ans;
int map[1001][1001];
int isVisited[1001][1001];
int dr[10], dc[10];
bool flag = false;

int main(){
    cin>>R>>C;
    for(int i=0; i<R;i++)
        for(int j=0; j<C;j++)
            cin>>map[i][j];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>dr[i]>>dc[i];
    
    for(int i=0;i<C;i++)
        if(map[0][i]) {
            pos p;
            p.r=0, p.c=i, p.cnt=0;
            q.push(p);
            isVisited[0][i]=1;
        }
    
    while(!q.empty()){
        pos p;
        p=q.front(); q.pop();
        
        if(p.r == R-1){
            flag=1;
            ans=p.cnt;
            break;
        }
        for(int i=0; i<N; i++){
            int nr = p.r+dr[i], nc = p.c+dc[i], nCnt=p.cnt+1;
            if(nr>=0 && nc>=0 && nr<R && nc<C && !isVisited[nr][nc] && map[nr][nc]){
                pos t;
                t.r=nr, t.c=nc, t.cnt=nCnt;
                q.push(t);
                isVisited[nr][nc]=1;
                
            }
        }
        
    }
    if(flag) cout<<ans<<"\n";
    else cout<<-1<<"\n";
    
}
