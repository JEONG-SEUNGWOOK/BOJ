#include <stdio.h>

#define MAX_N 10000000
#define MAX_SIZE 10000
int N,A[MAX_SIZE+1],B[MAX_SIZE+1],count[MAX_N+1]={0,}, sum[MAX_N+1];

int main(){
    scanf("%d",&N);
    
    for(int i =1 ; i<= N ; i++){
        scanf("%d", &A[i]);
        count[A[i]]++;
    }
    
    sum[0] = count[0];
    for(int i = 1 ; i<= MAX_N ; i++)
        sum[i] = sum[i-1]+count[i];
    
    for(int i=N;i>=1;i--){
        B[sum[A[i]]] = A[i];
        sum[A[i]]--;
    }
    for(int i=1;i<=N;i++)
        printf("%d\n",B[i]);
}
