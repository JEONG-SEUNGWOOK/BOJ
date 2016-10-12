
#include <algorithm>
#include <stdio.h>
using namespace std;

int N ,max_sum=0;;
int num[505][505];
int sum[505][505]={0,};
int main(){
    scanf("%d",&N);
    scanf("%d",&num[0][0]);
    sum[0][0] = num[0][0];
    max_sum = 0;
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            scanf("%d",&num[i][j]);
            if(j==0) {
                sum[i][0]=num[i][0]+sum[i-1][0];
                if(sum[i][0] > max_sum) max_sum = sum[i][0];
            }
            else if(j==i) {
                sum[i][j]=num[i][j]+sum[i-1][j-1];
                if(sum[i][j] > max_sum) max_sum = sum[i][j];
            }
            else {
                sum[i][j] = num[i][j] + max(sum[i-1][j-1], sum[i-1][j]);
                if(sum[i][j] > max_sum) max_sum = sum[i][j];
            }
        }
    }
    
    printf("%d",max_sum);
}
