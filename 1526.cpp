
#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int N,ans=0;
    queue<int> q;
    scanf("%d",&N);
    if(4 <= N){
        ans=4;
        q.push(4);
    }
    if (7 <= N){
        ans=7;
        q.push(7);
    }
    while(!q.empty()){
        int n=q.front();
        q.pop();
        n*=10;
        if(n+4 <=N){
            ans = n+4;
            q.push(n+4);
        }
        if(n+7 <=N){
            ans = n+7;
            q.push(n+7);
        }
    }
    printf("%d\n",ans);
}
