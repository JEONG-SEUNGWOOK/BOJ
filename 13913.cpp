

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int px[2]={1,-1};
int N,K,cnt=0;
int visited[100002];
queue<int> q;
int main(){
    scanf("%d%d",&N,&K);
    q.push(N);
    for(int i=0;i<100001;i++)
        visited[i]=-1;
    
    visited[N]=N;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int x = q.front();
            q.pop();
            if(x==K){
                printf("%d\n",cnt);
                vector<int> v;
                int pre = K;
                while(pre!=N){
                    v.push_back(pre);
                    pre = visited[pre];
                }
                printf("%d",N);
                for(int i=v.size()-1;i>=0;i--)
                    printf(" %d",v[i]);
                
                return 0;
            }
            for(int i=0;i<3;i++){
                int nx;
                if(i==2) nx = 2*x;
                else nx = x + px[i];
                if(nx > 100000 || nx < 0) continue;
                if(visited[nx]!=-1) continue;
                visited[nx]=x;
                q.push(nx);
            }
        }
        cnt++;
    }
}
