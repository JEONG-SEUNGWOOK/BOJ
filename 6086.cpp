
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 52;
const int INF = 1000000000;

int CtoI(char c){
    if(c <= 'Z') return c-'A';
    return c-'a'+26;
}
int main(){
    vector<int> adj[MAXV];
    int f[MAXV][MAXV] = {0};
    int c[MAXV][MAXV] = {0};
    int N;
    
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char u,v;
        int w;
        scanf(" %c %c %d",&u, &v, &w);
        u = CtoI(u); v = CtoI(v);
        c[u][v] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int S = CtoI('A'), T = CtoI('Z'), ans = 0;
    while(1){
        int visited[MAXV];
        fill(visited, visited+MAXV, -1);
        queue<int> q;
        q.push(S);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int next : adj[cur]){
                if(c[cur][next] - f[cur][next] > 0 && visited[next] == -1){
                    q.push(next);
                    visited[next] = cur;
                    if(next == T) break;
                }
            }
        }
        if(visited[T] == -1) break;
        int flow = INF;
        for(int i=T; i!=S; i=visited[i])
            flow = min(flow, c[visited[i]][i]-f[visited[i]][i]);
        // 찾은 flow만큼 해당 경로에 유량 흘려줌
        for(int i=T; i!=S; i=visited[i]){
            f[visited[i]][i] += flow;
            f[i][visited[i]] -= flow;
        }
        // 총 유량 값 증가
        ans += flow;
    }
    printf("%d\n",ans);
}
