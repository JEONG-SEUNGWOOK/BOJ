
#include <stdio.h>

int main(){
    int N, worth;
    int min=0;
    int coin[11];
    scanf("%d %d",&N, &worth);
    
    for(int i=N-1; i>=0; --i)
        scanf("%d",&coin[i]);
    
    
    for(int i=0; i<N; i++){
        if(worth - coin[i] >= 0){
            min++;
            worth -= coin[i];
            i--;
        }
    }
    
    printf("%d",min);
    return 0;
}
