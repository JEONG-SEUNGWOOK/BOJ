
#include <stdio.h>
#include <algorithm>

using namespace std;

int T, N;


int main(){
    scanf("%d",&T);
    for(int test=1; test<=T; test++){
        scanf("%d",&N);
        
        int sticker[2][100002]={0,};
        int sum[2][100002] ={0,};
        for(int i=0;i<2;i++)
            for(int j=0;j<N;j++) scanf("%d",&sticker[i][j]);
        
        sum[0][0]=sticker[0][0];
        sum[1][0]=sticker[1][0];
        int max1 = sum[1][0];
        int max2 = sum[0][0];
        
        for(int j=1;j<N;j++){
            
            sum[0][j]=sticker[0][j]+max1;
            
            sum[1][j]=sticker[1][j]+max2;
            
            max1 = max(max1 , sum[1][j]);
            max2 = max(max2 , sum[0][j]);
            
        }
        
        printf("%d\n",max(sum[0][N-1], sum[1][N-1]));
    }
}

