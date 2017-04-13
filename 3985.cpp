
#include <cstdio>
using namespace std;

int cake[1002], L,N,p,k;
int ans1=0,ans2, ans3=0,ans4;
int main(){
    scanf("%d%d",&L,&N);
    for(int i=1;i<=N;i++){
        int cnt=0;
        scanf("%d%d",&p,&k);
        if(k-p+1 > ans1) ans1=k-p+1, ans2=i;
        for(int j=p;j<=k;j++)
            if(cake[j] == 0) cake[j]=i, cnt++;
        if(cnt > ans3) ans3=cnt, ans4=i;
    }
    printf("%d\n%d\n",ans2,ans4);
}
