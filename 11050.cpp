
#include <stdio.h>

int bin(int N, int K){
    if(N==K || K==0) return 1;
    return bin(N-1,K-1) + bin(N-1,K);
}
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    printf("%d\n",bin(N,K));
}
