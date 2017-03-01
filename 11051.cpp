
#include <stdio.h>

int main(){
    int B[1001][1001],N,K;
    B[1][0] = 1;
    B[1][1] = 1;
    scanf("%d%d",&N,&K);
    
    for(int i=2; i<=N; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) B[i][j] = 1;
            else B[i][j] = (B[i-1][j-1] + B[i-1][j]) % 10007;
        }
    }
    printf("%d\n",B[N][K]);
}
