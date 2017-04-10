
#include <stdio.h>
#include <math.h>
int N,ans=0,cnt=0;
int main(){
    scanf("%d",&N);
    while(N>0){
        ans+=N%9*pow(10, cnt++);
        N/=9;
    }
    printf("%d\n",ans);
}
