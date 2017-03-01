#include <stdio.h>

int main(){
    int N, fibo[46];
    fibo[0] = 0;
    fibo[1] = 1;
    scanf("%d",&N);
    for(int i=2;i<=N;i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    printf("%d\n",fibo[N]);
}
