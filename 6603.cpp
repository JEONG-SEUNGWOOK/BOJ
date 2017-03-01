

#include <stdio.h>
#include <math.h>

void print(int num[], int i_num, int N){
    int place[13], cnt=0, exc = N-6;
    bool flag = true;
    for(int i=N-1;i>=0;i--){
        if(i_num%2) cnt++;
        place[i] = i_num%2;
        i_num/=2;
        if(cnt > exc) {
            flag = false;
            break;
        }
    }
    if(flag && N-cnt == 6){
        int _cnt=0;
        for(int i=0; i<N; i++){
            if(!place[i]) {
                if(++_cnt == 6) printf("%d\n",num[i]);
                else printf("%d ",num[i]);
            }
        }
    }
}
int main(){
    while(1){
        int N,num[13];
        scanf("%d",&N);
        if(N==0) break;
        for(int i=0;i<N;i++)
            scanf("%d",&num[i]);
        
        for(int i=0; i<pow(2,N); i++)
            print(num, i, N);
        printf("\n");
    }
}
