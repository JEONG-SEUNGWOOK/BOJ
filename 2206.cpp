
#include <iostream>
#include <queue>
using namespace std;

struct Pos{
    int x,y,bomb;
};
int N,M,dis=1,ans=0;
char map[1001][1001];
bool isVisited[1001][1001][2];
int px[4]={1,-1,0,0};
int py[4]={0,0,1,-1};

queue<Pos> q;

int main(){
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
        cin>>map[i];
    
    Pos s;
    s.x = 0, s.y = 0, s.bomb = 0;
    q.push(s);
    isVisited[s.x][s.y][s.bomb]=true;
    
    while(!q.empty()){
        int q_size = q.size();
        while(q_size--){
            Pos p = q.front(); q.pop();
            int x= p.x, y=p.y, b=p.bomb;
            
            //cout<<x<<" "<<y<<" "<<b<<endl;
            if(x==N-1 && y==M-1){
                ans=dis;
                cout<<ans<<'\n';
                return 0;
            }
            for(int i=0; i<4;i++){
                if(x+px[i]>=0 && x+px[i]<N && y+py[i]>=0 && y+py[i]<M && !isVisited[x+px[i]][y+py[i]][b] && map[x+px[i]][y+py[i]]=='0'){
                    
                    isVisited[x+px[i]][y+py[i]][b] = true;
                    Pos t;
                    t.x=x+px[i], t.y=y+py[i], t.bomb=b;
                    q.push(t);
                }
            }
            if(b==0){
                for(int i=0; i<4;i++){
                    if(x+px[i]>=0 && x+px[i]<N && y+py[i]>=0 && y+py[i]<M && !isVisited[x+px[i]][y+py[i]][b]){
                        
                        isVisited[x+px[i]][y+py[i]][b+1] = true;
                        Pos t;
                        t.x=x+px[i], t.y=y+py[i], t.bomb=b+1;
                        q.push(t);
                        
                    }
                }
                
                
            }
        }
        dis++;
    }
    if(ans==0)cout<<-1<<'\n';
}