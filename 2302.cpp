
#include <cstdio>
using namespace std;

long cases[41]={0,};
long ans=1;
void fibo(){
    cases[0]=1;
    cases[1]=1;
    for(int i=2;i<=40;i++)
        cases[i]=cases[i-2]+cases[i-1];
    
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    fibo();
    int a=0, b;
    for(int i=0;i<M;i++){
        scanf("%d",&b);
        ans *= cases[b-a-1];
        a=b;
    }
    ans*=cases[N-a];
    printf("%ld",ans);
}
