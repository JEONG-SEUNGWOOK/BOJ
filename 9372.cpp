#include <stdio.h>

int T,N,M,a,b;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        while(M--) scanf("%d %d",&a,&b);
        printf("%d\n",N-1);
    }
}
