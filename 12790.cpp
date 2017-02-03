
#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int hp=0,mp=0,a=0,d=0,n[8];
        for(int i=0; i<8;i++)
            scanf("%d",&n[i]);
        hp+=(n[0]+n[4]);
        mp+=(n[1]+n[5]);
        a+=(n[2]+n[6]);
        d+=(n[3]+n[7]);
        if((hp*=1) < 1) hp=1;
        if((mp*=5) < 1) mp=5;
        if((a*=2) < 0) a=0;
        d *= 2;
        
        printf("%d\n",hp+mp+a+d);
    }
}
