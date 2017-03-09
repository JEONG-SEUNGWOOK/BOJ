
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, step[301], sum[301]={0,};
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&step[i]);
    
    sum[1]= step[1];
    for(int i=2;i<=N;i++){
        sum[i] = max(step[i-1] + sum[i-3], sum[i-2])+step[i];
    }
    printf("%d\n",sum[N]);
}
