
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int map[21][21];
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                map[i][j] = min(map[i][j] , map[i][k]+map[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
