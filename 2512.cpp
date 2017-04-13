

#include <stdio.h>
int main(){
    int N, D[10002];
    long long M;
    int low=0, high=0, mid;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&D[i]);
        if(D[i]>high) high=D[i];
    }
    scanf("%lld",&M);
    
    while(high>=low){
        mid=(low+high)/2;
        long long sum=0;
        for(int i=0;i<N;i++){
            if(D[i]-mid > 0) sum+=mid;
            else sum+=D[i];
        }
        if(sum > M) high=mid-1;
        else low=mid+1;
    }
    printf("%d\n",high);
}
