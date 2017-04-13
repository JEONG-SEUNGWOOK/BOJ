

#include <stdio.h>
int N,K;
long long line[1000002];
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%lld",&line[i]);
    
    long long low=0, high=2300000000,mid;
    while(high > low+1){
        mid = low + (high-low)/2;
        int num=0;
        for(int i=0;i<N;i++)
            num+= line[i]/mid;
        
        if(num>=K) low = mid;
        else high = mid;
    }
    printf("%lld\n",low);
}
