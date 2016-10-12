

#include <queue>
#include <string>
#include <iostream>

using namespace std;

int N, M, V;
int arr[1005][1005]={0,};
bool isVisited[1005];
bool isVisited2[1005];
queue<pair<int, int>> q;
pair<int, int> p;
void dfs(int start){
    isVisited[start] = true;
    for(int i=1; i<=N; i++){
        if(!isVisited[i] && arr[start][i]==1){
            cout<< i <<" ";
            dfs(i);
        }
    }
}
void bfs(int start){
    isVisited2[start] = true;
    while(!q.empty()){
        p = q.front();
        q.pop();
        int v = p.second;
        if(!isVisited2[v]) cout << v <<" ";
        isVisited2[v] = true;
        for(int i=1; i<=N; i++){
            if(!isVisited2[i] && arr[v][i]==1){
                q.push(make_pair(v, i));
            }
        }
    }
}
int main(){
    cin >> N >> M >> V;
    while(M--){
        int v, m;
        cin >> v >> m;
        arr[v][m] = arr[m][v] = 1;
        
    }
    for(int i=1; i<=N; i++)
        if(arr[V][i]==1) q.push(make_pair(V, i));
    
    cout<<V<<" ";
    dfs(V);
    cout<<"\n"<<V<<" ";
    bfs(V);
}

