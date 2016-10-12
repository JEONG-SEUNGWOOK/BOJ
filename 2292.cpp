
#include <stdio.h>

int main(){
    long N,room=1;
    scanf("%ld",&N);
    for(long i=1, t=6; i<N; i+=t,t+=6,room++);
    
    printf("%ld",room);
}
