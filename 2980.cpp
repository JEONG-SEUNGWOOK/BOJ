
#include <stdio.h>

int main(){
    int N,L,pos=0,pre_light_pos=0, light;
    scanf("%d %d",&N,&L);
    int lpos, lg, lr;
    
    while(N--){
        scanf("%d %d %d",&lpos, &lr, &lg);
        pos += lpos - pre_light_pos;
        pre_light_pos = lpos;
        light = pos %(lr+lg);
        if(light < lr) pos += lr - light;
    }
    pos += L-pre_light_pos;
    
    printf("%d",pos);
}
