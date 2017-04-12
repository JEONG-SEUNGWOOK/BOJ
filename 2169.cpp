

#include <iostream>
#define INF -9876543210
long long dp[1002][1002][3];
int map[1002][1002];
bool visited[1002][1002];
int N,M;
long long DP(int r, int c, int d){
    if(r==N && c==M) return map[r][c];
    long long v1=INF,v2=INF,v3=INF;
    long long &ret = dp[r][c][d];
    if(ret != INF) return ret;
    visited[r][c]=1;
    if(r+1 <= N && !visited[r+1][c]) v1= DP(r+1, c,0);
    if(c+1 <= M && !visited[r][c+1]) v2 = DP(r, c+1,1);
    if(c-1 > 0 && !visited[r][c-1]) v3=DP(r,c-1,2);
    ret = std::max(std::max(v1,v2),v3)+map[r][c];
    visited[r][c]=0;
    return ret;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            scanf("%d",&map[i][j]);
            dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=INF;
        }
    printf("%lld\n",DP(1,1,0));
}
