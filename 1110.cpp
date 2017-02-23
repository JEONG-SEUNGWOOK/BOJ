#include <stdio.h>
int main(){
    int F,N,NN,cnt=0;
    scanf("%d",&F);
    N=F;
    
    while(1){
        int t = N/10, o = N%10;
        int s = t+o;
        NN = o*10 + s%10;
        cnt++;
        N = NN;
        if(F == NN) {
            printf("%d\n",cnt);
            return 0;
        }
       
    }
}
