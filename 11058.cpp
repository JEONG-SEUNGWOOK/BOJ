
#include <iostream>
using namespace std;
int N;
long long dp[102];
int main(){
    scanf("%d",&N);
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    dp[5]=5;
    dp[6]=6;
    
    for(int i=7;i<=N;i++)
        dp[i] = max(max(dp[i-5]*4, dp[i-4]*3), dp[i-3]*2);
    
    printf("%lld\n",dp[N]);
}
