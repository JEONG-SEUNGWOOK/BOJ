

#include <stdio.h>

int main(){
    int T, P, M, F, C;
    int coupon=0, chicken=0, chic_coup=0;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        scanf("%d %d %d %d",&P, &M, &F, &C);
        
        coupon = (M/P)*C;
        coupon/=F;
        while(coupon > 0){
            
            coupon/=F;
            if(coupon > 0) {
                chicken++;
                chic_coup += C;
            }
            
        }
        printf("%d",chicken);
    }
}
