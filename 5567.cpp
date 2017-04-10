

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int N,M,ans=0,cnt=0;
vector<int> v[502];
bool visited[502];
queue<int> q;

int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    visited[1]=1;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int n = q.front();
            q.pop();
            for(int &l : v[n]){
                if(!visited[l]){
                    visited[l]=1;
                    q.push(l);
                    ans++;
                }
            }
        }
        if(++cnt > 1) break;
    }
    printf("%d\n",ans);
}
