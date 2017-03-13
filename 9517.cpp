

#include <stdio.h>

int main(){
    int pos, N, total_time = 210;
    scanf("%d %d",&pos, &N);
    --pos;
    for(int i=0;i<N;i++){
        int time;
        char ans;
        scanf("%d %c",&time,&ans);
        total_time -= time;
        pos%=8;
        if(total_time <= 0) break;
        if(ans == 'T') pos++;
        
    }
    printf("%d\n",pos+1);
}
