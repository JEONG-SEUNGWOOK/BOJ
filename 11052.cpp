
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, fish[1001], sum[1001]={0,}, ans=0;
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&fish[i]);
    sum[0] = 0;
    sum[1] = fish[1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            sum[i] = max(sum[i], sum[i-j]+fish[j]);
        }
    }
    
    printf("%d\n",sum[N]);
}
