#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M,ans=0,K,sum=0;
        scanf("%d %d %d",&N,&M,&K);
        int h[200000];
        for(int i=0; i<N; i++) scanf("%d",&h[i]);
        
        for(int i=0; i<N; i++) h[i+N]=h[i];
        for(int i=0; i<M; i++) sum+=h[i];
        if(sum < K) ans++;
        for(int i=0; i<N-1; i++){
            sum=sum-h[i]+h[(i+M)%N];
            if(sum < K) ans++;
        }
        if(N==M) {
            if(ans!=0) printf("1\n");
            else printf("%d\n",ans);
            continue;
        }
        printf("%d\n",ans);
    }
}