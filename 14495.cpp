
#include <stdio.h>
long long dp[118];
int main(){
    int N;
    scanf("%d",&N);
    dp[1]=dp[2]=dp[3]=1;
    for(int i=4;i<=N;i++)
        dp[i]=dp[i-1]+dp[i-3];
    printf("%lld\n",dp[N]);
}
