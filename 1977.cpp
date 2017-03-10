
#include <stdio.h>

int main(){
    int N,M,sum=0,min=900000001;
    scanf("%d%d",&N,&M);
    for(int i=1;i*i<=M;i++){
        if(i*i >= N) {
            sum+=i*i;
            if(min > i*i) min = i*i;
        }
    }
    if(sum==0) printf("-1\n");
    else printf("%d\n%d\n",sum,min);
}
