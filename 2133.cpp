
#include <stdio.h>

int N, sum=0;
int cache[1001]={0,};
int dp(int width){
    if(width <= 1 || width%2==1) return 0;
    if(width == 2) return 3;
    if(cache[width] != 0) return cache[width];
    return cache[width]+=3*dp(width-2);
    
}
int main(){
    scanf("%d",&N);
    printf("%d",dp(N));
    
}
