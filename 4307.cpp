
#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int bar,N,pos,min=0, max=0;
        scanf("%d %d",&bar,&N);
        while(N--){
            scanf("%d",&pos);
            if(bar-pos>pos){
                if(bar-pos>max) max=(bar-pos);
                if(pos>min) min=pos;
            }
            else{
                if(pos>max)max=pos;
                if(bar-pos>min)min=(bar-pos);
            }
        }
        printf("%d %d\n",min,max);
    }
}
