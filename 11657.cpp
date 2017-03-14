
#include <cstdio>
#include <vector>
using namespace std;

#define INF 987654321

int main(){
    int N,M;
    int dist[502];
    bool cycle = false;
    vector<pair<int, int>> v[502];
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        v[A].push_back(make_pair(B, C));
    }
    for(int i=1;i<=N;i++)
        dist[i]=INF;
    
    dist[1] = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(auto &n : v[j]){
                if(dist[j] != INF && dist[n.first] > n.second + dist[j]){
                    dist[n.first] = n.second + dist[j];
                    if(i == N) cycle = true;
                }
            }
        }
    }
    
    if(cycle) printf("-1\n");
    else{
        for(int i=2;i<=N;i++)
            if(dist[i]==INF) printf("-1\n");
            else printf("%d\n",dist[i]);
    }
    
}
