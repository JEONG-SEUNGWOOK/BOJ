
#include <iostream>
using namespace std;
int dp[10002];
int wine[10002];
int N;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++)scanf("%d",&wine[i]);
    dp[1]=wine[1];
    dp[2]=wine[2]+dp[1];
    for(int j=3;j<=N;j++)
        dp[j] = max(max(dp[j-2]+wine[j], dp[j-1]), dp[j-3]+wine[j-1]+wine[j]);
    printf("%d\n",dp[N]);
    
}
