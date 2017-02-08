
#include <iostream>
#include <queue>
using namespace std;

int pr[4] = {1,-1,0,0};
int pc[4] = {0,0,1,-1};

int main(){
    int T;
    cin>>T;
    while(T--){
        int C,R,sec=0;
        char map[1001][1001];
        bool visited[1001][1001]={0,};
        bool fire_visited[1001][1001]={0,};
        bool flag = false;
        queue<int> q,fire;
        
        cin>>C>>R;
        for(int i=0;i<R;i++)
            cin>>map[i];
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j] == '@') {
                    q.push(i*1000+j);
                    visited[i][j] = true;
                }
                if(map[i][j] == '*') {
                    fire.push(i*1000+j);
                    fire_visited[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            sec++;
            
            int fire_sz = fire.size();
            while(fire_sz--){
                int fire_r = fire.front()/1000;
                int fire_c = fire.front()%1000;
                fire.pop();
                
                for(int i=0;i<4;i++){
                    int fr = fire_r + pr[i], fc = fire_c + pc[i];
                    if(fr < 0 || fc < 0 || fr >= R || fr >= C) continue;
                    if(fire_visited[fr][fc]) continue;
                    if(map[fr][fc] == '#') continue;
                    if(map[fr][fc] == '*') continue;
                    fire_visited[fr][fc] = true;
                    map[fr][fc] = '*';
                    fire.push(fr*1000+fc);
                }
            }
            
            
            int sz=q.size();
            while(sz--){
                int r = q.front()/1000;
                int c = q.front()%1000;
                q.pop();
                
                if(r == 0 || c == 0 || r == R-1 || c == C-1) {
                    flag = true;
                    break;
                }
                
                for(int i=0;i<4;i++){
                    int nr = r + pr[i], nc = c + pc[i];
                    if(nr <0 || nc < 0 || nr >= R || nc >= C) continue;
                    if(visited[nr][nc]) continue;
                    if(map[nr][nc] == '#') continue;
                    if(map[nr][nc] == '*') continue;
                    visited[nr][nc] = true;
                    q.push(nr * 1000 + nc);
                }
                
            }
            if(flag) break;
            
        }
        flag ? cout<<sec<<"\n" : cout<<"IMPOSSIBLE\n";
    }
}
