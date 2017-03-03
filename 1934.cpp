
#include <stdio.h>

int A,B,div;
bool lcm(int a, int b){
    for(int i=2;i<=45000;i++){
        if(A%i ==0 && B%i ==0) {
            A/=i, B/=i;
            div *= i;
            return true;
        }
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&A,&B);
        div = 1;
        while(1){
            if(!lcm(A, B)) break;
        }
        printf("%d\n",A*B*div);
    }
}
