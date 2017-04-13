
#include <stdio.h>
#include <math.h>
#define MOD 10007
long long dp[1002][11];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<10;i++)dp[1][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]+=dp[i-1][k];
                dp[i][j]%=MOD;
            }
        }
    }
    long long sum=0;
    for(int i=0;i<10;i++) sum+=dp[n][i];
    printf("%lld\n",sum%MOD);
}
