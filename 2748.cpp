#include <stdio.h>

int main(){
    int N;
    long fibo[91];
    fibo[0] = 0;
    fibo[1] = 1;
    scanf("%d",&N);
    for(int i=2;i<=N;i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    printf("%ld\n",fibo[N]);
}
