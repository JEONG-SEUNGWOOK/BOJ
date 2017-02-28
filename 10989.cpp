#include <stdio.h>

#define MAX_SIZE 10000
int N,a,count[MAX_SIZE+1]={0,}, sum[MAX_SIZE+1];

int main(){
    scanf("%d",&N);
    
    for(int i=1; i<=N ; i++){
        scanf("%d", &a);
        count[a]++;
    }
    
    for(int i=1;i<=MAX_SIZE;i++){
        while(count[i]-- > 0){
            printf("%d\n",i);
        }
    }
        
}
