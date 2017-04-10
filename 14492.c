
#include <stdio.h>
int A[302][302],B[302][302],N,cnt=0;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&A[i][j]);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&B[i][j]);
    
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(A[k][j]&B[j][i]){
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d\n",cnt);
}
