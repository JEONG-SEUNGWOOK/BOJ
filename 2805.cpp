
#include <stdio.h>
int main(){
    int N,M,wood[1000003];
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d",&wood[i]);
    int high = 1000000000, low=0;
    while(high>low+1){
        int mid = (high+low)/2;
        long long sum=0;
        
        for(int i=0;i<N;i++)
            if(wood[i]-mid > 0) sum+=wood[i]-mid;
        
        if(sum >= M) low=mid;
        else high = mid;
    }
    printf("%d\n",low);
}
