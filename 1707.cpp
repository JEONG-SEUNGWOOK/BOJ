

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> G[20001];
int value[20001];
int V, E;
int flag = 1;
bool dfs(int start,int f){
    
    value[start]=f;
    for(int i=0; i<G[start].size(); i++){
        int v = G[start][i];
        if(value[v]==0 && !dfs(v,-f)) {
            return false;
        }
        if(value[v]==f){
            return false;
        }
    }
    return true;
}
void process(){
    
    for(int i=0; i<V; i++){
        if(value[i]==0 && !dfs(i, 1)){
            printf("NO\n");
            return;
            
            
        }
    }
    printf("YES\n");
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&V, &E);
        for(int i=0; i<V; ++i){
            G[i].clear();
            value[i]=0;
        }
        while(E--){
            int a,b;
            scanf("%d %d",&a, &b);
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(V == 1){
            printf("NO\n");
            continue;
        }
        else process();
    }
    return 0;
}
