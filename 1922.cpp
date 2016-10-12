
#include <stdio.h>
#define INF 1000000001
int N, M;
int com[1002][1002];
int dist[1002];
int isVisited[1002];
int sum=0;
void input(){
    scanf("%d %d",&N, &M);
    for(int i=1;i<=N; i++){
        for(int j=1;j<=N;j++){
            com[i][j]=INF;
        }
        dist[i]=INF;
        isVisited[i]=0;
    }
    while(M--){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        com[a][b]=w;
        com[b][a]=w;
    }
    
    
}
int minVer(){
    int v;
    for(int i=1;i<=N; i++){
        if(!isVisited[i]){
            v=i;
            break;
        }
    }
    for(int i=1;i<=N; i++){
        if(!isVisited[i] && dist[i] < dist[v]) v=i;
    }
    return v;
}
void prim(){
    int u, start = 1;
    dist[start] = 0;
    for(int i=1; i<=N; i++){
        u=minVer();
        isVisited[u]=1;
        if(dist[u]==INF)break;
        sum+=dist[u];
        for(int v=1; v<=N; v++){
            if(com[u][v]!=INF){
                if(!isVisited[v] && com[u][v] < dist[v])
                    dist[v]=com[u][v];
            }
        }
    }
}
void output(){
    printf("%d",sum);
}
int main(){
    input();
    prim();
    output();
    return 0;
}
