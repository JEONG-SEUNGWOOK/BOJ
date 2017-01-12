
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> Pos;
int T,l,ans=0;

int px[8]={1,2,1,2,-1,-2,-1,-2};
int py[8]={2,1,-2,-1,2,1,-2,-1};
bool isVisited[302][302];

queue<pair<int, int>> q;

Pos s,e;
int main(){
    cin>>T;
    while(T--){
        cin>>l;
        ans=0;
        for(int i=0;i<l;i++)
            for(int j=0;j<l;j++)
                isVisited[i][j]=false;
        cin>>s.first>>s.second >>e.first>>e.second;
        q.push(s);
        isVisited[s.first][s.second]=true;
        
        while(!q.empty()){
            int q_size = q.size();
            while(q_size--){
                Pos p;
                p=q.front(); q.pop();
                int x=p.first, y=p.second;
                
                if(x==e.first && y==e.second){
                    cout<<ans<<'\n';
                    break;
                }
                
                for(int i=0;i<8;i++){
                    if(x+px[i]>=0 && y+py[i]>=0 && x+px[i]<l && y+py[i]<l && !isVisited[x+px[i]][y+py[i]]){
                        
                        isVisited[x+px[i]][y+py[i]]=true;
                        Pos next;
                        next.first=x+px[i], next.second=y+py[i];
                        q.push(next);
                    }
                }
            }
            ans++;
        }
        
    }
}

