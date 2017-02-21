
#include <stdio.h>
int main(){
    int N,S,A[21],cnt=0,sum;
    scanf("%d %d",&N,&S);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    for(int i=1; i < (1 << (N)); i++){
        sum=0;
        for (int j=0; j<N; j++){
            if (i & (1 << j)){
                sum+=A[j];
            }
        }
        if(sum == S) cnt++;
    }
    printf("%d\n",cnt);
}
