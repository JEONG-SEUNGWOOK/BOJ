
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pos{
    int x,y,time=0;
};
queue<Pos> q;
queue<pair<int, int>> w;

Pos start;
Pos cave;

int ans;
char map[55][55];
bool isVisited[55][55];

int main(){
    string s;
    Pos next;
    int R,C,w_size,q_size;
    cin >>R>>C;
    for(int i=0; i<R; i++){
        cin>>s;
        for(int j=0; j<C; j++){
            map[i][j]=s.at(j);
            if(s.at(j)=='S') start.x = i, start.y = j;
            if(s.at(j)=='*') w.push(make_pair(i, j));
        }
    }
    q.push(start);
    isVisited[start.x][start.y]=true;
    while(!q.empty()){
        q_size = q.size();
        w_size = w.size();
        
        while(w_size--){
            pair<int, int> water;
            water = w.front(); w.pop();
            
            //cout<<"물: "<<water.first<<" "<<water.second<<endl;
            if(map[water.first+1][water.second]!='D' && map[water.first+1][water.second]!='*' && map[water.first+1][water.second]!='X' && water.first+1 < R){
                map[water.first+1][water.second]='*';
                w.push(make_pair(water.first+1, water.second));
            }
            
            if(map[water.first-1][water.second]!='D' && map[water.first-1][water.second]!='*' && map[water.first-1][water.second]!='X' && water.first-1 >= 0){
                map[water.first-1][water.second]='*';
                w.push(make_pair(water.first-1, water.second));
            }
            
            if(map[water.first][water.second+1]!='D' && map[water.first][water.second+1]!='*' && map[water.first][water.second+1]!='X' && water.second+1 < C){
                map[water.first][water.second+1]='*';
                w.push(make_pair(water.first, water.second+1));
            }
            
            if(map[water.first][water.second-1]!='D' && map[water.first][water.second-1]!='*' && map[water.first][water.second-1]!='X' && water.second-1 >= 0){
                map[water.first][water.second-1]='*';
                w.push(make_pair(water.first, water.second-1));
            }
            
        }
        
        while(q_size--){
            Pos p=q.front(); q.pop();
            
            //cout<<"고 "<<p.x<<" "<<p.y<<" "<<p.time<<endl;
            
            if(map[p.x][p.y] =='D') {
                ans = p.time;
                break;
            }
            
            
            if(map[p.x+1][p.y]!='*' && map[p.x+1][p.y]!='X' && p.x+1 < R && !isVisited[p.x+1][p.y]){
                next.x = p.x+1, next.y = p.y, next.time=p.time+1;
                isVisited[p.x+1][p.y]=true;
                q.push(next);
            }
            
            if(map[p.x-1][p.y]!='*' && map[p.x-1][p.y]!='X' && p.x-1 >= 0 && !isVisited[p.x-1][p.y]){
                next.x = p.x-1, next.y = p.y, next.time=p.time+1;
                isVisited[p.x-1][p.y]=true;
                q.push(next);
            }
            
            if(map[p.x][p.y+1]!='*' && map[p.x][p.y+1]!='X' && p.y+1 < C && !isVisited[p.x][p.y+1]){
                next.x = p.x, next.y = p.y+1, next.time=p.time+1;
                isVisited[p.x][p.y+1]=true;
                q.push(next);
            }
            
            if(map[p.x][p.y-1]!='*' && map[p.x][p.y-1]!='X' && p.y-1 >= 0 && !isVisited[p.x][p.y-1]){
                next.x = p.x, next.y = p.y-1, next.time=p.time+1;
                isVisited[p.x][p.y-1]=true;
                q.push(next);
            }
        }
    }
    
    if(ans==0) cout<<"KAKTUS"<<endl;
    else cout<<ans<<endl;
    
}
