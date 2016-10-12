

#include <stdio.h>
typedef long long int lli;
lli N,K,Q,a,b;
int main() {
    scanf("%lld%lld%lld",&N,&K,&Q);
    while(Q--) {
        int depth1=0, depth2=0, ans=0;
        scanf("%lld %lld",&a,&b);
        a--;b--;
        
        for(lli i=0,t=K; i<a; i+=t, t*=K) depth1++;
        for(lli i=0,t=K; i<b; i+=t, t*=K) depth2++;
        
        while(depth1>depth2){
            depth1--;
            a=(a-1)/K;
            ans++;
        }
        while(depth1<depth2){
            depth2--;
            b=(b-1)/K;
            ans++;
        }
        while(a!=b){
            a=(a-1)/K;
            b=(b-1)/K;
            ans += 2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
