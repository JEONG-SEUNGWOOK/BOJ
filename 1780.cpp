
#include <stdio.h>

int N, paper[2200][2200],ans[3]={0,};

void check(int a, int b, int n){
    if(n==1) {
        ++ans[paper[a][b]];
        return;
    }
    int first = paper[a][b];
    bool flag = true;
    for(int i=a;i<a+n;i++){
        for(int j=b;j<b+n;j++){
            if(first != paper[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag) ++ans[first];
    else if(!flag) {
        int next = n/3;
        for(int i=a;i<a+n;i+=next)
            for(int j=b;j<b+n;j+=next)
                check(i,j,next);
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            scanf("%d",&a);
            paper[i][j] = a+1;
        }
    }

    check(0,0,N);
    for(int i=0;i<3;i++)
        printf("%d\n",ans[i]);
}
