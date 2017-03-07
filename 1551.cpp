

#include <stdio.h>
int main(){
    int N,K,A[21];
    scanf("%d%d",&N,&K);
    
    getchar();
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        getchar();
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<N-i-1;j++){
            A[j] = A[j+1] - A[j];
        }
    }
    printf("%d",A[0]);
    for(int i=1;i<N-K;i++)
        printf(",%d",A[i]);
    printf("\n");
}
