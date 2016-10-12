
#include <iostream>
#include <queue>
using namespace std;
struct Pos{
    int x,y,j;
};
int map[202][202];
bool isVisited[202][202][32];

int px[12]={1,-1,0,0,-2, -2, 2, 2, -1, -1, 1, 1};
int py[12]={0,0,1,-1,1, -1, 1, -1, -2, 2, -2, 2};


queue<Pos> q;
int ans=0;
int main(){
    int K, W, H;
    cin>>K>>W>>H;
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            cin>>map[i][j];
    
    Pos p, next;
    p.x=0, p.y=0, p.j=0;
    isVisited[p.x][p.y][0]=true;
    q.push(p);
    while(!q.empty()){
        
        
        int q_size = q.size();
        while(q_size--){
            p=q.front(); q.pop();
            
            //cout<<p.x <<" "<<p.y<< " "<<p.j<<endl;
            if(p.x==H-1 && p.y==W-1){
                cout<< ans<<'\n';
                return 0;
            }
           
            
            for(int i=0;i<12;i++){
                
                if(p.x+px[i]<H && p.x+px[i]>=0 && p.y+py[i]<W && p.y+py[i]>=0 && map[p.x+px[i]][p.y+py[i]]==0){
                    
                    next.x=p.x+px[i], next.y=p.y+py[i];
                    if(i<4){
                        if(!isVisited[p.x+px[i]][p.y+py[i]][p.j]){
                            next.j=p.j;
                            q.push(next);
                            isVisited[p.x+px[i]][p.y+py[i]][next.j]=true;
                        }
                    }
                    else{
                        if(!isVisited[p.x+px[i]][p.y+py[i]][p.j+1] && p.j!=K){
                            next.j=p.j+1;
                            q.push(next);
                            isVisited[p.x+px[i]][p.y+py[i]][next.j]=true;
                        }
                    }
                    
                }
            }
        }

        ans++;

        
    }
    
    cout<<-1<<'\n';
    return 0;
}

