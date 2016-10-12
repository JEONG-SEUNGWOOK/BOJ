
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXV 20001
#define MAXE 300001
#define INF 987654321

struct edge {int from, to, cost;};
typedef pair<int,int> P;  // first 는 최단거리, second 는 노드 번호

vector<edge> G[MAXV];
int d[MAXV];
int V,E,a,b,c,start;

void Dijkstra(int s){
    // greater<P> 는 first가 작은순으로 뽑을 수 있도록 한다.
    priority_queue<P,vector<P>,greater<P> > que;
    for (int i = 1; i <= V; i++){
        d[i] = INF;
    }
    d[s] = 0;
    que.push(P(0,s));
    while (!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    scanf("%d%d",&V,&E);
    scanf("%d",&start);
    for (int i = 0; i < E; i++){
        scanf("%d%d%d",&a,&b,&c);
        edge e;
        e.from = a;
        e.to = b;
        e.cost = c;
        G[a].push_back(e);
    }
    Dijkstra(start);
    for (int i = 1; i <= V; i++){
        if (d[i] == INF){
            printf("INF\n");
        }else{
            printf("%d\n",d[i]);
        }
    }
    return 0;
}
