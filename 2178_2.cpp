
#include <iostream>
#include <queue>
using namespace std;

int N,M,ans=1;
queue<pair<int, int>> q;
char map[102][102];
bool isVisited[102][102];
int px[4]={1,-1,0,0};
int py[4]={0,0,1,-1};

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>map[i];
    
    pair<int, int> s;
    s.first=0, s.second=0;
    isVisited[s.first][s.second]=true;
    q.push(s);
    while(!q.empty()){
        
        int q_size = q.size();
        while(q_size--){
            
            pair<int, int> p;
            p=q.front(); q.pop();
            int x=p.first, y=p.second;
            if(x==N-1 && y==M-1){
                cout<<ans<<'\n';
                return 0;
            }
            for(int i=0; i<4; i++){
                if(x+px[i]>=0 && x+px[i]<N && y+py[i]>=0 && y+py[i]<M && !isVisited[x+px[i]][y+py[i]] && map[x+px[i]][y+py[i]]=='1'){
                    
                    pair<int, int> temp;
                    temp.first = x+px[i]; temp.second = y+py[i];
                    q.push(temp);
                    isVisited[x+px[i]][y+py[i]]=true;;
                }
            }
        }
        ans++;
        
    }

}