#include <stdio.h>

int main(){
    int X,n=1,cnt=0,A=1,B=1;
    scanf("%d",&X);
    
    while(1){
        
        if(n%2==0) A=1, B=n;
        else A=n, B=1;
        for(int i=0;i<n;i++){
            if(++cnt == X) {
                printf("%d/%d\n",A,B);
                return 0;
            }
            if(n%2==0) ++A, --B;
            else --A, ++B;
            
        }
        n++;
    }
}
