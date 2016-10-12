
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
int maze[105][105];
bool isVisited[105][105]={false, };
int sum[105][105]={0,};
queue<pair<int, int>> q;
pair <int, int> p;

void input(){
    cin>>N>>M;
    string s;
    for(int i=1;i<=N;i++){
        cin>>s;
        for(int j=1;j<=M;j++){
            maze[i][j] = s.at(j-1)-'0';
        }
    }
}
void bfs(){
    q.push(make_pair(1,1));
    int count = 1;
    sum[1][1]=count;
    isVisited[1][1] = true;
    while(!q.empty()){
        count++;
        
        int size = q.size();
        for(int i=0; i<size; i++){
            
            p = q.front();
            q.pop();
            int x = p.first; int y = p.second;
            if(maze[x+1][y]==1 && x+1<=N && !isVisited[x+1][y]) {
                sum[x+1][y] = count;
                isVisited[x+1][y]=true;
                q.push(make_pair(x+1, y));
            }
            if(maze[x-1][y]==1 && x-1>0 && !isVisited[x-1][y]) {
                sum[x-1][y] = count;
                isVisited[x-1][y]=true;
                q.push(make_pair(x-1, y));
            }
            if(maze[x][y+1]==1 && y+1<=M && !isVisited[x][y+1]) {
                sum[x][y+1] = count;
                isVisited[x][y+1]=true;
                q.push(make_pair(x, y+1));
            }
            if(maze[x][y-1]==1 && y-1>0 && !isVisited[x][y-1]) {
                sum[x][y-1] = count;
                isVisited[x][y-1]=true;
                q.push(make_pair(x, y-1));
            }
        }
    }
}
void output(){
    cout<<sum[N][M];
}
int main(){
    input();
    bfs();
    output();
    
}
