
#include <stdio.h>
int main(){
    int N,ans=-1;
    scanf("%d",&N);
    bool flag=false;
    for(int i=0; i<=N/3; i++){
        int t=N;
        if((t-(3*i))%5==0) {
            int tt = i+(t-(3*i))/5;
            if(ans == -1) ans = tt;
            else {
                if(ans > tt) ans = tt;
            }
        }
    }
    printf("%d\n",ans);
}
