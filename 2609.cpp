
#include <stdio.h>

int A,B,div;
bool lcm(int a, int b){
    for(int i=2;i<=10000;i++){
        if(A%i ==0 && B%i ==0) {
            A/=i, B/=i;
            div *= i;
            return true;
        }
    }
    return false;
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    scanf("%d%d",&A,&B);
    div = 1;
    int g = gcd(A,B);
    while(1){
        if(!lcm(A, B)) break;
    }
    printf("%d\n%d\n",g,A*B*div);
    
}
