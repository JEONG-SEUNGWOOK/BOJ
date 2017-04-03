
#include <stdio.h>
#include <math.h>
int N,R,C,cnt=0;
void dnc(int n,int r,int c){
    if(n==2){
        if(r==R && c==C) {
            printf("%d\n",cnt++);
            return ;
        }
        cnt++;
        
        if(r==R && c+1==C) {
            printf("%d\n",cnt++);
            return ;
        }
        cnt++;
        
        if(r+1==R && c==C) {
            printf("%d\n",cnt++);
            return ;
        }
        cnt++;
        
        if(r+1==R && c+1==C) {
            printf("%d\n",cnt++);
            return ;
        }
        cnt++;
        return;
    }
    dnc(n/2, r, c);
    dnc(n/2, r, c+n/2);
    dnc(n/2, r+n/2, c);
    dnc(n/2, r+n/2, c+n/2);
}
int main(){
    scanf("%d%d%d",&N,&R,&C);
    dnc(pow(2,N), 0, 0);
}
