
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Length{
    int l=0, d=0;
};
int main(){
    int K, N=6, square=0;
    scanf("%d",&K);
    
    Length len[6], hMax, wMax, side1, side2;
    for(int i=0;i<N;i++){
        int a,b;
        scanf("%d%d",&b,&a);
        len[i].l = a;
        len[i].d = b;
        
        
        if(b==3 || b==4) {
            if(hMax.l < a){
                hMax.l = a;
            }
        }
        if(b==1 || b==2) {
            if(wMax.l < a){
                wMax.l = a;
            }
        }
    }
    for(int i=1;i<=N+3;i++){
        if(len[(i-1)%N].d==len[(i+1)%N].d && len[i%N].d==len[(i+2)%N].d){
            side1.l=len[i%N].l;
            side2.l=len[(i+1)%N].l;
            break;
        }
    }
    square = (wMax.l*hMax.l) - (side1.l*side2.l);
    printf("%d",square*K);
}
