
#include <iostream>
#include <queue>
using namespace std;

int N, ans=0;
int T[17],P[17];
queue<pair<int, int>> q;

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        scanf("%d%d",&T[i],&P[i]);
        if(T[i]+i-1 <= N) {
            q.push({T[i]+i,P[i]});
            if(ans < P[i]) ans=P[i];
        }
    }
    
    while(!q.empty()){
        int day = q.front().first, sum = q.front().second;
        q.pop();
        for(int i=day; i<=N;i++){
            if(T[i]+i-1 <= N) {
                q.push({T[i]+i, sum+P[i]});
                if (ans < sum+P[i]) ans = sum+P[i];
            }
        }
    }
    printf("%d\n",ans);
}
