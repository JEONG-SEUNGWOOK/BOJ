
#include <stdio.h>
#define INF 987654321
    int N,M,ans=0;
    int arr[505][505];
    int isConnected[505]={0,};
int main(){
    
    scanf("%d%d",&N,&M);
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            arr[i][j] = INF;
        }
    }
    
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        arr[a][b] = 1;
    }
    
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(arr[i][j] > arr[i][k]+arr[k][j])
                    arr[i][j] = arr[i][k]+arr[k][j];
    
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=N;j++){
//            if(arr[i][j]==INF) printf("INF ");
//            else printf("%d   ",arr[i][j]);
//        }
//        printf("\n");
//    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j]!=INF) {
                isConnected[i]++, isConnected[j]++;
                if(isConnected[i]==N-1) ans++;
                if(isConnected[j]==N-1) ans++;
            }
        }
    }
//    for(int i=1;i<=N;i++) printf("%d ",isConnected[i]);

    printf("%d",ans);
}


