
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M,N,K;
bool map[102][102];
bool isVisited[102][102];

vector<int> v;
int px[4]={1,-1,0,0};
int py[4]={0,0,1,-1};
int cnt;

void dfs(int y,int x){
    
    for(int i=0;i<4;i++){
        int nx=x+px[i], ny=y+py[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M && !isVisited[ny][nx] && !map[ny][nx]){
            
            cnt++;
            isVisited[ny][nx]=true;
            dfs(ny, nx);
        }
    }
    
}
int main(){
    cin>>M>>N>>K;
    while(K--){
        int x1,y1, x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1; i<x2; i++)
            for(int j=y1; j<y2; j++)
                map[j][i]=true;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!map[j][i] && !isVisited[j][i]){
                isVisited[j][i]=true;
                cnt=1;
                dfs(j,i);
                v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(), v.end());
    int v_size=v.size();
    int i=1;
    cout<<v_size<<'\n';
    for(auto n:v){
        if(i++ !=v_size)cout<<n<<" ";
        else cout<<n<<'\n';
    }
}