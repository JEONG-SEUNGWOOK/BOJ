
#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N, n[12];
        n[0]=0, n[1]=1, n[2]=2, n[3]=4;
        for(int i=4;i<=11;i++)
            n[i] = n[i-1]+n[i-2]+n[i-3];
        scanf("%d",&N);
        printf("%d\n",n[N]);
    }
}
