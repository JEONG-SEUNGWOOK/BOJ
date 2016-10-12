
#include <stdio.h>
#define INF 987654321;
int V, E;
int start,end;
int map[1002][1002];
int dist[1002];
int isVisited[1002];

void input(){
    scanf("%d %d", &V, &E);
    
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            map[i][j]=INF;
        }
        dist[i]=INF;
        isVisited[i]=0;
    }
    
    for(int i=1; i<=E; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if(map[u][v] > w) map[u][v]=w;
    }
    scanf("%d", &start);
    scanf("%d",&end);
}

void dijkstra(){
    int min;
    int v =0;
    dist[start]=0;
    for(int i=1; i<=V; i++){
        min = INF;
        for(int j=1; j<=V; j++){
            if(isVisited[j]==0 && min > dist[j]){
                min = dist[j];
                v = j;
            }
        }
        isVisited[v] = 1;
        for(int j=1; j<=V;j++){
            if(dist[j]>dist[v]+map[v][j]){
                dist[j]=dist[v]+map[v][j];
            }
        }
    }
}
void output(){
    printf("%d", dist[end]);
}

int main(){
    input();
    dijkstra();
    output();
    return 0;
}

