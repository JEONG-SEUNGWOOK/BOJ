
#include <stdio.h>

int main(){
    int N, cnt=99;
    scanf("%d",&N);
    if(N < 100) {
        printf("%d\n",N);
        return 0;
    }
    for(int i=100;i<=N;i++){
        int a, b, c;
        a = i/100;
        b = (i%100)/10;
        c = i%10;
        if(b-a == c-b) cnt++;
    }
    printf("%d\n",cnt);
}
