

#include <stdio.h>

int N;
long long dp[2][91];
int main(){
    scanf("%d",&N);
    dp[1][1]=1;
    for(int i=2;i<=N;i++){
        dp[1][i] = dp[0][i-1] ;
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
    }
    printf("%lld\n",dp[1][N]+dp[0][N]);
}
