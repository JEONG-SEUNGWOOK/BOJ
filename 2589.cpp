
#include <iostream>
#include <queue>
using namespace std;

int R,C,dis=0,ans=0;
char map[52][52];
bool isVisited[52][52];
int px[4]={1,-1,0,0};
int py[4]={0,0,1,-1};

queue<pair<int,int>> point;
queue<pair<int,int>> q;




void findPoint(int xi, int yi){
    isVisited[xi][yi]=true;
    q.push(make_pair(xi, yi));
    while(!q.empty()){
        pair<int, int> p;
        p=q.front(); q.pop();
        int x = p.first, y = p.second;
        bool check=false;
        for(int i=0; i<4; i++){
            if(x+px[i]>=0 && x+px[i]<R && y+py[i]>=0 && y+py[i]<C && map[x+px[i]][y+py[i]]=='L' && !isVisited[x+px[i]][y+py[i]]){isVisited[x+px[i]][y+py[i]]=true;
                check = true;
                q.push(make_pair(x+px[i], y+py[i]));
            }
        }
        if(!check) point.push(make_pair(x, y));
        
    }
}

void findAns(int xi, int yi){
    q.push(make_pair(xi, yi));
    isVisited[xi][yi]=true;
    while(!q.empty()){
        int q_size=q.size();
        while(q_size--){
            pair<int, int> p;
            p=q.front(); q.pop();
            int x = p.first, y = p.second;
            for(int i=0; i<4; i++){
                if(x+px[i]>=0 && x+px[i]<R && y+py[i]>=0 && y+py[i]<C && map[x+px[i]][y+py[i]]=='L' && !isVisited[x+px[i]][y+py[i]]){
                    isVisited[x+px[i]][y+py[i]]=true;
                    q.push(make_pair(x+px[i], y+py[i]));
                }
            }
        }
        if(!q.empty())dis++;
    }
}
int main(){
    cin >>R>>C;
    for(int i=0; i<R; i++){
        cin>>map[i];
    }
    
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]=='L' && !isVisited[i][j]){
                findPoint(i,j);
            }
        }
    }
   
    while(!point.empty()){
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                isVisited[i][j]=false;
            }
        }
        pair<int, int> temp;
        temp = point.front(); point.pop();
        dis=0;
        findAns(temp.first, temp.second);
        if(dis > ans) ans=dis;
    }
    cout<<ans<<'\n';
}