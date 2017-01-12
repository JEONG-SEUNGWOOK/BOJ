/*
#include <cstdio>
#include <iostream>
using namespace std;
int N,ans=0,ans2=0;
char pic[101][101];
bool isVisited[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x, int y, char color){
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<N && !isVisited[nx][ny] && pic[nx][ny]==color){
            isVisited[nx][ny]=true;
          
            dfs(nx,ny,color);
        }
    }
}
int main(){
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        cin>>pic[i];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!isVisited[i][j]){
                ans++;
                char color = pic[i][j];
                dfs(i,j,color);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            isVisited[i][j]=false;
            if(pic[i][j]=='R') pic[i][j]='G';
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!isVisited[i][j]){
                ans2++;
                char color = pic[i][j];
                dfs(i,j,color);
            }
        }
    }
    printf("%d %d\n",ans,ans2);
    
}

*/