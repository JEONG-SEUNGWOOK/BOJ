
#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int N;
int arr[105][105];
void input(){
    int a;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d",&a);
            if(a) arr[i][j] = a;
            else arr[i][j] = INF;
        }
    }
}
void floyd(){
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
}
void output(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j] == INF) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }
        
}
int main(){
    input();
    floyd();
    output();
}

